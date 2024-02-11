#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Row
{
public:
	Row();
	Row(int, const sf::RectangleShape& value = sf::RectangleShape({ 50.f, 50.f }));
	Row(const Row& other);
	Row& operator=(const Row& other);
	void push_back(const sf::RectangleShape& value);
	const char getChar(int index) const;
	void setChar(int index, char type);
	void writeOnIndex(int index, char obj);
	const sf::RectangleShape& at(int index) const;
	sf::RectangleShape& at(int index);
	int getSize() const;
	bool isEmpty() const;
	~Row();

private:
	sf::RectangleShape* m_cell;
	sf::RectangleShape m_cellBoard;
	int m_size;
	char* m_char;
};

