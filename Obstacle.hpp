/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The header file for the Obstacle class. Acts to bar progress, e.g. a locked door.
 *********************************************************************************************************************/

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Space.hpp"

class Obstacle : public Space {
private:
public:
    Obstacle();
    Obstacle(int);
    virtual void setSecondaryText();
};
#endif
