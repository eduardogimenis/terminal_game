#ifndef MENU_CLASS_H
#define MENU_CLASS_H

#include <iostream>
#include <string>
#include <vector>
// constants & settings

// menu
class menuClass
{
protected:
    // has a menu title, and a vector for options
    // the options can be initialized in the constructor,
    // but allows a variable amount of options.
    std::string m_title;
    std::vector<std::string> m_options;

public:
    // constructor
    menuClass(const std::string &title, const std::vector<std::string> &options)
        : m_title{title}, m_options{options}
    {
    }
    // end of constructor

    // methods

    // prompts user with choices from the vector that is initialized
    // returns the choice made
    int display()
    {
        
        int choice;
        do
        {
            std::cout << "\n--- " << m_title << " ---\n";
            for (int i = 0; i < m_options.size(); ++i)
            {
                std::cout << i + 1 << ". " << m_options[i] << std::endl;
            }
            std::cout << "Enter your choice: ";
            std::cin >> choice;
        } while (choice < 1 || choice > m_options.size());

        return choice;
    }
};

// class for the game menu
// initializes a set amount of options
// uses the same display function to handle option input
class gameMenu : public menuClass
{
public:
    // constructor
    gameMenu()
        : menuClass("Game Menu", {"Move", "See attriutes",
                                  "Loot", "See Items", "Save", "Exit"})
    {
    }
    // end of constructor
};

// more menus based on if settings are going to be changed, if randomizer is going to be
// player seeded etc.
#endif