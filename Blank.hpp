/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/04/2019
 * Description: The header file for the Blank class. Contains information on a room with nothing of note.
 *********************************************************************************************************************/

#ifndef BLANK_HPP
#define BLANK_HPP

#include "Space.hpp"

class Blank : public Space{
private:
public:
    Blank();
    virtual void setSecondaryText();
};
#endif