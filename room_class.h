#ifndef ROOM_CLASS_H
#define ROOM_CLASS_H

#include <vector>
#include <string>
#include "player_class.h"
#include "message_class.h"


class messageClass;
class playerClass;

class roomClass
{
public:
    bool hasPlayerVisited;
    std::string name;
    int roomType;

    //methods:
    //descriptions from the messageClass
    void get_description(int roomType, playerClass& player)
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
    void basicRoomInitializer()
    {
        hasPlayerVisited = false;
        name = "Basic Room.";
        roomType = 2;
    }
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
    //generate items
    //remove item from room
};
#endif