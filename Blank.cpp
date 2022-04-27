/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/04/2019
 * Description: The .cpp file for the Blank class. Contains information on a room with nothing of note.
 *********************************************************************************************************************/

#include "Blank.hpp"


/**************************************************************************************************
 *                                         Constructor()
 * Sets the room description as that of an empty room.
 *************************************************************************************************/
Blank::Blank() {
    roomDescription = "There's nothing in this room. It is empty.";
}


/**************************************************************************************************
 *                                         setSecondaryText()
 * Nothing changes with this text, but this function is required or it will be an abstract class, so the form is
 *     kept the same as that of the other class functions.
 *************************************************************************************************/
void Blank::setSecondaryText() {
    secondaryText = "There's nothing in this room. It is empty.";
    secondaryTextFlag = true;
}