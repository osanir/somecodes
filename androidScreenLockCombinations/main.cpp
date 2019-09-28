#include <iostream>
#include <fstream>
using namespace std;

void fill();

struct dots{
	int dir[8] = {0,0,0,0,0,0,0,0};
}dot[9];

int main(){
	fill();
	int path[9] = {0,0,0,0,0,0,0,0,0};

	traverse(1, path)

}

void traverse( int x, int path[9] ){
	for( int i=0; i<8; i++){
		if( dot[x].dir[i] == 0)

		for(int j=0; j<9; j++){
			path[j] == dot[x].dir[i]
		}
	}
}

void fill(){
	int num;
	ifstream file;
	file.open("size");

	while( !file.eof() ){
		for(int i=0; i<9; i++){
			for(int j=0; j<8; j++){
				file >> num;
				dot[i].dir[j] = num;
			}
		}
		break;
	}

	file.close();

}


/*
for(int i=0; i<9; i++){
	for(int j=0; j<8; j++){
		cout << dot[i].dir[j]  << " ";
	}
	cout << endl;
}

o	o	o

o	o	o

o	o	o


1:	2,4,5,6,8
2:	1,3,4,5,6,7,9
3:	2,4,5,6,8
4:	1,2,3,5,7,8,9
5:	1,2,3,4,6,7,8,9
6:	1,2,3,5,7,8,9
7:	2,4,5,6,8
8:	1,3,4,5,6,7,9
9:	2,4,5,6,8

1,3,7,9 :	2,4,5,6,8
2,8		:	1,3,4,5,6,7,9
4,6		:	1,2,3,5,7,8,9
5		:	1,2,3,4,6,7,8,9
*/
