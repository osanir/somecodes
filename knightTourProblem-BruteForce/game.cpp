#include "game.h"

Game::Game(){
    moveCount = 0;
    highMoveCount = 0;
    startPos.x = 4; 
    startPos.y = 4;
}

void Game::initBoard(){
    for(int i=0; i<10; i++){
        board[i][0]     = border;
        board[0][i]     = border;
        board[9-i][9]   = border;
        board[9][9-i]   = border;
    }
    for(int i=1; i<9; i++)
        for( int j=1; j<9; j++)
            board[i][j] = empty;
}

void Game::drawBoard(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0; i<10; i++){
        printf("%d ", i);
        for(int j=0; j<10; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }    
}

void Game::updateBoard(std::list<Position2i> moves){
    for(int i=1; i<9; i++)
        for( int j=1; j<9; j++)
            board[i][j] = empty;

    std::list<Position2i>::iterator iter;
    iter = moves.begin();
    while( iter != moves.end() ){
        board[iter->y][iter->x] = knight;
        iter++;
    }
}

void Game::traverse(Position2i pos){
    moveCount++;
    moves.push_back(pos);
    updateBoard(moves);
   // delay();
    if( board[pos.y+2][pos.x+1] == empty)
        traverse({pos.y+2, pos.x+1});
    if( board[pos.y+2][pos.x-1] == empty)
        traverse({pos.y+2, pos.x-1});
    if( board[pos.y-2][pos.x+1] == empty)
        traverse({pos.y-2, pos.x+1});
    if( board[pos.y-2][pos.x-1] == empty)
        traverse({pos.y-2, pos.x-1});
    if( board[pos.y+1][pos.x+2] == empty)
        traverse({pos.y+1, pos.x+2});
    if( board[pos.y-1][pos.x+2] == empty)
        traverse({pos.y-1, pos.x+2});
    if( board[pos.y+1][pos.x-2] == empty)
        traverse({pos.y+1, pos.x-2});
    if( board[pos.y-1][pos.x-2] == empty)
        traverse({pos.y-1, pos.x-2});
    
    
    if( moveCount >= highMoveCount ){
        drawBoard();
        printInfo();
        highMoveCount = moveCount;
        std::list<Position2i>::iterator iter;
        iter = moves.begin();
        highMoves.clear();
        while( iter != moves.end() ){
            highMoves.push_back(*iter);
            iter++;
        }
    }
    
    if( moveCount == 64 || highMoveCount == 64)
        return;
    moves.pop_back();
    moveCount -= 1;
    
}

void Game::delay(){
    for(int i = 0; i<10000000; i++)
        for(int j = 0; j<1; j++);
}

void Game::printInfo(){
    printf("Move Count: %d, Highest Move: %d\n", moveCount, highMoveCount);
    printf("Start Position: %d,%d\n", moves.begin()->y, moves.begin()->x);
    std::list<Position2i>::iterator iter;
    iter = highMoves.begin();
    
    while( iter != highMoves.end() ){
        printf("[%d, %d] ", iter->y, iter->x);
        iter++;
    }
}