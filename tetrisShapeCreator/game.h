#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
using namespace std;

struct Vec2i{
    int y;
    int x;
};

class Game{
public:
    Game();
    void initGame(u_int8_t initSize);
    void clearBoard();
    void printBoard();

    void makeSelection(); // selecting node and direction to place new brick 
    bool placeToBoard();

    void createShape();
    
private:
    u_int8_t size;
    char board[50][50];
    vector<Vec2i> points;
    
    Vec2i    selNode;  // selected node
    u_int8_t selDir; // selected direction 0 right, 1 left, 2 up, 3 down  

    char chEmpty = ' ', chBrick = '#';
};