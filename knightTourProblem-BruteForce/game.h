#include <iostream>
#include <list>

struct Position2i{
    int y, x;
};

class Game{
    public:
        Game();
        void initBoard();
        void drawBoard();
        void updateBoard(std::list<Position2i> moves);
        void traverse(Position2i pos);
        void delay();
        void printInfo();
    private:
        int moveCount;
        int highMoveCount;
        char board[10][10];
        Position2i startPos; // h1
        std::list<Position2i> moves;
        std::list<Position2i> highMoves;
        char empty = '.';
        char border = '#';
        char knight = 'K';
};