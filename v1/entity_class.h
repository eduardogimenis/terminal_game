#ifndef ENTITY_CLASS_H
#define ENTITY_CLASS_H
#include <string>
#include <iostream>

// base class for any living creature
// might be used later for anything non-human
// or maybe a npc encounter (though this is unlikely)
class entityClass
{
protected:
    // variables that all child classes inherit
    // includes basic attributes of a living thing.
    std::string m_name {};
    bool        m_isAlive {};
    int         m_health {};
    int         m_hunger {};
    int         m_position {};
    int         m_stamina {};

public:
    // constructor
    entityClass(std::string name, bool isAlive, int health, int hunger, int position)
        : m_name{name}, m_isAlive{isAlive}, m_health{health}, m_hunger{hunger}, m_position{position}
    {
    }
    // end constructor

    // getters & setters
    int getHealth() const
    {
        return m_health;
    }
    int getHunger() const
    {
        return m_hunger;
    }
    int getPosition() const
    {
        return m_position;
    }
    bool getIsAlive() const
    {
        return m_isAlive;
    }
    std::string_view getName() const
    {
        return m_name;
    }
    void setHealth(int health_equals_to)
    {
        m_health = health_equals_to;
    }
    void setHunger(int hunger_equals_to)
    {
        m_hunger = hunger_equals_to;
    }
    void setPosition(int new_position)
    {
        m_position = new_position;
    }
    void setName(std::string_view name)
    {
        m_name = name;
    }
    // actions to the player
    // these might all be virtual, so each specific sub-entity class
    // can handle its own actions a certain way.
    virtual void die()
    {
        m_isAlive = false;
    }
    void revive()
    {
        m_isAlive = true;
    }
    void takeDamage(int damage)
    {
        m_health -= damage;
    }
    void move(int move_amount)
    {
        m_position += move_amount;
    }
    // print attributes for the terminal only
    // does not provide any specific return value to be used.
    virtual void print_attributes() const
    {
        std::cout
            << "Name:   " << m_name << "\n"
            << "Health: " << m_health << "\n"
            << "Hunger: " << m_hunger << "\n"
            << "Stamina: " <<  m_stamina << "\n";
    }
};

class Player : public entityClass
{
private:
    // Player only adds one variable
    // sanity is how events might be influenced.
    int m_sanity;
public:
    // constructor
    Player(std::string name, int health, int hunger, int starting_position, int sanity)
        : entityClass(name, true, health, hunger, starting_position), m_sanity{sanity}
    {
    }
    // end of constructor

    // includes all of entities methods
    // getters & setters of player
    int getSanity()
    {
        return m_sanity;
    }
    void setSanity(int set_sanity_to)
    {
        m_sanity = set_sanity_to;
    }
    // actions
    void loseSanity(int loss_sanity_amt)
    {
        m_sanity -= loss_sanity_amt;
    }
    void gainSanity(int gain_sanity_amt)
    {
        m_sanity += gain_sanity_amt;
    }

    // print attributes
    // it overrides the public method
    // and adds sanity.
    void print_attributes() const override
    {
        // first print common entity attributes
        entityClass::print_attributes();

        // then print specific player attribute(s)
        std::cout << "Sanity: " << m_sanity << "\n";
    }
    void die() override
    {
        entityClass::die();
        std::cout << "You died.\n";
    }
    // handles movement that is used in the gameplay loop
    // it handles movement based on the total number of rooms for a level
    // if the player is at room 0 (normally the lobby),
    // it doesn't let the player go backward
    // same thing once the player reaches the end of the level.
    void handleMove(int total_number_rooms)
    {
        // total number of rooms is the int value
        // returned from the levelgenerator
        int move_direction;
        std::cout << "1 for Forward, 2 for Backward?\n";
        std::cin >> move_direction;

        // if the movement direction input is not one specified
        // it ends the function.
        if (move_direction != 1 && move_direction != 2)
        {
            std::cout << "Select either 1 or 2.\n";
            return;
        }

        // if the movement is forward, it checks to see,
        // if the player has reached the end of the level.
        if (move_direction == 1)
        {
            if (getPosition() >= total_number_rooms - 1)
            // -1 because player pos = 0, vector = 1
            // magic number is this case, but only way to make it work
            // the statement above is how I assume it works.
            {
                std::cout << "You have already reached the end of the level.\n";
                return;
            }
            move(1);
            return;
        }

        // else, the movement is going to be backward
        // then checks to see if the player is at the beginning of the level
        else
        {
            if (getPosition() <= 0)
            {
                std::cout << "You cannot move backward right now.\n";
                return;
            }
            move(-1);
            return;
        }
    }
};
#endif