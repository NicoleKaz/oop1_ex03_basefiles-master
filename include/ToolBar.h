#pragma once
#include <SFML/Graphics.hpp>
//#include "Controller.h"
#include "Wall.h"
#include "Door.h"
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "Present.h"
//#include "Button.h"


class ToolBar
{
public:
    void setSize(float, float);
    void init();
    void drawToolBar(sf::RenderWindow& m_window);
    //void draw(sf::RenderWindow& window);
    //const sf::RectangleShape getToolBar();
    //const sf::RectangleShape getButton(const int);
    //const char GetButtonChar(const int);

private:
    int m_col, m_row;
    sf::RectangleShape m_outline;
    Wall m_wall;
    Door m_door;
    Cat m_cat;
    Mouse m_mouse;
    Cheese m_cheese;
    Present m_present;
    /*Key m_key;
    Erase m_erase;
    Reset m_reset;
    Save m_save;*/

    ////buttons array
    //Button* m_botton[10] = { &m_wall, &m_door, &m_cat, &m_mouse,&m_cheese,
    //                        &m_present, &m_key, &m_erase, &m_reset, &m_save };

    //Button* m_botton[6] = { &m_wall, &m_door, &m_cat, &m_mouse, &m_cheese, &m_present };
};
