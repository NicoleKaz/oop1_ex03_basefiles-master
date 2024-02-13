#pragma once
#include <SFML/Graphics.hpp>
//#include "Controller.h"
#include "GameObject.h"
const int NUM_OF_OBJECT = 11;

class ToolBar
{
public:
    void setSize(float, float);
    void init();
    void drawToolBar(sf::RenderWindow& m_window);
    const sf::RectangleShape getObject(const int object);
    const sf::RectangleShape getButton(const int);
    char handleClickToolBar(const sf::Vector2f& location,bool pressed);
    const char GetButtonChar(const int button);
    const sf::RectangleShape getToolBar();
    sf::FloatRect getGlobalBounds()const{ return m_outline.getGlobalBounds();}
    //void draw(sf::RenderWindow& window);
    //const sf::RectangleShape getToolBar();
    //const sf::RectangleShape getButton(const int);
    //const char GetButtonChar(const int);

private:
    float m_col, m_row;
    sf::RectangleShape m_outline;
    Wall m_wall;
    Door m_door;
    Cat m_cat;
    Mouse m_mouse;
    Cheese m_cheese;
    Present m_present;
    Key m_key;
    Erase m_erase;
    Reset m_reset;
    Save m_save;
    Tool m_tool;

    //buttons array
    GameObject* m_object[NUM_OF_OBJECT] = { &m_wall, &m_door, &m_cat, &m_mouse, &m_cheese,
                                           &m_present, &m_key, &m_erase, &m_reset, &m_save, &m_tool };
};
