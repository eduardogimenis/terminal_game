#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include "entity_class.h"
#include "room_class.h"
#include "menu_class.h"


// function that handles the menu
// initialized player and menu are the parameters
// currently, initializes a generate sub-class everytime it's called,
// on every new level. might not be the best way of doing it,
// since I can clear the vector
int handleGameMenu(Player &player, gameMenu &menu)
{
    // static variable that counts levels
    // used only within this function
    // doesn't have any functionality beyond displaying the level
    // and returning it.
    // maybe I can use the static variable in the level generator?
    // still unsure how I would.
    static int level_count{0};

    // initializes a generator sub-class everytime it is called
    // this means that an object is initialized and destroyed everytime
    // I have to find a better way of handling it.
    Generator level{"Level " + std::to_string(level_count + 1) + "."};
    level.generateSimpleLevels(), level.displayLevel();

    // prints the lobby name and description before showing the options.
    level.getCurrentRoomInfo(player.getPosition());
    level.getCurrentRoom(player.getPosition(), player.getHealth(), player.getHunger(), player.getSanity());
    
    // infinite loop checking if player is alive.
    // have to handle if player is not, 
    // that would be a restart screen of some sort.
    int choice{};
    while (player.getIsAlive())
    {
        // calls the display menu function
        // to show menu options (therefore really easy to change options)
        // but if options are changed, the switch also would have to change.
        choice = menu.display();

        // switch based on player's choice
        switch (choice)
        {
        case 1:
            // calls the player handle movement function
            // it sends in the generated level's number of rooms as argument
            // this means that the random amount is sent.
            player.handleMove(level.getNumberOfRooms());
            clearScreen();
            // displays current room for player
            level.getCurrentRoomInfo(player.getPosition());
            level.getCurrentRoom(player.getPosition(), player.getHealth(), player.getHunger(), player.getSanity());
            break;
        case 2:
            // prints player's attributes
            player.print_attributes();
            break;
        case 3:
            // Loot room
            std::cout << "WIP\n";
            break;
        case 4:
            // see backback
            std::cout << "WIP\n";
            break;
        case 5:
            // save
            std::cout << "WIP\n";
            break;
        case 6:
            exit(0);
        default:
            std::cout << "Please pick an option given.\n";
        }
        // now it handles end of level (theStaircase)
        // player can go up a level
        // or exit.
        // if player goes up, the static level amount is incremented
        // and the value returned.
        // the return value is only, currently, being used to check if any errors arise
        // but could be used in level generation?
        while (player.getPosition() >= level.getNumberOfRooms() - 1)
        {
            std::cout
                << "Now that you've reached the staircase,\n"
                << "what would you like to do?\n"
                << "1. Go up.\n2. Dematerialize (exit).\n";
            std::cin >> choice;

            if (choice == 1)
            {
                clearScreen();
                std::cout
                    << "You chose to go to go up the stairs,\n"
                    << "to the next level.\n"
                    << "As you go up the stairs you wonder,\n"
                    << "how many more levels will I have to go up to the reach the surface?\n\n";
                level_count++;
                player.setPosition(0);
                return level_count;
            }
            else
            {
                std::cout << "You chose to exit.";
                exit(0);
            }
        }
    }
    // error number.
    // I don't know how it would get here
    // but just in case.
    return -1;
}
#endif