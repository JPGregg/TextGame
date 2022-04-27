/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The .cpp file for the Space class. Parent class for all specific room types.
 *********************************************************************************************************************/

#include "Space.hpp"


/**************************************************************************************************
 *                                         Constructor()
 * Creates all the directional pointers and initially sets them to 0.
 *************************************************************************************************/
Space::Space() {
    North = nullptr;
    East = nullptr;
    South = nullptr;
    West = nullptr;
}


/**************************************************************************************************
 *                                         getNorth()
 * Returns the directional pointer that points North.
 *************************************************************************************************/
Space* Space::getNorth() {
    return North;
}


/**************************************************************************************************
 *                                         getSouth()
 * Returns the directional pointer that points South.
 *************************************************************************************************/
Space* Space::getSouth() {
    return South;
}


/**************************************************************************************************
 *                                         getEast()
 * Returns the directional pointer that points East.
 *************************************************************************************************/
Space* Space::getEast() {
    return East;
}


/**************************************************************************************************
 *                                         getWest()
 * Returns the directional pointer that points West.
 *************************************************************************************************/
Space* Space::getWest() {
    return West;
}


/**************************************************************************************************
 *                                         setNorth()
 * Sets the directional pointer that points North to the Space parameter.
 *************************************************************************************************/
void Space::setNorth(Space& newNorth) {
North = &newNorth;
}


/**************************************************************************************************
 *                                         setSouth()
 * Sets the directional pointer that points South to the Space parameter.
 *************************************************************************************************/
void Space::setSouth(Space& newSouth) {
    South = &newSouth;
}


/**************************************************************************************************
 *                                         setEast()
 * Sets the directional pointer that points East to the Space parameter.
 *************************************************************************************************/
void Space::setEast(Space& newEast) {
    East = &newEast;
}


/**************************************************************************************************
 *                                         setWest()
 * Sets the directional pointer that points West to the Space parameter.
 *************************************************************************************************/
void Space::setWest(Space& newWest) {
    West = &newWest;
}


/**************************************************************************************************
 *                                         getRoomDescription()
 * Prints out the general room description dependent on the class.
 *************************************************************************************************/
void Space::getRoomDescription() {
    std::cout << roomDescription << std::endl << std::endl;
}


/**************************************************************************************************
 *                                         getRoomExits()
 * Prints out the options for the player to move.
 *************************************************************************************************/
void Space::getRoomExits() {
    if (getNorth() != nullptr) {
        std::cout << "There is a path to the North." << std::endl;
    }
    if (getEast() != nullptr) {
        std::cout << "There is a path to the East." << std::endl;
    }
    if (getSouth() != nullptr) {
        std::cout << "There is a path to the South." << std::endl;
    }
    if (getWest() != nullptr) {
        std::cout << "There is a path to the West." << std::endl;
    }
}


/**************************************************************************************************
 *                               getSecondaryFlagCondition()
 * Returns the state of the secondary text flag. Usually used when returning to a room.
 *************************************************************************************************/
bool Space::getSecondaryFlagCondition() {
    return secondaryTextFlag;
}


/**************************************************************************************************
 *                                         getItemName()
 * Returns the item string present in the current room.
 *************************************************************************************************/
std::string Space::getItemName() {
    return item;
}


/**************************************************************************************************
 *                                         setItemName()
 * Sets the item name in the item-room from the parameter.
 *************************************************************************************************/
void Space::setItemName(std::string itemParam) {
    item = itemParam;
}


/**************************************************************************************************
 *                                         getItemFlag()
 * Returns the state of the item in an item-room. Basically dictates if an item has been taken or not.
 *************************************************************************************************/
bool Space::getItemFlag() {
    return itemFlag;
}


/**************************************************************************************************
 *                                         setItemFlag()
 * Changes the item state from false to true so it is flagged as "picked-up".
 *************************************************************************************************/
void Space::setItemFlag() {
    itemFlag = true;
}