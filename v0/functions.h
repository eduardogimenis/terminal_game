#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "classes.h"

void print_player_attributes(playerClass& player)
{
    //get attributes:
    int health{player.get_health(player)};
    int hunger{player.get_hunger(player)};
    int sanity{player.get_sanity(player)};

    std::cout << player.name << ", your current attributes: \n"
    << "Health: " << health << "\n"
    << "Hunger: " << hunger << "\n"
    << "Sanity: " << sanity << "\n";
}

void get_room_description(int roomType, playerClass& player)
{   
    //pass room type as an argument
    //gets different descriptions based on room type
    //and different descriptions based on player attributes
    
    //get attributes:
    int health{player.get_health(player)};
    int hunger{player.get_hunger(player)};
    int sanity{player.get_sanity(player)};

    //switch based on room type
    switch(roomType)
    {
        messageClass temp;
        case 1:
            //the lobby
            temp.theLobby(health, hunger, sanity);
            break;
        case 2:
            //basic room
            temp.basicRoom(health, hunger, sanity);
            break;
        case 3:
            //the staircase
            temp.theStaircase(health, hunger, sanity);
    }
}
void initialMessage(playerClass& player)
{
    std::cout << "\nWelcome, " << player.name << ", to the backrooms.\n";
    std::cout << "You have " << player.health << " health points." << std::endl;
    std::cout
    << "==============================++===============++=========================" 
    << "==============================++===============++========================="
    << "==============================++===============++=========================\n\n\n"  
    << "You find yourself in a familiar place,"
    << " it's as if you have already worked here before,"
    << " but this time it feels different. There's a buzzing noise that does not seem to stop.\n"
    << "It seems to be coming from the flourescent lights above. And as you keep looking," 
    << " you notice that the same brand of lights seem to be going on, forever, theres no end in sight.\n"
    << "At this moment you wonder what you have done wrong to find yourself here, what is this place?\n"
    << "\n\n";
}


//get current room
void get_current_room(std::vector<roomClass> room, playerClass& player)
{
    int current_room{player.get_room(player)};
    room[current_room].hasPlayerVisited = true;
    get_room_description(room[current_room].roomType, player);
}
//get last room
//get next room

//void addItemInv(itemClass& item);
//void useItemInv(int itemIndex);

std::vector<roomClass> level_initializer(int roomNumber)
{
    std::vector<roomClass> levelVector;
    roomClass level; //initializes class
    //initializes values for the first member = always lobby
    level.hasPlayerVisited = false;
    level.name = "The Lobby.";
    level.roomType = 1;
    levelVector.push_back(level);

    //intializes variable number of basicRooms
    for (int i = 0; i < roomNumber; i++)
    {
        level.basicRoomInitializer();
        levelVector.push_back(level);
    }

    //appends with staircase
    level.hasPlayerVisited = false;
    level.name = "The Staircase.";
    level.roomType = 3;
    levelVector.push_back(level);

    return levelVector;
}

void move_room_forward(std::vector<roomClass> room, playerClass& player)
{
    int current_room{player.get_room(player)};
    current_room += 1;
    player.currentRoom = current_room;
    player.hunger -= 5;
}
void move_room_backward(std::vector<roomClass> room, playerClass& player)
{
    int current_room{player.get_room(player)};
    current_room -= 1;
    player.currentRoom = current_room;
    player.hunger -= 5;
}

int whatDoYouWantFromHere(playerClass& player, std::vector<roomClass> room)
{
    //print a menu choice for the player
    //uses choice to determine what next
    //calls other functions to perform actions
    int choice;
    std::cout
    << "\n\n\nYour options: \n"
    << "1. Check stats.\n2. Go to the next room.\n3. Go to the previous room.\n6. Exit game.\nYour choice: ";
    std::cin >> choice;
    std::cout << "\n\n";
    switch(choice)
    {
        messageClass msg;
        case 1:
            print_player_attributes(player);
            return 1;
            //ask choices again
        case 2:
            move_room_forward(room, player);
            get_current_room(room, player);
            return 2;
            //break
        case 3:
            move_room_backward(room, player);
            get_current_room(room, player);
            return 3;
            //break
        case 4:
            //loot
            //ask choices again
        case 5:
            //useitem
            //ask choices again
        case 6:
            //exit game
            msg.lastMessage();
            exit(0);
        default:
            return 0;
            //ask choices again
    }
}
#endif