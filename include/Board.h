#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Row.h"


class Board
{
public:
	//const sf::RectangleShape CreateRectangle(const int row, const int col) const;
	void SetRow(const int row);
	void SetCol(const int col);
	const int getCol() const;
    const int getRow() const;
	void setSize();
	sf::RectangleShape& getMRec();
	Board();
	void initMatrix();
	void initWithGivenMatrix(std::ifstream& m_ifile);
	void drawBoard(sf::RenderWindow& m_window);
	//void drawToolBar(sf::RenderWindow& window);
	enum texture { WALL = 0, DOOR, CAT, MOUSE, CHEESE, PRESENT, KEY, ERASE, RESET, SAVE,SIZE};

private:
	int m_row;
	int m_col;
	std::vector< Row> m_matrixVector;
	sf::RectangleShape m_rec;
	sf::Texture m_textures[texture::SIZE]; // the board textures
};