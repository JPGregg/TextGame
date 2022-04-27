/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The header file for the Item class. Contains information on rooms that provide items to the player.
 *********************************************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include "Space.hpp"

class Item : public Space {
private:
public:
    Item();
    virtual void setSecondaryText();
};
#endif