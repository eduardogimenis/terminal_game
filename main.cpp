#include <iostream>
#include <string>
#include "classes.h"
#include "player_class.h"
#include "message_class.h"
#include "room_class.h"


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
    message.initialMessage(player);
    
    // infinite loop
    while (1)
    {
        if (!player.isAlive)
        {
            message.deadMessage(0);
        }
        if (player.isAlive)
        {
            //level initialization
            roomClass level0;
            int level0_numberRooms {3};
            std::vector level0Vector = {level0.level_initializer(level0_numberRooms)};

            player.get_current_room(level0Vector, player);
            

            //
            break;

            //gameplay loop
            //handles finishing level
            //creating new level
        }
    }

    // closing words
    message.lastMessage();

    return 0;
}