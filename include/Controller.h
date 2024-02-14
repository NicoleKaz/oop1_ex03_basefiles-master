#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "ToolBar.h"
#include "Board.h"


class Controller
{
public:
    void initWindow();
    void run();
    void init();


private:
    void handleClick(const sf::Vector2f& location, char& type, bool& pressed);
    //void reset();
    ToolBar m_toolBar;
    Board m_board;
    sf::RenderWindow m_window;
    sf::Texture m_background;
    std::ifstream m_ifile = std::ifstream("Board.txt");
    std::ofstream m_ofile;
};