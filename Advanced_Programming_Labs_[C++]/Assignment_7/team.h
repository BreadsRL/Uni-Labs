#ifndef TEAM_H
#define TEAM_H

#include <ostream>
#include "player.h"

struct Team{
    Player* players;
    int count;
    int capacity;

    Team(){
        count = 0;
        capacity = 1;
        players = new Player[capacity];
    }

    Team(const Team& other){
        count = other.count;
        players = new Player[count];
        for (int i = 0; i < count; i++){
            players[i] = other.players[i];
        }
    }

    Dist averageHeight() const {
        Dist total;
        for(int i = 0; i < count; i++){
            total = total + players[i].height;
        }
        
        return total / count;
    }

    Duration averageAge(Date today) const {
        Duration total_age;
        for(int i = 0; i < count; i++){
            total_age = total_age + (today - players[i].birthday);
        }

        //return Duration(totalage.years/count, totalage.days/count);
        return total_age / count;
    }

    void add(Player p){
        players[count] = p;
        count++;

        if (count == capacity){
            // We have run out of space, so we double our storage

            int prev_Capacity = capacity;
            capacity *= 2;

            Player* temp = new Player[capacity]; // This is twice as big as the original

            // Copy all contents of the players array into temp
            for(int i = 0; i < prev_Capacity; i++){
                temp[i] = players[i];
            }

            // Move players pointer to the new storage, delete the old storage
            Player* prev_Storage = players;
            players = temp;

            // Release the old storage space
            delete[] prev_Storage;

        }
    }

    void remove(Player p){
        Player* prev = new Player[capacity];

        int k;
        int l = 0;

        for (int i = 0; i < capacity; i++) {
            if (players[i] == p) {
                l = 1;
            }

            k = i - l;

            if (!(players[i] == p)){
                prev[k] = players[i];
            }
        }

        Player* oldStorage = players;
        players = prev;
        delete[] oldStorage;

        count--;

        if (count/2 == capacity) {
            capacity /= 2;

            Player* prev = new Player[capacity];

            for(int i = 0; i < count/2; i++){
                prev[i] = players[i];
            }

            Player* oldStorage = players;
            players = prev;

            delete[] oldStorage;
        }
    }

    void getRandom(){
        srand (time(NULL));
        std::cout << players[rand() % count] << std::endl;
    }


};

std::ostream& operator<<(std::ostream& os, const Team& t){
    for (int i = 0; i < t.count; i++){
        os << t.players[i] << std::endl;
    }

    return os;
}



#endif
