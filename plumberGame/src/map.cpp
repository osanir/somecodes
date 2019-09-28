#include "../include/map.h"

void Map::initBoard(){
    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++)
            board[i][j] = '.';

    board[0][0]   = '6';
    board[0][11]  = '7';
    board[11][0]  = '8';
    board[11][11] = '9';
    for(int i=1; i<11; i++)
        board[0][i] = '0';
    for(int i=1; i<11; i++)
        board[11][i] = '0';

    for(int i=1; i<11; i++)
        board[i][0] = '1';
    for(int i=1; i<11; i++)
        board[i][11] = '1';
}

void Map::drawBoard(){
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            switch( board[i][j] ){
                case '0':
                    cout << "═";
                    break;
                case '1':
                    cout << "║";
                    break;
                case '2':
                    cout << "╠";
                    break;
                case '3':
                    cout << "╣";
                    break;
                case '4':
                    cout << "╦";
                    break;
                case '5':
                    cout << "╩";
                    break;
                case '6':
                    cout << "╔";
                    break;
                case '7':
                    cout << "╗";
                    break;
                case '8':
                    cout << "╚";
                    break;
                case '9':
                    cout << "╝";
                    break;
                case 'X':
                    cout << "╬";
                    break;
                case 'S':
                    cout << "»";
                    break;
                case 'O':
                case 'F':
                    cout << "O";
                    break;
                default:
                    cout << board[i][j];
                    break; 
            }
        }
        cout << endl;        
    }
}

void load(char map[10][10], char board[10][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            board[i][j] = map[i][j];
        }
    }
}
void Map::loadMap(){
    
    ifstream fp("map.txt");

    char ch;
    int i=1, j=1;
    while ( fp >> ch ) {
        //cout << ch;
        if( j == 11){
            i++; j=1;
        }else{
            board[i][j] = ch;
        }
        j++;
    }
    
    fp.close();


}

void Map::traverse(Pos pos0, Pos pos1, Pos pos2){
    if( directions[pos1.y][pos1.x] == 16){
        cout << "Succesfully planted!" << endl;
        return;
    }
    if( directions[pos2.y][pos2.x] == 16){
        cout << "Succesfully planted!" << endl;
        return;
    }
    
    if( (directions[pos1.y][pos1.x] & Dir::right) != 0){
        pos2.y = pos1.y;
        pos2.x = pos1.x+1;
        if( !((pos0.x == pos2.x) && (pos0.y == pos2.y)) ){
            cout << "right var" << endl;
            traverse(pos1, pos2, pos2);
        }
    }
    
    if( (directions[pos1.y][pos1.x] & Dir::left) != 0){
        pos2.y = pos1.y;
        pos2.x = pos1.x-1;
        if( !((pos0.x == pos2.x) && (pos0.y == pos2.y)) ){
            cout << "left var" << endl;
            traverse(pos1, pos2, pos2);        
        }

    }
    
    if( (directions[pos1.y][pos1.x] & Dir::up) != 0){
        pos2.y = pos1.y-1;
        pos2.x = pos1.x;
        if( !((pos0.x == pos2.x) && (pos0.y == pos2.y)) ){
            cout << "up var" << endl;
            traverse(pos1, pos2, pos2);        
        }
    }
    
    if( (directions[pos1.y][pos1.x] & Dir::down) != 0){
        pos2.y = pos1.y+1;
        pos2.x = pos1.x;
        if( !((pos0.x == pos2.x) && (pos0.y == pos2.y)) ){
            cout << "down var" << endl;        
            traverse(pos1, pos2, pos2);        
        }
    }

}

void Map::initDirections(){
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            switch( board[i][j] ){
                case '0':
                    directions[i][j] = Dir::left | Dir::right;
                    break;
                case '1':
                    directions[i][j] = Dir::up | Dir::down;
                    break;
                case '2':
                    directions[i][j] = Dir::up | Dir::down | Dir::right;
                    break;
                case '3':
                    directions[i][j] = Dir::up | Dir::down | Dir::left;
                    break;
                case '4':
                    directions[i][j] = Dir::left | Dir::right | Dir::down;
                    break;
                case '5':
                    directions[i][j] = Dir::left | Dir::right | Dir::up;
                    break;
                case '6':
                    directions[i][j] = Dir::right | Dir::down;
                    break;
                case '7':
                    directions[i][j] = Dir::left | Dir::down;
                    break;
                case '8':
                    directions[i][j] = Dir::right | Dir::up ;
                    break;
                case '9':
                    directions[i][j] = Dir::left | Dir::up;
                    break;
                case 'X':
                    directions[i][j] = Dir::left | Dir::right | Dir::up | Dir::down;
                    break;
                case 'S':
                    directions[i][j] = Dir::left | Dir::right | Dir::up | Dir::down;
                    break;
                case 'O':
                case 'F':
                    directions[i][j] = 16;
                    break;
                case '.':
                    directions[i][j] = 0;
                    break;                    
                default:
                    cout << board[i][j];
                    break; 
            }
        }
    }
    
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++)
            printf("%3d", directions[i][j]);
        cout << endl;
    }
    
}