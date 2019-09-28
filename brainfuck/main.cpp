#include <iostream>
#include <fstream>
#include <list>
using namespace std;


int main(){
    char array[128] = {0};
    char *ptr = array;

    ifstream file;
    file.open("hello.bf");

    char ch;
    char *ptrPos;
    list<long> positions;
///*
    while ( !file.eof() ) {
        file >> noskipws >> ch;
        switch (ch){
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++*ptr;
                break;
            case '-':
                --*ptr;
                break;
            case '.':
                cout << *ptr;
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if( (positions.front() != file.tellg() ) )
                   positions.push_front( (file.tellg()) );
                break;
            case ']':
                if( *ptr != 0 )
                    file.seekg(positions.front(), file.beg);
                else
                    positions.pop_front();               
                break;
            default:
                break;
        }
    }
//*/
    file.close();
}