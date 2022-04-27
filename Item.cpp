/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/03/2019
 * Description: The .cpp file for the Item class. Contains information on rooms that provide items to the player.
 *********************************************************************************************************************/

#include "Item.hpp"


/**************************************************************************************************
 *                                         Constructor()
 * Sets the roomDescription as that of an unplundered room.
 *************************************************************************************************/
Item::Item() {
    roomDescription = "You see a chest in the corner of the room. Other than that, the room is empty.";
}


/**************************************************************************************************
 *                                         setSecondaryText()
 * Sets roomDescription as that of a plundered room. Acts to flag the room as visited.
 *************************************************************************************************/
void Item::setSecondaryText() {
    secondaryText = "There is an empty chest in the room. Other than that, the room is empty.";
    roomDescription = secondaryText;
    secondaryTextFlag = true;
}