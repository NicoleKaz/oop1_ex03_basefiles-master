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
    m_textures[TOOL].loadFromFile("tool.png");

}
void Board::initMatrix()
{
    Row temp_row(m_col);
	// initial the matrix with char ' ' to create empty board
	m_matrixVector.clear();
	//m_matrixVector.resize(m_row);
    for (int i = 0; i < m_row; i++) //קח מצביע לתוך הוקטור ותעבור שורה שורה
	{
        m_matrixVector.push_back(temp_row); //יצירת שורה ריקה
	}
}

void Board::initWithGivenMatrix(std::ifstream &m_ifile)
{
	m_ifile.get(); // for \n
	// Read the two integers from the file
	m_ifile >> m_row >> m_col;
	m_ifile.get(); // for \n //אולי תהיה בעייה עם הירדית שורה על מנת לקרוא את הנתונים
	m_matrixVector.clear();
	m_matrixVector.resize(m_row);
	char c;
	
	for (auto& row : m_matrixVector)
	{
		Row temp_row(m_col);
		for (int col = 0; col < m_col; col++)
		{
			m_ifile.get(c);
			temp_row.writeOnIndex(col, c);
		}
		row.operator= (temp_row);
	}
}

void Board::drawBoard(sf::RenderWindow &m_window)
{
    float offset = 300 ;
    int num_of_row = 0;
    for (int row = 0 ; row < m_matrixVector.size(); row++)
    {
        for (int col = 0; col < m_col; ++col)
        {
            sf::Vector2f location((col * m_rec.getSize().x) + offset, num_of_row * m_rec.getSize().y);
            char type = m_matrixVector[row].getChar(col);
            switch (type)
            {
            case '#':
            {
                m_rec.setTexture(&m_textures[0], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case 'D':
            {
                m_rec.setTexture(&m_textures[1], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '^':
            {
                m_rec.setTexture(&m_textures[2], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '%':
            {
                m_rec.setTexture(&m_textures[3], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '*':
            {
                m_rec.setTexture(&m_textures[4], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;;
            }
            case '$':
            {
                m_rec.setTexture(&m_textures[5], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case 'F':
            {
                m_rec.setTexture(&m_textures[6], true);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }

            case ' ':
                m_rec.setFillColor(sf::Color::Black);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;

            default:
                m_rec.setFillColor(sf::Color::Black);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);

                break;
            }
        }
        num_of_row++;
    }

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
}

sf::RectangleShape& Board::getMRec()
{
	return m_rec;
}


