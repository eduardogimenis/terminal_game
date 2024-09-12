#include <iostream>
#include <string>
#include "classes.h"

int main()
{
    // initializes variable to keep track of levels
    // just used in main() in order to display
    // not used in any other way.
    int level_count{0};

    // intializes player to default values
    // asks the player for an input name for the character.
    std::cout << "What is your character name this time?\n";
    std::string name;
    getline(std::cin, name);
    Player player{name, 100, 100, 0, 100};

    // initializes menu
    // menu is then passed to the handleGameMenu function
    // this way it is only created once,
    // unlike a level class that has to be created for every level.
    gameMenu gameplayMenu{};

    // infinite loops to handle gameplay
    // outer loop handles level changes.
    while (1)
    {
        // clears the scrren using a terminal command.
        clearScreen();

        // prints the level fot the player, only use of level_count variable in main
        std::cout << "You enter level " << level_count << ".";

        // handles menu error, and level gameplay loop
        // passes the player and the menu as arguments
        // the function also creates an instance of the generated level,
        // that gets destroyed once it returns
        if ((level_count = handleGameMenu(player, gameplayMenu)) == -1)
        {
            std::cout << "There was an error.\n";
            exit(1);
        }
        else
            continue;
    }
    return 0;
}