/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/04/2019
 * Description: Header file for the Menu class. Acts to run the majority of the underground cave game.
 *********************************************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Monster.hpp"
#include "Obstacle.hpp"
#include "Item.hpp"
#include "Blank.hpp"
#include "Player.hpp"


class Menu {
private:
public:
    void start();
    void linkTopToBottom(Space& frontSpace, Space& bottomSpace);
    void linkLeftToRight(Space& leftSpace, Space& rightSpace);
    void doorCheck(Player&, Obstacle&, Obstacle&, Obstacle&);
    int battleStart(Player*, Monster*);
    int inputCheck(int minVal, int maxVal);
};
#endif
