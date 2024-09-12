#ifndef BACKPACK_CLASS_H
#define BACKPACK_CLASS_H
#include "item_class.h"

#include <map>

class backpackClass
{
protected:
    // basic variables that would be able to affect the player,
    // max_weight is how much the backpack can fit
    // current_noise_level is how much noise the backpack generates,
    // as the player goes from room to room. It might have some effect in events.
    int m_max_weight {};
    int m_current_weight {};
    int m_current_noise_level {};

    // a dictionary for storing item name and the item class inside.
    std::map<std::string, itemClass *> itemsInside;

public:
    // constructor

    // end of constructor
    
    // getters & setters
    int getMaxWeight()
    {
        return m_max_weight;
    }
    int getCurrentWeight()
    {
        return m_current_weight;
    }
    int getCurrentNoiseLevel()
    {
        return m_current_noise_level;
    }
    void setMaxWeight(int max_weight)
    {
        m_max_weight = max_weight;
    }
    void setCurrentWeight(int current_weight)
    {
        m_current_weight = current_weight;
    }
    void setCurrentNoiseLevel(int current_noise_level)
    {
        m_current_noise_level = current_noise_level;
    }
    // actions
    void add_to_backpack(int item_weight, int item_noise)
    {
        m_current_weight += item_weight;
        m_current_noise_level += item_noise;
    }
    void remove_from_backpack(int item_weight, int item_noise)
    {
        m_current_weight -= item_weight;
        m_current_noise_level -= item_noise;
    }
};

#endif