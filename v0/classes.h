#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <iostream>
#include <vector>

class playerClass;
class messageClass;
class roomClass;

//Classes
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
    int get_room(playerClass& player)
    {
        return player.currentRoom;
    }
};
class roomClass
{
public:
    bool hasPlayerVisited;
    std::string name;
    int roomType;

    //methods:
    void basicRoomInitializer()
    {
        hasPlayerVisited = false;
        name = "Basic Room.";
        roomType = 2;
    }
};
class messageClass
{
public:
    //messages to be played out
    //considers if first time or not
    //considers player sanity
        //if sanity above 70% normal
        //if sanity below 70% and above 30% tense
        //if sanity below 30% dramatic
        //if sanity less than 10% horror

    
    void lastMessage(void)
    {
        std::cout 
        << "\n\n==============================++===============++=========================" 
        << "==============================++===============++========================="
        << "==============================++===============++=========================\n"  
        << "\nThanks for trying out this little game.\n";
    }
    void theLobby(int health, int hunger, int sanity)
    {
        if (hunger < 50)
        {
            std::cout << "You are getting hungry.\n";
        }
        if (sanity < 70)
        {
            std::cout << "You notice something different, unsettling.\n";
        }
        if (health < 30)
        {
            std::cout << "Your body feels heavy.\n";
        }
        std::cout << "You step into what it seems to be a lobby.\n";
    }
    void basicRoom(int health, int hunger, int sanity)
    {
        if (hunger < 50)
        {
            std::cout << "\nYou are getting hungry.\n";
        }
        if (sanity < 70)
        {
            std::cout << "\nYou notice something different, unsettling.\n";
        }
        if (health < 30)
        {
            std::cout << "\nYour body feels heavy.\n";
        }
        std::cout 
        << "You step into what it seems to be a basically empty room.\n"
        << "The same beige wallpaper paints the wall, the same humming sound coming from above.\n"
        << "And the same feeling of a distant familiarity.\n";
    }
    void theStaircase(int health, int hunger, int sanity)
    {
        if (hunger < 50)
        {
            std::cout << "\nThis might be the best place to grab a snack\n";
        }
        if (sanity < 70)
        {
            std::cout << "\nYou could take some time to recuperate.\n";
        }
        if (health < 30)
        {
            std::cout << "\nYou are exhausted.\n";
        }
        std::cout
        << "You find the staircase, you can't see the end looking up.\n"
        << "Regardless, you feel an urge to go up the stairs.\n";
    }
    
    // descriptive message for types of rooms:
    // - theLobby office room
    // - theLobby empty room
    void deadMessage(int reason)
    {
        //reason 1 - health
        //reason 2 - went insane
        //reason 3 - dehydration
        //reason 4 - hunger
        //ask to restart, defaults to exiting
        switch(reason)
        {
            default:
                std::cout << "You quit the game.";
                exit(0);
        }
    }
};
class itemClass
{
public:
    std::string name;
    std::string description;
    int rarity;  //used with the item picker, rarer items are less picked
    int quality; //dictates the effectiveness of the item, a poor quality apple satisfies less hhunger

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