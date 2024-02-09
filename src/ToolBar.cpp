#include "ToolBar.h"

void ToolBar::setSize(float row, float col)
{
	m_row = row;
	m_col = col;
}

void ToolBar::init()
{
	//toolbar position
	m_outline.setSize(sf::Vector2(285.f, 685.f));
	m_outline.setPosition(0.f,0.f);
	
	//Style
	m_outline.setOutlineColor(sf::Color::Color(0, 0, 0));
	m_outline.setOutlineThickness(4.f);
	m_outline.setFillColor(sf::Color::Color(0,0,0));

	//init index
	for (int index = 0; index < 10; ++index)
	{
		m_object[index]->init();
	}
}

void ToolBar::drawToolBar(sf::RenderWindow& m_window)
{
	m_window.draw(m_outline); // draw the rectangle
	for (int object = 0; object < 10; object++)
	{
		//sf::Vector2f location((row * m_outline.getSize().x), col * m_outline.getSize().y);
		m_window.draw(m_object[object]->GetRec());
	}
}