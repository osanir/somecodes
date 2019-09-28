#include "game.h"

Game::Game( ){
    size = 5;    
    srand(time(NULL));        
}

void Game::initGame(u_int8_t initSize){
    points.clear();
    size = initSize;
    clearBoard();
    points.clear();
    points.push_back({size/2,size/2});
    board[size/2][size/2] = chBrick;
}

void Game::clearBoard(){
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            board[y][x] = chEmpty;
        }
    }
}

void Game::printBoard(){
    //cout << string(100,'\n');    
    for(int i = 0; i<size+4; i++)
        cout << ".";
    cout << endl;

    for(int y=0; y<size; y++){
        cout << ". ";            
        for(int x=0; x<size; x++){
            cout << board[y][x];
        }
        cout << " ." << endl;    
    }
    for(int i = 0; i<size+4; i++)
        cout << ".";
    cout << endl;    
    
}

void Game::makeSelection(){
    Vec2i *selectedNode;
    selectedNode = &points[ rand()%points.size() ];
    selNode.x = (*selectedNode).x;
    selNode.y = (*selectedNode).y;
    selDir  = rand()%4;
}

bool Game::placeToBoard(){
    switch (selDir){
        case 0:         // right
            if( board[ selNode.y ][ selNode.x+1 ] == chEmpty ){
                board[ selNode.y ][ selNode.x+1 ] = chBrick;
                points.push_back( {selNode.y, selNode.x+1} );
                return 1;
            }
            break;
        case 1:         // left
            if( board[ selNode.y ][ selNode.x-1 ] == chEmpty ){
                board[ selNode.y ][ selNode.x-1 ] = chBrick;
                points.push_back( {selNode.y, selNode.x-1} );
                return 1;
            }
            break;
        case 2:         // up
            if( board[ selNode.y-1 ][ selNode.x ] == chEmpty ){
                board[ selNode.y-1 ][ selNode.x ] = chBrick;
                points.push_back( {selNode.y-1, selNode.x} );
                return 1;
            }
            break;
        case 3:         // down
            if( board[ selNode.y+1 ][ selNode.x ] == chEmpty ){
                board[ selNode.y+1 ][ selNode.x ] = chBrick;
                points.push_back( {selNode.y+1, selNode.x} );
                return 1;
            }
            break;
        default:
            break;
    }

    return 0;
}

void Game::createShape(){

    for(int i=0; i<size-1; i++){
        makeSelection();
        if( placeToBoard() == 0 ) i--;     
    
    }
}
