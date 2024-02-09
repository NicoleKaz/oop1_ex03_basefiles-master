#pragma once

#include "GameObject.h"


//---------------Wall GameObject-----------------
void Wall::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("wall.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(0,0));
}

const sf::RectangleShape Wall::GetRec()const
{
	return m_rec;
}

const char Wall::GetChar()const
{
	return m_type;
}

//---------------Door GameObject-----------------
void Door::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("door.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(0, 140));
}

const sf::RectangleShape Door::GetRec()const
{
	return m_rec;
}

const char Door::GetChar()const
{
	return m_type;
}

//---------------Cat GameObject-----------------
void Cat::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("Cat.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(0, 280));
}

const sf::RectangleShape Cat::GetRec()const
{
	return m_rec;
}

const char Cat::GetChar()const
{
	return m_type;
}

//---------------Mouse GameObject-----------------
void Mouse::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("Mouse.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(0, 420));
}

const sf::RectangleShape Mouse::GetRec()const
{
	return m_rec;
}

const char Mouse::GetChar()const
{
	return m_type;
}


//---------------Cheese GameObject-----------------
void Cheese::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("cheese.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(0, 560));
}

const sf::RectangleShape Cheese::GetRec()const
{
	return m_rec;
}

const char Cheese::GetChar()const
{
	return m_type;
}

//---------------Present GameObject-----------------
void Present::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("present.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(140, 0));
}

const sf::RectangleShape Present::GetRec()const
{
	return m_rec;
}

const char Present::GetChar()const
{
	return m_type;
}


//---------------Key GameObject-----------------
void Key::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("key.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(140, 140));
}

const sf::RectangleShape Key::GetRec()const
{
	return m_rec;
}

const char Key::GetChar()const
{
	return m_type;
}

//---------------Eraze GameObject-----------------
void Erase::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("erase.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(140, 280));
}

const sf::RectangleShape Erase::GetRec()const
{
	return m_rec;
}

const char Erase::GetChar()const
{
	return m_type;
}


//---------------Reset GameObject-----------------
void Reset::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("reset.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(140, 420));
}

const sf::RectangleShape Reset::GetRec()const
{
	return m_rec;
}

const char Reset::GetChar()const
{
	return m_type;
}

//---------------Save GameObject-----------------
void Save::init()
{
	m_rec.setSize(sf::Vector2f(140.f, 140.f));
	m_texture.loadFromFile("save.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(140, 560));
}

const sf::RectangleShape Save::GetRec()const
{
	return m_rec;
}

const char Save::GetChar()const
{
	return m_type;
}

//---------------Tool----------------
void Tool::init()
{
	m_rec.setSize(sf::Vector2f(280.f, 280.f));
	m_texture.loadFromFile("tool.png");
	m_rec.setTexture(&m_texture);
	m_rec.setPosition(sf::Vector2f(560, 560));
}

const sf::RectangleShape Tool::GetRec()const
{
	return m_rec;
}

const char Tool::GetChar()const
{
	return m_type;
}
