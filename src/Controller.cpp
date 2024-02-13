#include "Controller.h"


void Controller::initWindow()
{
    m_window.create(sf::VideoMode(1100, 950), "Mouse&Cat Editor");
    m_background.loadFromFile("background.png");
    m_background.setSmooth(true);
    sf::Sprite s1(m_background);
    s1.scale(sf::Vector2f(1.2f, 1.2f));
    m_window.clear(sf::Color::Color(255, 255, 230));
    m_window.draw(s1);
    m_window.display();
}

void Controller::run()
{
    bool reset = true;
    while (reset)
    {
        initWindow();
        //sets the background sprit
        sf::Sprite s1(m_background);
        s1.scale(sf::Vector2f(1.2f, 1.2f));
        init();
        bool pressed = false;
        char type = 0;
        bool reflection = false;
        int row = 0, col = 0;
        m_window.setFramerateLimit(30);
        while (m_window.isOpen())
        {
            //clear and draw
            m_window.clear(sf::Color::Color(255, 255, 230));
            m_window.draw(s1);
            m_board.drawBoard(m_window);
            m_toolBar.drawToolBar(m_window);
            m_window.display();
            
            if (auto event = sf::Event{}; m_window.waitEvent(event))
            {
                //handle every case of event
                switch (event.type)
                {
                case sf::Event::Closed:
                {
                    m_window.close();
                    reset = false;
                    break;
                }
                case sf::Event::MouseButtonReleased:
                {                   
                    auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                    handleClick(location, type, pressed);
                    break;
                }

                case sf::Event::MouseMoved:
                {
                    //if (pressed) // if was any press at the tool bar
                    //{
                    //    handlereflction(reflection, row, col); //update reflection if the press was in the board
                    //}
                    //break;
                }

                }
            }
        }

    }
}

void Controller::handleClick(const sf::Vector2f& location, char& type, bool& pressed)
{
    if (m_toolBar.getGlobalBounds().contains(location))
    {
        //handle each button at the toolbar
        type = m_toolBar.handleClickToolBar(location, pressed);
        if (type == 'R')
        {
            m_window.close();
        }
        else if (type == 'S')
        {
            //CreateFile();
            return;
        }

        
    }
    else
    {
        m_board.handleClickBoard(location, type, pressed);
    }
}

void Controller::init()
{
    if (!m_ifile.fail()) //if file opend
    {
        m_board.initWithGivenMatrix(m_ifile);//reset the matrix with the file
    }
    else
    {
        m_board.setSize();
        m_board.initMatrix();
    }
    m_window.setSize(sf::Vector2u(1050, 950));
    m_toolBar.init();
}

