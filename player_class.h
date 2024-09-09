#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <string>
#include <vector>
#include "room_class.h"
#include "message_class.h"

class roomClass;
class messageClass;

class playerClass
{
public:
    bool isAlive;
    std::string name;
    int health;
    int hunger;
    int sanity;
    int currentRoom;
    //inventory

    //methods:
    //shows player attributes
    int get_health(playerClass& player)
    {
        return player.health;
    }
    int get_hunger(playerClass& player)
    {
        return player.hunger;
    }
    int get_sanity(playerClass& player)
    {
        return player.sanity;
    }
    //move between the rooms function
    void move_rooms(std::vector<roomClass>)
    {

    }

    //get current room
    void get_current_room(std::vector<roomClass> room, playerClass& player)
    {
        int i{currentRoom};
        room[i].get_description(room[i].roomType, player);
    }
    //get last room
    //get next room

    //void addItemInv(itemClass& item);
    //void useItemInv(int itemIndex);
};

#endif