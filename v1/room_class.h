#ifndef ROOM_CLASS_H
#define ROOM_CLASS_H
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>

// function to clear the terminal screen.
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// what is going to be included with messages:
// include messages with rooms
// inherit room class for room types
// messages to be played out:
// considers if first time or not
// considers player sanity
// if sanity above 70% normal
// if sanity below 70% and above 30% tense
// if sanity below 30% dramatic
// if sanity less than 10% horror

// base class for all rooms
// includes a name for the room
// and if the room has been visited or not.
class roomClass
{
protected:
    bool m_hasPlayerVisited;
    std::string m_name;
public:
    // constructor
    roomClass(std::string name)
        : m_hasPlayerVisited{false}, m_name{name}
    {
    }
    // end of constructor

    // getters & setters
    bool getPlayerVisited()
    {
        return m_hasPlayerVisited;
    }
    std::string_view getName()
    {
        return m_name;
    }
    void setPlayerVisited(bool true_or_false)
    {
        m_hasPlayerVisited = true_or_false;
    }
    // actions
    void visited()
    {
        m_hasPlayerVisited = true;
    }
    virtual void message(int health, int hunger, int sanity)
    {
    }
};

// basicRoom is a room subclass
// it inherits name and if player has visited
// prints a message for the room
// based on a few parameters.
class basicRoom : public roomClass
{
public:
    // constructor
    basicRoom(std::string name)
        : roomClass(name)
    {
    }
    // end of constructor
    void message(int health, int hunger, int sanity) override
    {
        roomClass::message(health, hunger, sanity);
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
};

// theLobby is the first room in all levels
// its the first one to be inserted into the vector
// also includes a message with a few parameters.
class theLobby : public roomClass
{
public:
    // constructor
    theLobby(std::string name)
        : roomClass(name)
    {
    }
    // end of constructor
    void message(int health, int hunger, int sanity) override
    {
        roomClass::message(health, hunger, sanity);
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
};

// staircase is always the last room in a level
// it contains a message as well
class theStaircase : public roomClass
{
public:
    // constructor
    theStaircase(std::string name)
        : roomClass(name)
    {
    }
    // end of constructor
    void message(int health, int hunger, int sanity) override
    {
        roomClass::message(health, hunger, sanity);
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
};

// level generator is a room subclass
// it's how I am generating the levels
// it procedurally generates a very basic layout (so far)
// based on just a few things.
// it also starts and initializes a randomizer, completely seeded.
// might be wise to have a better way to initialize.
class Generator : public roomClass
{
private:
    // creates a randomizer seeded:
    std::random_device rd{};
    // get 8 integers of random numbers from std::random_device for our seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    // initialize our Mersenne Twister with the std::seed_seq
    std::mt19937 mt{ss};
    // Create a reusable random number generator that generates uniform numbers
    std::uniform_int_distribution<> random_3_to_6{3, 6};

    // vector for storing rooms
    std::vector<roomClass *> rooms;

    // stores the number of randomized rooms for the level
    // includes random_3_to_6 + 2 (lobby + staircase)
    int m_number_of_rooms{};

public:
    // constructor
    Generator(std::string name)
        : roomClass(name)
    {
    }
    // end of constructor

    // getters & setters
    int getNumberOfRooms()
    {
        return m_number_of_rooms;
    }
    void setNumberOfRooms(int number_of_rooms)
    {
        m_number_of_rooms = number_of_rooms;
    }
    std::vector<roomClass *> getLevels()
    {
        return rooms;
    }

    // generator function
    // it's a simple generator based on just having:
    // the lobby as the first room, the staircase as the last,
    // and a random number in between.
    // would be nice to implement the item system right here.
    void generateSimpleLevels()
    {
        // clears the vector
        rooms.clear();
        // first room is the lobby
        rooms.push_back(new theLobby("The Lobby."));
        // creates a random variable for the level generator
        int number_of_basic_rooms{};
        number_of_basic_rooms = random_3_to_6(mt);
        // sets the variable to the randomly generated amount.
        m_number_of_rooms = number_of_basic_rooms + 2; //(lobby + staircase)

        // using the random number, it inserts a variable number
        // of basic rooms, this is the part that can be tweaked.
        for (int i = 0; i < number_of_basic_rooms; i++)
        {
            rooms.push_back(new basicRoom("Basic Room " + std::to_string(i + 1) + "."));
        }

        // adds the last room in the level,
        // the staircase.
        rooms.push_back(new theStaircase("The Staircase."));
    }
    // display all levels
    // iterates through the vector.
    void displayLevel()
    {
        std::cout << "\n--- " << "There are " << m_number_of_rooms << " rooms" << " ---\n";
        for (int i = 0; i < rooms.size(); i++)
        {
            std::cout << rooms[i]->getName() << "\n";
        }
        std::cout << "--- " << "----------------" << " ---\n";
    }
    // display current room, including room sub-class message,
    // based on player's current position
    void getCurrentRoom(int playerRoomIndex, int health, int hunger, int sanity)
    {
        std::cout << "\n";
        rooms[playerRoomIndex]->message(health, hunger, sanity);
    }
    // prints out the room name based on the player position.
    void getCurrentRoomInfo(int playerRoomIndex)
    {
        std::cout << rooms[playerRoomIndex]->getName();
    }
};
#endif