#include "../include/game.h"

void Game::initGame(){
    map.initBoard();
    map.loadMap();
    map.drawBoard();
    map.initDirections();

    //map.traverse({1,1},{1,2},{1,3});
}

void Game::showMenu(){
    cout << "Welcome to Pipe game!" << endl;
    cout << "1. Play" << endl;
    cout << "2. Help" << endl;
    cout << "0. EXIT" << endl;

    int ch;
    cin >> ch;
    switch (ch){
        case 1:
            initGame();
            break;
        case 2:
            help();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choose. Bye :)" << endl;
    }
}

void Game::help(){
    cout << "\n\nYou can use this char for create custom map:" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9 X S F" << endl;
    cout << "═ ║ ╠ ╣ ╦ ╩ ╔ ╗ ╚ ╝ ╬ » O (Note: \"»\" is Start and \"O\" is Finish)" << endl;
    cout << "Map should be 10x10 size!" << endl;
}
