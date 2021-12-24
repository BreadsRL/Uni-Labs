#include <iostream>
#include "team.h"
#include "date.h"
#include "player.h"
#include "dist.h"
#include "duration.h"


using namespace std;

int main(){

    Team dreamTeam;

    dreamTeam.add(Player("Michael Jordan", 6, 6, 1963, 2, 17));
    dreamTeam.add(Player("Charles Barkley", 6, 6, 1963, 2, 20));
    dreamTeam.add(Player("Nikola Jokic", 6, 11, 1995, 2, 19));
    dreamTeam.add(Player("Stephen Curry", 6, 2, 1988, 3, 14));
    


    cout << dreamTeam << endl;

    cout << "Adding Magic Johnson to team:" << endl;
    dreamTeam.add(Player("Magic Johnson", 6, 9, 1959, 8, 14));

    cout << dreamTeam << endl;

    cout << "Adding LeBron James to team:" << endl;
    dreamTeam.add(Player("LeBron James", 6, 9, 1984, 12, 30));

    cout << dreamTeam << endl;

    cout << "Picking a random player: " << endl;
    dreamTeam.getRandom();
    cout << endl;


    cout << "The average height of players: ";
    cout << dreamTeam.averageHeight() << endl;
    cout << endl;

    cout << "Removing Magic Johnson from team:" << endl;
    dreamTeam.remove(Player("Magic Johnson", 6, 9, 1959, 8, 14)) ;
    cout << dreamTeam << endl;


    Date d = Date(2001, 6, 28);
    Date d1 = Date(2010, 4, 15);

    Date today = Date(2021, 11, 28);

    cout << "Date differences: " << d-d1 << " == " << d1-d << endl;

    cout << "The average age of players: ";
    cout << dreamTeam.averageAge(today) << endl;

    return 0;
}


