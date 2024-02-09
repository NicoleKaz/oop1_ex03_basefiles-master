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

// ���� �����
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
        // ����� �� ��� ����
        sf::RectangleShape* tempCell = m_cell;
        char* tempChar = m_char;
        int tempSize = m_size;

        // ������ ���� �����
        m_size = other.m_size;
        m_cell = new sf::RectangleShape[m_size];
        m_char = new char[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_cell[i] = other.m_cell[i];
            m_char[i] = other.m_char[i];
        }

        // ����� ����� �����
        if (!m_cell || !m_char)
        {
            // ����� ����� ������ - ����� ������� ����� ���� �����
            delete[] m_cell;
            delete[] m_char;
            m_cell = tempCell;
            m_char = tempChar;
            m_size = tempSize;
        }
        else
        {
            // ��� ����� - ����� ������� ������
            delete[] tempCell;
            delete[] tempChar;
        }
    }
    return *this;
}

// ����� ���� ���� �����
void Row::push_back(const sf::RectangleShape& value) 
{
    sf::RectangleShape* newData = new sf::RectangleShape[m_size + 1];
    for (int i = 0; i < m_size; ++i) {
        newData[i] = m_cell[i];
    }
    newData[m_size] = value;
    delete[] m_cell;
    m_cell = newData;
    m_size++;
}

// ���� ��� ������ ����
const sf::RectangleShape& Row::at(int index) const
{
    return m_cell[index];
}

// ���� ��� ������ ����
const char Row::getChar(int index) const
{
    return m_char[index];
}

// ���� ��� ������ ����
void Row::writeOnIndex(int index, char obj)
{
    m_char[index] = obj;
}

// ���� ���� �����
int Row::getSize() const {
    return m_size;
}

// ����� ��� ����� ����
bool Row::isEmpty() const {
    return m_size == 0;
}

// �������� ������ �� �������
Row::~Row() {
    delete[] m_cell;
}

