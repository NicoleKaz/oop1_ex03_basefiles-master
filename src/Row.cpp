#include "Row.h"

Row::Row()
{
}

Row::Row (int size, const sf::RectangleShape& value)
{
    m_size = size;
    m_char = new char[m_size];
	m_cell = new sf::RectangleShape[size]();
	for (int i = 0; i < m_size; i++)
	{
        auto startPosition = value.getPosition();
        auto cellsize = value.getSize();
        m_char[i] = ' ';
        m_cell[i] = value;
    }
}

// בנאי העתקה
Row::Row(const Row& other) : m_size(other.m_size)
{
    //delete m_char + m_cell;
    m_char = new char[m_size];
    m_cell = new sf::RectangleShape[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_cell[i] = other.m_cell[i];
        m_char[i] = other.m_char[i];
    }
}

Row& Row::operator=(const Row& other)
{
    if (this != &other)
    {
        // שמירה על מצב קודם
        sf::RectangleShape* tempCell = m_cell;
        char* tempChar = m_char;
        int tempSize = m_size;

        // ניסיון לבצע העתקה
        m_size = other.m_size;
        m_cell = new sf::RectangleShape[m_size];
        m_char = new char[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_cell[i] = other.m_cell[i];
            m_char[i] = other.m_char[i];
        }

        // בדיקת הצלחת העתקה
        if (!m_cell || !m_char)
        {
            // קיימת חריגת זיכרון - שחרור המשאבים וחזרה למצב הקודם
            delete[] m_cell;
            delete[] m_char;
            m_cell = tempCell;
            m_char = tempChar;
            m_size = tempSize;
        }
    }
    return *this;
}

// קבלת ערך במיקום נתון
const sf::RectangleShape& Row::at(int index) const
{
    return sf::RectangleShape(m_cell[index]);
}

sf::RectangleShape& Row::at(int index)
{
    return m_cell[index];
}

// קבלת ערך במיקום נתון
const char Row::getChar(int index) const
{
    return m_char[index];
}

void Row::setChar(int index, char type)
{
    m_char[index] = type;
}

// קבלת ערך במיקום נתון
void Row::writeOnIndex(int index, char obj)
{
    m_char[index] = obj;
}

// קבלת גודל השורה
int Row::getSize() const {
    return m_size;
}

// בדיקה האם השורה ריקה
bool Row::isEmpty() const {
    return m_size == 0;
}

// דסטרקטור לשחרור את הזיכרון
Row::~Row() {
    delete[] m_cell;
}

