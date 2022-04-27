/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The header file for the Space class. Parent class for all specific room types.
 *********************************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <iostream>

class Space {
protected:
    Space *North, *East, *West, *South;
    std::string roomDescription, secondaryText, item = "0";
    bool secondaryTextFlag = false;
    bool itemFlag = false;

public:
    Space();
    Space* getNorth();
    Space* getSouth();
    Space* getEast();
    Space* getWest();

    virtual void setNorth(Space&);
    virtual void setSouth(Space&);
    virtual void setEast(Space&);
    virtual void setWest(Space&);
    virtual void getRoomDescription();
    virtual void getRoomExits();
    virtual void setSecondaryText() = 0;
    virtual bool getSecondaryFlagCondition();
    virtual std::string getItemName();
    virtual void setItemName(std::string);
    virtual bool getItemFlag();
    virtual void setItemFlag(); //sets to true
};
#endif
