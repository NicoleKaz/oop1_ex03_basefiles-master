#include "ToolBar.h"

void ToolBar::setSize(float row, float col)
{
	m_row = row;
	m_col = col;
}

void ToolBar::init()
{
	//toolbar position
	m_outline.setSize(sf::Vector2(150.f, 150.f));
	m_outline.setPosition(0.f,0.f);
	
	//Style
	m_outline.setOutlineColor(sf::Color::Color(102, 102, 102));
	m_outline.setOutlineThickness(4.f);
	m_outline.setFillColor(sf::Color::Color(150, 150, 150));

	//init button
	/*for (int button = 0; button < 6; ++button)
	{
		m_botton[button]->init();
	}*/
}

void ToolBar::drawToolBar(sf::RenderWindow& m_window)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			sf::Vector2f location((row * m_outline.getSize().x), col * m_outline.getSize().y);
			m_window.draw(m_outline);
		}
	}
}