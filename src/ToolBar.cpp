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
	m_outline.setFillColor(sf::Color::Color(255, 255, 255));


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

const sf::RectangleShape ToolBar::getButton(const int object)
{
	//returns button rectangle
	return m_object[object]->GetRec();
}



char ToolBar::handleClickToolBar(const sf::Vector2f& location,bool pressed)
{
	char type;
	for (int index = 0; index < 10; index++)
	{
		if (m_object[index]->GetRec().getGlobalBounds().contains(location))
		{
			type = m_object[index]->GetChar();
			pressed = true;
			return type;
		}
	}
	return type;
}





const char ToolBar::GetButtonChar(const int object)
{
	//returns the type
	return m_object[object]->GetChar();
}
const sf::RectangleShape ToolBar::getToolBar()
{
	//returns toolbar rectangle
	return m_outline;
}


