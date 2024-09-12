#ifndef ITEM_CLASS_H
#define ITEM_CLASS_H
#include <string>

class itemClass
{
protected:
    // weight is going to be used in conjunction with the backpack system
    std::string m_name {};
    // an item's weight is going to affect how much the player can carry
    int m_weight {};
    //the item's noise level variable affects how much noise the player makes,
    // as he walks between rooms.
    // noise level can go from 0 to 100.
    int m_noise_level {};
    // types: food, health, sanity, stamina.
    int m_type {};
    // rarity: 1 (basic), 2 (important), 3 (necessary)
    int m_rarity {};
    // value: smaller values, to feel more like a barter economy
    // total player value will be calculated at the end of a level.
    int m_value {};
public:
    // constructor

    // end of constructor

    // getters & setter
    std::string_view getName()
    {
        return m_name;
    }
    int getWeight()
    {
        return m_weight;
    }
    int getNoise()
    {
        return m_noise_level;
    }
    int getType()
    {
        return m_type;
    }
    int getRarity()
    {
        return m_rarity;
    }
    int getValue()
    {
        return m_value;
    }
    void setName(std::string_view name)
    {
        m_name = name;
    }
    void setWeight(int weight)
    {
        m_weight = weight;
    }
    void setNoise(int noise)
    {
        m_noise_level = noise;
    }
    void setType(int type)
    {
        m_type = type;
    }
    void setRarity(int rarity_level)
    {
        m_rarity = rarity_level;
    }
    void setValule(int value)
    {
        m_value = value;
    }
};

#endif