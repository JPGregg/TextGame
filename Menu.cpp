/**********************************************************************************************************************
 * Name: Jonathan Gregg
 * Date: 12/04/2019
 * Description: The .cpp file for the Menu class. Acts to run the majority of the underground cave game.
 *********************************************************************************************************************/

#include "Menu.hpp"


/**************************************************************************************************
 *                                         start()
 * Runs the majority of the underground cave game. Calls other functions as necessary, but this is where the
 *     majority of the game takes place.
 *************************************************************************************************/
void Menu::start() {
    Monster minion1(0), minion2(1), minion3(1), finalBoss(1);
    Obstacle lockedDoor1(1), lockedDoor2(2), chasmRoom(3);
    Item key1, key2, sword, shield, torch, flintSteel;
    Blank startingSpace, blank1, blank2, blank3, blank4, blank5, blank6, blank7, blank8, exit;
    Player player1;

    Player* player1Ptr = &player1;
    Monster* minion1Ptr = &minion1;
    Monster* minion2Ptr = &minion2;
    Monster* minion3Ptr = &minion3;
    Monster* minionFinalPtr = &finalBoss;

    int directionMove, battleVictor = 0;
    bool movementFlag;

    // This links the spaces from front to bottom. This means the North to South positions are all linked here.
    linkTopToBottom(startingSpace, sword), linkTopToBottom(sword, blank1), linkTopToBottom(blank1, minion1),
            linkTopToBottom(minion1, blank4), linkTopToBottom(blank4, blank5), linkTopToBottom(blank5, blank6),
            linkTopToBottom(blank6, shield), linkTopToBottom(flintSteel, lockedDoor2), linkTopToBottom(lockedDoor2,blank7),
            linkTopToBottom(blank7, chasmRoom), linkTopToBottom(chasmRoom, blank8), linkTopToBottom(blank8, finalBoss),
            linkTopToBottom(finalBoss, exit), linkTopToBottom(key2, blank3), linkTopToBottom(blank3, minion2),
            linkTopToBottom(minion2, lockedDoor1), linkTopToBottom(lockedDoor1, torch);

    //This links the spaces from left to right. This means the East to West positions are all linked here.
    linkLeftToRight(key1, minion1), linkLeftToRight(minion1, blank2), linkLeftToRight(blank2, blank3),
            linkLeftToRight(blank7, minion3), linkLeftToRight(minion3, blank6);

    player1.setStartingLocation(startingSpace); //places the player at the starting location.

    key1.setItemName("key1"), key2.setItemName("key2"), torch.setItemName("torch"), sword.setItemName("sword"),
        shield.setItemName("shield"), flintSteel.setItemName("flint & steel");

    //opening text that prints to screen.
    std::cout << "You are part of a scouting band for the local township. It's your first day, but what could go wrong?"
                 " While scouting out the woods in the outlying areas, you came across a band of creatures..."
                 "goblins." << std::endl
              << "Unfortunately, they caught you before you could get away and warn your compatriots. You were"
                 " blindfolded and taken away with your hands tied, most likely to be interrogated and eaten. Truly a"
                 " gruesome end." << std::endl << "You were led somewhere cool and you could hear your footprints echo"
                 " against stone walls. Underground, most likely." << std::endl << "They walk you deeper and deeper"
                 " inside before you hear their attention apparently drawn by something else. You hear them"
                 " growling and hissing at each other until one eventually pokes something into you. You can feel it"
                 " begin to radiate pain outward." << std::endl << "You know you've been poisoned. They push you and"
                 " you stumble to the ground. You listen, but they've apparently left you alone. It doesn't make sense,"
                 " but you don't let the opportunity slip away. You slide your hands under your legs until they're in"
                 " front of you, pull off your blindfold and use your teeth to untie the knots binding your hands. You"
                 " look around and immediately start to make your way out." << std::endl << std::endl << "OBJECTIVE: "
                 " Find the cave entrance and escape." << std::endl << std::endl;

    player1.getPlayerLocation()->getRoomExits(); //prints possible routes

    //This is the main game loop. Until the player either wins or dies, this loop repeats.
    do {
        do {
            movementFlag = false;

            std::cout << std::endl << "where would you like to move?" << std::endl << "Press 1: North" << std::endl
                      << "Press 2: East" << std::endl << "Press 3: South" << std::endl << "Press 4: West" << std::endl;
            directionMove = inputCheck(1, 4);
            player1.updateRoutes();

            //checks for legal movement and performs the move if it is legal.
            if (directionMove == 1 && player1.getNorthOption()) {
                player1.setPlayerLocation(player1.getPlayerLocationNorth());
                movementFlag = true;
            } else if (directionMove == 2 && player1.getEastOption()) {
                player1.setPlayerLocation(player1.getPlayerLocationEast());
                movementFlag = true;
            } else if (directionMove == 3 && player1.getSouthOption()) {
                player1.setPlayerLocation(player1.getPlayerLocationSouth());
                movementFlag = true;
            } else if (directionMove == 4 && player1.getWestOption()) {
                player1.setPlayerLocation(player1.getPlayerLocationWest());
                movementFlag = true;
            } else {
                std::cout << "It's not possible to go that way." << std::endl;
            }
        } while (movementFlag == false);

        //as per instruction, this block slowly lowers player's life as they move between rooms. Also checks for death.
        //if player dies, game over occurs.
        player1.incrementPlayerLife();
        std::cout << "You have " << player1.getPlayerLife() << " life left." << std::endl;
        if (player1.getPlayerLife() < 1) {
            std::cout << "You have died." << std::endl;
            player1.setPlayerLocation(&exit);
        }

        if (player1.getPlayerLocation() == &exit && player1.getPlayerLife() > 0) {
            std::cout << "You see daylight up ahead..." << std::endl << std::endl;
        }
        else if (player1.getPlayerLife() > 0) {
            player1.getCurrentRoomDescription(); //generic room description. Prints to screen.
        }

        //This block executes if the player is in an unplundered item room.
        if ((player1.getPlayerLocation() == &key1 || player1.getPlayerLocation() == &key2 ||
             player1.getPlayerLocation() == &torch || player1.getPlayerLocation() == &sword ||
             player1.getPlayerLocation() == &shield || player1.getPlayerLocation() == &flintSteel) &&
            !player1.getPlayerLocation()->getItemFlag()) {
            player1.addItem(); //adds current room item to player item container.
            std::cout << "You opened the chest and found a " << player1.getPlayerLocation()->getItemName() << std::endl
                      << std::endl;
            player1.getPlayerLocation()->setItemFlag();
            player1.getPlayerLocation()->setSecondaryText();

        }

        //Checks if it is an obstacle room, if so, checks for requisite items to pass. If items present, obstacle
        //removed, otherwise they go back to previous space.
        doorCheck(player1, lockedDoor1, lockedDoor2, chasmRoom);

        //checks if space contains a monster. If so, and it's not dead, battle occurs.
        if (player1.getPlayerLocation() == &minion1) {
            if (minion1.checkLifeStatus() == 1) {
                battleVictor = battleStart(player1Ptr, minion1Ptr);
            }
        }
        if (player1.getPlayerLocation() == &minion2) {
            if (minion2.checkLifeStatus() == 1) {
                battleVictor = battleStart(player1Ptr, minion2Ptr);
            }
        }
        if (player1.getPlayerLocation() == &minion3) {
            if (minion3.checkLifeStatus() == 1) {
                battleVictor = battleStart(player1Ptr, minion3Ptr);
            }
        }
        if (player1.getPlayerLocation() == &finalBoss) {
            if (finalBoss.checkLifeStatus() == 1) {
                battleVictor = battleStart(player1Ptr, minionFinalPtr);
            }
        }

        if (battleVictor == 1) { //if player wins...
            player1.getPlayerLocation()->setSecondaryText(); //sets "flag" for dead monster.
        } else if (battleVictor == 2) { //otherwise...
            player1.setHP(0);
            player1.setPlayerLocation(&exit); //ensures that the game ends with a game over.
        }

        if (player1.getPlayerLife() > 0) { //if player not dead...
            if (player1.getPlayerLocation() != &exit) {
                player1.viewInventory(); //prints inventory to the screen and...
                player1.getPlayerLocation()->getRoomExits(); //prints possible routes.
            }
        }
    } while (player1.getPlayerLocation() != &exit); //Loop continues until the exit is reached, or player is dead.

    if (player1.getPlayerLife() < 1) {
        std::cout << "You were unable to make it out alive. Game Over." << std::endl;
    }
    else { //closing text
        std::cout << "You stumble out of the cave - with the poison still draining your life - to a violent, but"
                     " wonderful sight. In front of you are at least a dozen goblins dead on the ground. Some with"
                     " arrows sticking out and some impaled with spears." << std::endl << std::endl
                  << "Standing in front of you are the rest of the scouts, five in total. Not an army, but more than"
                     " enough for a dozen or so goblins. While you retreat with the other scouts, you report your"
                     " condition, receive potions for your wounds & the poison, and learn that one of the scouts had"
                     " been tasked with shadowing your route. He saw you get captured, but against over a dozen"
                     " goblins, a solo rescue would have been suicidal. He ran back, gathered the other scouts and"
                     " mounted a rescue. Apparently that was the commotion that had caused the goblins to abandon you"
                     " blindfolded in the first place." << std::endl << std::endl
                  << " You can only surmise that they poisoned you - instead of simply killing you - so they could"
                     " still interrogate you, albeit in a weakened state. That way, regardless of their fighting"
                     " strength when they returned, they could still overpower you. But - you mused - that only works"
                     " if they're alive at the end. You make it back to the scouting outpost and lay down. All you can"
                     " think about, as you slowly start to relax, is that you made it through your first day."
                  << std::endl << std::endl << "THE END" << std::endl;
    }
}


/**************************************************************************************************
 *                                         linkTopToBottom()
 * Links spaces from North to South.
 *************************************************************************************************/
void Menu::linkTopToBottom(Space& frontSpace, Space& bottomSpace) {
    bottomSpace.setSouth(frontSpace);
    frontSpace.setNorth(bottomSpace);
}


/**************************************************************************************************
 *                                         linkLeftToRight()
 * Links spaces from East to West.
 *************************************************************************************************/
void Menu::linkLeftToRight(Space& leftSpace, Space& rightSpace) {
    leftSpace.setEast(rightSpace);
    rightSpace.setWest(leftSpace);
}


/**************************************************************************************************
 *                                         inputCheck()
 * Takes in a user value and checks to see if it is a legal integer. This means it is both an actual
 *     integer and an integer within the correct range.
 *************************************************************************************************/
//    http://www.cplusplus.com/reference/cstdlib/atoi/
//    http://www.cplusplus.com/forum/general/13135/
//    The above links were necessary in order to convert ints longer than a single digit.
int Menu::inputCheck(int minVal, int maxVal) {
    int returnVal = 0;
    std::string checkString;
    char tempChar;
    bool intFlag;
    bool stringFlag;

    do {
        std::cin >> checkString;
        for (int counter = 0; counter < checkString.size(); counter++) {
            tempChar = checkString[counter];
            if (static_cast<int>(tempChar) >= 48 && static_cast<int>(tempChar) <= 57) { //checks for ASCII int.
                stringFlag = true;
            } else {
                if (counter == 0 && static_cast<int>(tempChar) == 45) { //if the sign is (-), then it's still ok.
                    stringFlag = true;
                }
                else {
                    stringFlag = false;
                    std::cout << "Invalid input. Please enter a value between " << minVal << " and " << maxVal
                              << std::endl;
                    break;
                }
            }
        }
        if (stringFlag) {
            returnVal = atoi(checkString.c_str());  //string to int type conversion. check references above.
            if (returnVal >= minVal && returnVal <= maxVal) {
                intFlag = true;
            } else {
                intFlag = false;
                std::cout << "Invalid input. Please enter a value between " << minVal << " and " << maxVal << std::endl;
            }
        }
    } while (!stringFlag || !intFlag);

    std::cout << std::endl;
    return returnVal;
}


/**************************************************************************************************
 *                                         battleStart()
 * The actual combat function makes calls to the respective character classes for attack and defense. Loops
 *     until there is a winner.
 *************************************************************************************************/
int Menu::battleStart(Player* ptrPlayer1, Monster* ptrPlayer2) {
    bool lifeFlag;
    int winner = 0;
    do {
        std::cout << std::endl << std::endl << "Press any key + Enter to continue." << std::endl;
        std::cin.ignore(256, '\n');
        std::cin.get();
        std::cout << "You attack!" << std::endl;
        int playerAttack = ptrPlayer1->attack(); //returns attack val.
        lifeFlag = ptrPlayer2->defend(playerAttack); //uses attack val for defense phase.
        if (!lifeFlag) { //if character 2 is dead, skip the next battle phase and declare a winner.
            winner = 1;
        }
        else {
            std::cout << std::endl << std::endl << "Press any key + Enter to continue." << std::endl;
            std::cin.ignore(256, '\n');
            std::cin.get();
            std::cout << "The monster attacks!" << std::endl;
            playerAttack = ptrPlayer2->attack(); //returns character2 attack val.
            lifeFlag = ptrPlayer1->defend(playerAttack);
            if (!lifeFlag) {
                winner = 2; //declares character2 the winner if character1 is dead.
            }
        }
    } while (lifeFlag); //battle continues until one of the characters is dead.
    if (winner == 1) {
        std::cout << std::endl << "You were able to kill the monster. It lies dead in the room." << std::endl
                  << std::endl;
    }
    else {
        std::cout << std::endl << "You were killed by the monster's attack." << std::endl;
    }
    return winner;
}


/**************************************************************************************************
 *                                         doorCheck()
 * Checks requirements for obstacle rooms and either turns the player away or removes the obstacle from play.
 *************************************************************************************************/
void Menu::doorCheck(Player& player1, Obstacle& lockedDoor1, Obstacle& lockedDoor2, Obstacle& chasmRoom) {
    if (!player1.getPlayerLocation()->getSecondaryFlagCondition()) { //if  we haven't gotten past the obstacle...
        if (player1.getPlayerLocation() == &lockedDoor1) {
            if (player1.check(player1.getStack(), "key1")) {
                std::cout << "You used the key to unlock the door." << std::endl << std::endl;
                player1.getPlayerLocation()->setSecondaryText(); //set text that says the door is now open.
            }
            else if (player1.check(player1.getStack(), "key2")) {
                std::cout << "You try the key on the door... but it doesn't fit. You have no choice but to turn around."
                          << std::endl << "You find yourself back in the previous room..." << std::endl << std::endl;
                player1.setPlayerLocation(player1.getPlayerLocationSouth());
                player1.getCurrentRoomDescription();
            }
            else {
                std::cout << "You need a key to get past this door, you have no choice but to turn around."
                          << std::endl
                          << "You find yourself back in the previous room..." << std::endl << std::endl;
                player1.setPlayerLocation(player1.getPlayerLocationSouth());
                player1.getCurrentRoomDescription();
            }
        }

        if (player1.getPlayerLocation() == &lockedDoor2) {
            if (player1.check(player1.getStack(), "key2")) {
                std::cout << "You used the key to unlock the door." << std::endl << std::endl;
                player1.getPlayerLocation()->setSecondaryText(); //set text that says the door is now open.
            }
            else if (player1.check(player1.getStack(), "key1")) {
                std::cout << "You try the key on the door... but it doesn't fit. You have no choice but to turn around."
                          << std::endl << "You find yourself back in the previous room..." << std::endl << std::endl;
                player1.setPlayerLocation(player1.getPlayerLocationNorth());
                player1.getCurrentRoomDescription();
            }
            else {
                std::cout << "You need a key to get past this door, you have no choice but to turn around." << std::endl
                          << "You find yourself back in the previous room..." << std::endl << std::endl;
                player1.setPlayerLocation(player1.getPlayerLocationNorth());
                player1.getCurrentRoomDescription();
            }
        }

        if (player1.getPlayerLocation() == &chasmRoom) {
            if (player1.check(player1.getStack(), "torch", "flint & steel")) {
                std::cout << "You lit the torch with the flint & steel. You can now make your way through the"
                             " treacherous pits in the pitch black room." << std::endl <<std::endl;
                player1.getPlayerLocation()->setSecondaryText(); //set text that says the door is now open.
            } else {
                std::cout << "You toss a rock into the pitch black room, but don't hear it hit the ground." << std::endl
                          << "You're sure there are deep chasms in this room so you decide to turn back to try and find"
                             " a way to light the way." << std::endl << "You find yourself back in the previous room..."
                             << std::endl << std::endl;
                player1.setPlayerLocation(player1.getPlayerLocationSouth());
                player1.getCurrentRoomDescription();
            }
        }
    }
}