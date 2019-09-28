#include <iostream>
#include "game.h"

int main(){
    Game game;
    game.initBoard();
    game.drawBoard();
    game.traverse( {1, 3} );
    for(int y=1; y<9; y++)
        for(int x=1; x<9; x++)
            game.traverse( {y, x} );
}