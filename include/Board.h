#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Row.h"

enum texture { WALL = 0, DOOR, CAT, MOUSE, CHEESE, PRESENT, KEY, ERASE, RESET, SAVE, TOOL, SIZE };


class Board
{
public:
	//const sf::RectangleShape CreateRectangle(const int row, const int col) const;
	Board();
	void SetRow(const int row);
	void SetCol(const int col);
	const int getCol() const;
    const int getRow() const;
	void setSize();
	sf::RectangleShape& getMRec();
	void handleClickBoard(const sf::Vector2f& location, char& type, bool pressed);
	void initMatrix();
	void initWithGivenMatrix(std::ifstream& m_ifile);
	void findMouse();
	void drawBoard(sf::RenderWindow& m_window);
	enum texture { WALL = 0, DOOR, CAT, MOUSE, CHEESE, PRESENT, KEY, ERASE, RESET, SAVE, TOOL, SIZE };
	//sf::FloatRect getGlobalBounds()const { return .getGlobalBounds(); }
	void CreateFile(std::ofstream& m_ofile);
	void wasMouse();

private:
	int m_row;
	int m_col;
	std::vector< Row> m_matrixVector;
	sf::RectangleShape m_rec;
	sf::Texture m_textures[texture::SIZE]; // the board textures
	bool m_wasMouse = false;
};