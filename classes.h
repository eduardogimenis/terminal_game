#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <iostream>
#include <vector>
#include "player_class.h"
#include "message_class.h"
#include "room_class.h"

//Classes
class itemClass
{
public:
    std::string name;
    std::string description;
    int rarity;  //used with the item picker, rarer items are less picked
    int quality; //dictates the effectiveness of the item, a poor quality apple satisfies less hunger

    //methods:
    //void useItem(playerClass& player)
    //std::string getDescription(); 
};


class itemDescriptionsClass
{
    //where all the item descriptions will be at
    //procedurally take from here for specific attributes of generated item
};

#endif