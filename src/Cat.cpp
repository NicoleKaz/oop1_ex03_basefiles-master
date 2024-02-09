#include "Cat.h"

Cat::Cat()
{
    m_type = '^';
}

void Cat::init()
{
    m_rec.setSize(sf::Vector2f(50.f, 50.f));
    m_texture.loadFromFile("Cat.png");
    m_rec.setTexture(&m_texture);
    m_rec.setPosition(sf::Vector2f(10, 10));
}