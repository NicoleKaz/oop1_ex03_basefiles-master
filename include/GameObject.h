#pragma once

#include <SFML/Graphics.hpp>


//-----------abstruct GameObject class-----------------

class GameObject
{
public:
	virtual void init() = 0;
	virtual const sf::RectangleShape GetRec()const = 0;
	virtual const char GetChar()const = 0;

private:

};


//---------------Wall GameObject-----------------

class Wall: public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = '#';
	sf::Texture m_texture;
};

//---------------Door GameObject-----------------

class Door : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 'D';
	sf::Texture m_texture;
};

//---------------Cat GameObject-----------------

class Cat : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = '^';
	sf::Texture m_texture;
};

//---------------Mouse GameObject-----------------

class Mouse : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = '%';
	sf::Texture m_texture;
};

//---------------Cookie GameObject-----------------

class Cheese : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = '*';
	sf::Texture m_texture;
};

//---------------Present GameObject-----------------

class Present : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = '$';
	sf::Texture m_texture;
};

//---------------Key GameObject-----------------

class Key : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 'F';
	sf::Texture m_texture;
};

//---------------Eraze GameObject-----------------

class Erase : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 'E';
	sf::Texture m_texture;
};

//---------------Reset GameObject-----------------

class Reset : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 'R';
	sf::Texture m_texture;
};

//---------------Save GameObject-----------------

class Save : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 'S';
	sf::Texture m_texture;
};
//---------------Tool-----------------

class Tool : public GameObject
{
public:
	void init();
	const sf::RectangleShape GetRec()const;
	const char GetChar()const;

private:
	sf::RectangleShape m_rec;
	char m_type = 't';
	sf::Texture m_texture;
};











