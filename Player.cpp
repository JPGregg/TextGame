/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/05/2019
 * Description: The .cpp file for the Player class. Contains all of the information necessary for keeping track
 *     of the player's position, life, etc.
 *********************************************************************************************************************/

#include "Player.hpp"


/**************************************************************************************************
 *                                         Constructor()
 * Sets the dice, health, and basic armor for the player. Doesn't account for the sword and shield.
 *************************************************************************************************/
Player::Player() {
    HP = 75;
    armor = 0;
    dieCountAttack = 2;
    dieSidesAttack = 6;
    dieCountDefend = 2;
    dieSidesDefend = 6;
    shieldFlag = false;
}


/**************************************************************************************************
 *                                  getCurrentRoomDescription()
 * Prints out the room information from the space class.
 *************************************************************************************************/
void Player::getCurrentRoomDescription() {
    playerLocation->getRoomDescription();
}


/**************************************************************************************************
 *                                         setStartingLocation()
 * Puts the player in the designated starting location.
 *************************************************************************************************/
void Player::setStartingLocation(Space& startingSpace) {
    playerLocation = &startingSpace;
}


/**************************************************************************************************
 *                                         setPlayerLocation()
 * Moves the player to the next location, doesn't do error checking.
 *************************************************************************************************/
void Player::setPlayerLocation(Space* nextSpace) {
    playerLocation = nextSpace;
}


/**************************************************************************************************
 *                                         updateRoutes()
 * Updates the options for the player to move. Looks at linked spaces for legality.
 *************************************************************************************************/
void Player::updateRoutes() {
    if (playerLocation->getNorth() != nullptr) {
        northOption = true;
    }
    else northOption = false;
    if (playerLocation->getEast() != nullptr) {
        eastOption = true;
    }
    else eastOption = false;
    if (playerLocation->getSouth() != nullptr) {
        southOption = true;
    }
    else southOption = false;
    if (playerLocation->getWest() != nullptr) {
        westOption = true;
    }
    else westOption = false;
}


/**************************************************************************************************
 *                                         getNorthOption()
 * Returns the legality of moving the player 1 space North.
 *************************************************************************************************/
bool Player::getNorthOption() {
    return northOption;
}


/**************************************************************************************************
 *                                         getEastOption()
 * Returns the legality of moving the player 1 space East
 *************************************************************************************************/
bool Player::getEastOption() {
    return eastOption;
}


/**************************************************************************************************
 *                                         getSouthOption()
 * Returns the legality of moving the player 1 space South.
 *************************************************************************************************/
bool Player::getSouthOption() {
    return southOption;
}


/**************************************************************************************************
 *                                         getWestOption()
 * Returns the legality of moving the player 1 space West.
 *************************************************************************************************/
bool Player::getWestOption() {
    return westOption;
}


/**************************************************************************************************
 *                                   getPlayerLocationNorth()
 * Returns the pointer information for the space 1 North of the player's current position.
 *************************************************************************************************/
Space* Player::getPlayerLocationNorth() {
    return playerLocation->getNorth();
}


/**************************************************************************************************
 *                                   getPlayerLocationEast()
 * Returns the pointer information for the space 1 East of the player's current position.
 *************************************************************************************************/
Space* Player::getPlayerLocationEast() {
    return playerLocation->getEast();
}


/**************************************************************************************************
 *                                  getPlayerLocationSouth()
 * Returns the pointer information for the space 1 South of the player's current position.
 *************************************************************************************************/
Space* Player::getPlayerLocationSouth() {
    return playerLocation->getSouth();
}


/**************************************************************************************************
 *                                    getPlayerLocationWest()
 * Returns the pointer information for the space 1 West of the player's current position.
 *************************************************************************************************/
Space* Player::getPlayerLocationWest() {
    return playerLocation->getWest();
}


/**************************************************************************************************
 *                                         getPlayerLocation()
 * Returns the Space pointer for the player's current location.
 *************************************************************************************************/
Space* Player::getPlayerLocation() {
    return playerLocation;
}


/**************************************************************************************************
 *                                         incrementPlayerLife()
 * The "poison" tracker. Reduces player's life by 1 every time they change rooms.
 *************************************************************************************************/
void Player::incrementPlayerLife() {
    HP -= 1;
}


/**************************************************************************************************
 *                                         getPlayerLife()
 * Returns the value of the player's current health.
 *************************************************************************************************/
int Player::getPlayerLife() {
    return HP;
}


/**************************************************************************************************
 *                                         check(queue, string)
 * Creates a temp string queue, and runs through the queue checking for a specific string. Returns true if the
 *     single string is found.
 *************************************************************************************************/
bool Player::check(std::queue<std::string> queueParam, std::string stringParam1) {
    std::queue<std::string> tempStack = queueParam;
    while (!tempStack.empty()) {
        if (tempStack.front() == stringParam1) {
            return true;
        }
        else
            tempStack.pop();
    }
    return false;
}


/**************************************************************************************************
 *                                  check(queue, string, string)
 * Creates a temp string queue, and runs through the queue checking for two specific strings. Returns true if
 *     both strings are found.
 *************************************************************************************************/
bool Player::check(std::queue<std::string> queueParam, std::string stringParam1, std::string stringParam2) {
    std::queue<std::string> tempStack = queueParam;
    bool checkFlag1 = false;
    bool checkFlag2 = false;
    while (!tempStack.empty()) {
        if (tempStack.front() == stringParam1) {
            checkFlag1 = true;
        }
        else if (tempStack.front() == stringParam2) {
            checkFlag2 = true;
        }
            tempStack.pop();
    }
    if (checkFlag1 && checkFlag2) {
        return true;
    }
    else return false;
}


/**************************************************************************************************
 *                                         getStack()
 * Returns the queue that contains the player items.
 *************************************************************************************************/
std::queue<std::string> Player::getStack() {
    return queue;
}


/**************************************************************************************************
 *                                       viewInventory()
 * Prints out the queue containing all the player items.
 *************************************************************************************************/
void Player::viewInventory() {
    int inventoryCheck;
    std::cout << "Would you like to see your current inventory?" << std::endl << "1: Yes" << std::endl << "2: No"
              << std::endl;
    inventoryCheck = inputCheck(1, 2);
    if (inventoryCheck == 1) {
        std::queue<std::string> tempStack = queue;
        std::cout << "This is your current inventory:";
        while (!tempStack.empty()) {
            std::cout << std::endl << tempStack.front();
            tempStack.pop();
        }
    }
    std::cout << std::endl << std::endl;
}


/**************************************************************************************************
 *                                         addItem()
 * Adds a new item to the player item queue. Includes an item limit as well.
 *************************************************************************************************/
void Player::addItem() {
    if (queue.size() < 5) {
        queue.push(playerLocation->getItemName());
    }
    else {
        std::cout << "You can't carry any more items, you have no choice but to drop the sword." << std::endl
                  << "Unfortunately, this will make future fights more difficult." << std::endl;
        queue.pop();
        queue.push(playerLocation->getItemName());
    }
}

/**************************************************************************************************
 *                                         setHP()
 * Sets the player HP to a specific value. Only used to ensure HP is at 0 for game over.
 *************************************************************************************************/
void Player::setHP(int hpParam) {
    HP = hpParam;
}


/**************************************************************************************************
 *                                         inputCheck()
 * Takes in a user value and checks to see if it is a legal integer. This means it is both an actual
 *     integer and an integer within the correct range.
 *************************************************************************************************/
//    http://www.cplusplus.com/reference/cstdlib/atoi/
//    http://www.cplusplus.com/forum/general/13135/
//    The above links were necessary in order to convert ints longer than a single digit.
int Player::inputCheck(int minVal, int maxVal) {
    int returnVal = 0;
    std::string checkString;
    char tempChar;
    bool intFlag;
    bool stringFlag;

    do {
        std::cin >> checkString;
        for (int counter = 0; counter < checkString.size(); counter++) {
            tempChar = checkString[counter];
            if (static_cast<int>(tempChar) >= 48 && static_cast<int>(tempChar) <= 57) { //checks for ASCII int.
                stringFlag = true;
            } else {
                if (counter == 0 && static_cast<int>(tempChar) == 45) { //if the sign is (-), then it's still ok.
                    stringFlag = true;
                }
                else {
                    stringFlag = false;
                    std::cout << "Invalid input. Please enter a value between " << minVal << " and " << maxVal
                              << std::endl;
                    break;
                }
            }
        }
        if (stringFlag) {
            returnVal = atoi(checkString.c_str());  //string to int type conversion. check references above.
            if (returnVal >= minVal && returnVal <= maxVal) {
                intFlag = true;
            } else {
                intFlag = false;
                std::cout << "Invalid input. Please enter a value between " << minVal << " and " << maxVal << std::endl;
            }
        }
    } while (!stringFlag || !intFlag);

    std::cout << std::endl;
    return returnVal;
}


/**************************************************************************************************
 *                                         attack()
 * The base attack function which rolls the dice and returns the result. No special ability usage here.
 *************************************************************************************************/
int Player::attack() {
    int counter = dieCountAttack;
    int totalAttackVal = 0;
    while (counter != 0) {
        totalAttackVal += std::rand() % dieSidesAttack + 1;
        counter--;
    }
    std::queue<std::string> tempStack = queue;
    while (!tempStack.empty()) {
        if (tempStack.front() == "sword") {
            totalAttackVal += 3;
        }
        std::cout << "You attack with a dice roll of " << totalAttackVal << "." << std::endl;
        return totalAttackVal;
    }
}


/**************************************************************************************************
 *                                         defend()
 * The base defend function. Rolls the dice and compares the result to the attack parameter that is
 *     passed into the function. Determine the amount of damage that the defending character takes.
 *     No special ability usage here.
 *************************************************************************************************/
bool Player::defend(int attackParam) {
    std::queue<std::string> tempStack = queue;
    while (!tempStack.empty()) {
        if (tempStack.front() == "shield") {
            if (shieldFlag == false) {
                armor += 5;
                shieldFlag = true;
            }
        }
        tempStack.pop();
    }
    int damageVal = 0;
    int counter = dieCountDefend;
    int totalDefendVal = 0;
    while (counter != 0) {
        totalDefendVal += std::rand() % dieSidesDefend + 1;
        counter--;
    }
    std::cout << "You tried to defend with " << armor << " armor, and " << HP
              << " HP." << std::endl;
    damageVal = attackParam - totalDefendVal - armor;
    if (damageVal < 0) {
        damageVal = 0;
    }
    HP -= damageVal;
    if (HP < 0) {
        HP = 0;
    }
    std::cout << "The defense dice roll was " << totalDefendVal << std::endl
              << "The total inflicted damage was " << damageVal << std::endl
              << "You now have " << HP << " HP." << std::endl;

    if (HP < 1) {
        return false;
    }
    else
        return true;
}