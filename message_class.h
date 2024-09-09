#ifndef MESSAGE_CLASS_H
#define MESSAGE_CLASS_H

#include <iostream>
#include "player_class.h"
#include "room_class.h"

class playerClass;
class roomClass;

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
        << "\n\n\n";
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
    /*int whatDoYouWantFromHere(int choice)
    {
        //print a menu choice for the player
        //uses choice to determine what next
        //calls other functions to perform actions
        switch(choice)
        {
            case 1:
                //check stats & inv
                //ask choices again
            case 2:
                //go next room
                //break
            case 3:
                //go backwards
                //break
            case 4:
                //loot
                //ask choices again
            case 5:
                //useitem
                //ask choices again
            default:
                //ask choices again
        }
    }*/
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
#endif