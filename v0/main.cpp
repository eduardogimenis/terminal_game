#include <iostream>
#include <string>
#include "classes.h"
#include "functions.h"

int main()
{
    // initializing classes
    playerClass player;
    messageClass message;

    //initializing classes values
    //playerClass
    player.health = 100; //fully healthy
    player.hunger = 100; //fully satisfied
    player.sanity = 100; //fully sane
    player.isAlive = true;
    player.currentRoom = 0;
    std::cout << "Enter a name for your character: \n";
    getline(std::cin, player.name);

    // welcoming words
    initialMessage(player);

    //level initialization
    //roomClass level0;
    int level0_numberRooms {3};
    std::vector level0Vector = {level_initializer(level0_numberRooms)};
    get_current_room(level0Vector, player); //theLobby
    
    // infinite loop
    while (1)
    {
        if (!player.isAlive)
        {
            message.deadMessage(0);
        }
        while (player.isAlive)
        {
            if (whatDoYouWantFromHere(player, level0Vector) == 0)
            {
                continue;
            }
            if (whatDoYouWantFromHere(player, level0Vector) == 1)
            {
                get_current_room(level0Vector, player);
                continue;
            }
            if (whatDoYouWantFromHere(player, level0Vector) == 2)
            {
                get_current_room(level0Vector, player);
                continue;
            }
            else
                continue;
            //gameplay loop
            //handles finishing level
            //creating new level
        }
    }

    // closing words
    message.lastMessage();

    return 0;
}