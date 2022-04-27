/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The header file for the Monster class. Attacks the player when they enter the Monster spaces.
 *********************************************************************************************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Space.hpp"

class Monster : public Space {
private:
    int HP;
    int armor;
    int dieCountAttack;
    int dieSidesAttack;
    int dieCountDefend;
    int dieSidesDefend;
    std::string type;

public:
    Monster(int);
    int attack();
    bool defend(int);
    virtual void setSecondaryText();
    int checkLifeStatus();
};
#endif
