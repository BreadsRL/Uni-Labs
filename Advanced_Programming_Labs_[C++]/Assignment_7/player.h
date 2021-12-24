#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ostream>
#include "dist.h"
#include "duration.h"
#include "date.h"

struct Player{
    std::string name;
    Date birthday;
    Dist height;

    Player(){
        this->name = "";
        this->birthday = Date();
        this->height = Dist();
    }

    Player(std::string name, int feet, int inches, int year, int month, int day){
        this->name = name;
        this->birthday = Date(year, month, day);
        this->height = Dist(feet, inches);
    }

    Player(const Player& other){
        this->name = other.name;
        this->height = other.height;
        this->birthday = other.birthday;
    }

    bool operator==(Player p){
        return (p.birthday == birthday && p.name == name && p.height == height);
    }

    ~Player(){

    }
};


std::ostream& operator<<(std::ostream& os, const Player& p){
    os << p.name << " | " << p.height << " | " << p.birthday;
    return os;
}

#endif
