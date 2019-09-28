#include <iostream>
#include <fstream>

using namespace std;

enum Dir{
    right=1, left=2, up=4, down=8
};

struct Pos{
    int y, x;
};

struct Map{
    char board[12][12];
    int directions[12][12];

    
    void initBoard();
    void initDirections();
    void drawBoard();
    void loadMap();
    void traverse(Pos pos0, Pos pos1, Pos pos2);
};