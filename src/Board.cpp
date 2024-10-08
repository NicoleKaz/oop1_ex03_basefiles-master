#include "Board.h"

Board::Board()
{
    m_row=0;
    m_col=0;
    m_rec.setSize({ 50, 50 });
    m_textures[WALL].loadFromFile("wall.png");
    m_textures[DOOR].loadFromFile("door.png");
    m_textures[CAT].loadFromFile("cat.png");
    m_textures[MOUSE].loadFromFile("mouse.png");
    m_textures[CHEESE].loadFromFile("cheese.png");
    m_textures[PRESENT].loadFromFile("present.png");
    m_textures[KEY].loadFromFile("key.png");
    m_textures[SAVE].loadFromFile("save.png");
    m_textures[RESET].loadFromFile("reset.png");
    m_textures[ERASE].loadFromFile("erase.png");
    //m_textures[TOOL].loadFromFile("tool.png");
}

void Board::initMatrix()
{
    Row temp_row(m_col);
	// initial the matrix with char ' ' to create empty board
	m_matrixVector.clear();
	//m_matrixVector.resize(m_row);
    for (int i = 0; i < m_row; i++) //�� ����� ���� ������ ������ ���� ����
	{
        m_matrixVector.push_back(temp_row); //����� ���� ����
	}
}


void Board::initWithGivenMatrix(std::ifstream &m_ifile)
{
	//m_ifile.get(); // for \n
	// Read the two integers from the file
	m_ifile >> m_row >> m_col;
	m_ifile.get(); // for \n //���� ���� ����� �� ������ ���� �� ��� ����� �� �������
	m_matrixVector.clear();
	m_matrixVector.resize(m_row);
	char c;
	
	for (auto& row : m_matrixVector)
	{
		Row temp_row(m_col);
		for (int col = 0; col < (m_col); col++)
		{
			m_ifile.get(c);
			temp_row.writeOnIndex(col, c);
		}
        m_ifile.get(c);
		row.operator= (temp_row);
	}
}

void  Board::findMouse()
{
    for (int row = 0; row < m_matrixVector.size(); ++row)
    {
        for (int col = 0; col < m_col; ++col)
        {
            if (m_matrixVector[row].getChar(col) == '%') // adding each char at the corrnt place
            {
                m_wasMouse = true;
                return;
            }
        }
    }
}

void Board::drawBoard(sf::RenderWindow &m_window)
{
    float offset = 300 ;
    int num_of_row = 0;
    for (int row = 0 ; row < m_matrixVector.size(); ++row)
    {
        for (int col = 0; col < m_col; ++col)
        {
            sf::Vector2f location((col * m_rec.getSize().x) + offset, num_of_row * m_rec.getSize().y );
            char type = m_matrixVector[row].getChar(col);
            m_rec.setTexture(NULL);
            m_rec.setFillColor(sf::Color::White);
            m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
            m_rec.setOutlineThickness(2.f);
            m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
            m_window.draw(m_rec);
            switch (type)
            {
            case '#':
            {
                m_rec.setTexture(&m_textures[0], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            } 
            case 'D':
            {
                m_rec.setTexture(&m_textures[1], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            }
            case '^':
            {
                m_rec.setTexture(&m_textures[2], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            }
            case '%':
            {
                m_rec.setTexture(&m_textures[3], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            }
            case '*':
            {
                m_rec.setTexture(&m_textures[4], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;;
            }
            case '$':
            {
                m_rec.setTexture(&m_textures[5], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            }
            case 'F':
            {
                m_rec.setTexture(&m_textures[6], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;
            }

            case ' ':
                //m_rec.setTexture(nullptr, true);
                m_rec.setTexture(NULL);
                m_rec.setFillColor(sf::Color::White);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);
                break;

            default:
                m_rec.setTexture(NULL);
                m_rec.setFillColor(sf::Color::White);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(2.f);
                m_rec.setPosition(location); //���� ������� ���� ��� ���� ���� �����.
                m_window.draw(m_rec);

                break;
            }
        }
        num_of_row++;
    }

}

void Board::CreateFile(std::ofstream& m_ofile)
{
    m_ofile.open("Board.txt"); //opening the file
    m_ofile << m_row<< " " << m_col<< '\n'; //adding the size of the board at the top

    for (int row = 0; row < m_matrixVector.size(); ++row)
    {
        for (int col = 0; col < m_col; ++col)
        {
            m_ofile << m_matrixVector[row].getChar(col); // adding each char at the corrnt place
        }
        m_ofile << '\n'; //endl
    }
}

void Board::wasMouse()
{
    m_wasMouse = false;
}

void Board::SetRow(const int row)
{
	m_row = row;
}

void Board::SetCol(const int col)
{
	m_col = col;
}
const int Board::getCol() const
{
	return m_col;
}

const int Board::getRow() const
{
	return m_row;
}

void Board::setSize()
{
	std::cout << "please enter row and col: ";
	std::cin >> m_row >> m_col;
    while (m_col > 18 || m_row > 20 || m_col < 1 || m_row < 1) // correct the size
    {
        std::cout << "the maximum c/r size is 1-18/1-20 please enter again col and row: ";
        std::cin >> m_col >> m_row;
    }
}

sf::RectangleShape& Board::getMRec()
{
	return m_rec;
}

void Board::handleClickBoard(const sf::Vector2f& location, char& type,bool pressed)
{
    float offset = 300;
    int row = location.y / m_rec.getSize().y;
    int col = (location.x - offset) / m_rec.getSize().x;

    if (row >= 0 && row < m_matrixVector.size() && col >= 0 && col < m_matrixVector[row].getSize())
    {
        if (type == '%' && !m_wasMouse)
        {
            m_matrixVector[row].setChar(col, type);
            m_wasMouse = true;
        }
        else if(type != '%')
        {
            if (m_matrixVector[row].getChar(col) == '%')
            {
                m_wasMouse = false;
            }
            m_matrixVector[row].setChar(col, type);
        }
    }
}


