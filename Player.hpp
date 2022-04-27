/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/05/2019
 * Description: The header file for the Player class. Contains all of the information necessary for keeping track
 *     of the player's position, life, etc.
 *********************************************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include <queue>

class Player {
private:
    Space* playerLocation;
    std::queue<std::string> queue;
    bool northOption, eastOption, southOption, westOption, shieldFlag;
    int HP, armor, dieCountAttack, dieSidesAttack,
        dieCountDefend, dieSidesDefend;

public:
    Player();
    void getCurrentRoomDescription();
    void setStartingLocation(Space&);
    void setPlayerLocation(Space*);
    void updateRoutes();
    bool getNorthOption();
    bool getEastOption();
    bool getSouthOption();
    bool getWestOption();
    Space* getPlayerLocationNorth();
    Space* getPlayerLocationEast();
    Space* getPlayerLocationSouth();
    Space* getPlayerLocationWest();
    Space* getPlayerLocation();
    void incrementPlayerLife();
    int getPlayerLife();
    bool check(std::queue<std::string>, std::string);
    bool check(std::queue<std::string>, std::string, std::string);
    void viewInventory();
    std::queue<std::string> getStack();
    int inputCheck(int, int);
    void addItem();
    int attack();
    bool defend(int);
    void setHP(int);
};
#endif
