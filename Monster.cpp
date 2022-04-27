/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The .cpp file for the Monster class. Attacks the player when they enter the Monster spaces.
 *********************************************************************************************************************/

#include "Monster.hpp"

/**************************************************************************************************
 *                                         Constructor()
 * Sets up the attack, defense, HP, and armor of the monster.
 *************************************************************************************************/
Monster::Monster(int armorVal) {
    roomDescription = "There is a monster in this room! It charges at you!";
    HP = 10;
    armor = armorVal;
    dieCountAttack = 2;
    dieSidesAttack = 6;
    dieCountDefend = 2;
    dieSidesDefend = 6;
}


/**************************************************************************************************
 *                                         attack()
 * The base attack function which rolls the dice and returns the result. No special ability usage here.
 *************************************************************************************************/
int Monster::attack() {
    int counter = dieCountAttack;
    int totalAttackVal = 0;
    while (counter != 0) {
        totalAttackVal += std::rand() % dieSidesAttack + 1;
        counter--;
    }
    std::cout << "The monster attacked with a dice roll of " << totalAttackVal << "." << std::endl;
    return totalAttackVal;
}


/**************************************************************************************************
 *                                         defend()
 * The base defend function. Rolls the dice and compares the result to the attack parameter that is
 *     passed into the function. Determine the amount of damage that the defending character takes.
 *     No special ability usage here.
 *************************************************************************************************/
  bool Monster::defend(int attackParam) {
    int damageVal = 0;
    int counter = dieCountDefend;
    int totalDefendVal = 0;
    while (counter != 0) {
        totalDefendVal += std::rand() % dieSidesDefend + 1;
        counter--;
    }
    std::cout << "The defending monster tried to defend with " << armor << " armor, and " << HP
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
              << "The defending monster now has " << HP << " HP." << std::endl;

    if (HP < 1) {
        return false;
    }
    else
        return true;

}


/**************************************************************************************************
 *                                         setSecondaryText()
 * Changes the room description to that of a room with a dead monster.
 *************************************************************************************************/
void Monster::setSecondaryText() {
    secondaryText = "There is the corpse of a monster in this room. Other than that, it is empty.";
    roomDescription = secondaryText;
    secondaryTextFlag = true;
}


/**************************************************************************************************
 *                                         checkLifeStatus()
 * Used to flag the state of the room as "live-monster" or "dead-monster".
 *************************************************************************************************/
int Monster::checkLifeStatus() {
    if (roomDescription == "There is the corpse of a monster in this room. Other than that, it is empty.") {
        return 0;
    }
    else return 1;
}