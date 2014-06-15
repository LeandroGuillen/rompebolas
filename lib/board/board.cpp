#include "board.h"

#include <ctime>
#include <cstdlib>

Board::Board(int size, QObject *parent) :
    QObject(parent)
{
    this->setScore(0);
    this->setColors(5);
    this->setSize(size);
    this->setSelected(0);
}

void Board::generateRandom()
{
    // Random seed
    std::srand((unsigned)std::time(0));

    for(int i = 0; i < _size; i++)
    {
        for(int j = 0; j < _size; j++)
        {
            _matrix[i][j] = (std::rand() % _colors) + 1;
        }
    }
}

