#ifndef EVENT_CLASS_H
#define EVENT_CLASS_H

class eventClass
{
protected:
    // event weight is how impactful it is to the player
    // events are going to be chosen with a specific
    // algorithm based on multiple event values
    int m_weight {};
    // trigger is the condition in which it is activated
    // conditions: 
    // 1 (entering a room),
    // 2 (losing sanity), 
    // 3 (using an item),
    // 4 (reaching a level)
    // 5 (reading a certain text)
    int m_trigger {};
public:
    // constructor

    // end of constructor

    //getters & setters
    int getWeight()
    {
        return m_weight;
    }
    int getTrigger()
    {
        return m_trigger;
    }
    void setWeight(int weight)
    {
        m_weight = weight;
    }
    void setTrigger(int trigger)
    {
        m_trigger = trigger;
    }
    // potential methods:
    // check trigger
    // execute event
};

#endif