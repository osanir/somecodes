#include <iostream>
#include <cstdlib>
#include "game.h"
using namespace std;

int main(int argc, char** argv){
    if( argc < 2 ) return 0;
    Game game;
    int size = atoi( argv[1] );
    int iteration = 1;
   
    if( argc == 3) 
        iteration = atoi( argv[2] );
    
    for(int i=0; i<iteration; i++){
        game.initGame(size);
        game.createShape();
        game.printBoard();
    }
}