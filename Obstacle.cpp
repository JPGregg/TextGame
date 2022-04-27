/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The .cpp file for the Obstacle class. Acts to bar progress, e.g. a locked door.
 *********************************************************************************************************************/

#include "Obstacle.hpp"


/**************************************************************************************************
 *                                         Constructor()
 * General constructor for setting the roomDescription for that of a locked door.
 *************************************************************************************************/
Obstacle::Obstacle() {
    roomDescription = "There is a locked door blocking your path forward.";
}



/**************************************************************************************************
 *                                         Constructor(int)
 * Constructor for each specific type of obstacle. Text used when obstacle key is not obtained.
 *************************************************************************************************/
Obstacle::Obstacle(int typeParam) {
    if (typeParam == 1) {
        roomDescription = "There is a locked door blocking your path forward.";
    }
    if (typeParam == 2) {
        roomDescription =  "There is a locked door blocking your path forward.";;
    }
    if (typeParam == 3) {
        roomDescription = "There is a pitch black room blocking your path forward.";
    }
}


/**************************************************************************************************
 *                                         setSecondaryText()
 * Overwrites original room text with secondary text. Used to flag the state of the room as well.
 *************************************************************************************************/
void Obstacle::setSecondaryText() {
    secondaryText = "There are no more obstacles barring your path in this room.";
    roomDescription = secondaryText;
    secondaryTextFlag = true;
}