#include <iostream>
using namespace std;
#define SIZE 60
#define DIFFICULTY 9
int numerate(int x, int y, char arrayMin[SIZE][SIZE]);
void mining(char arrayMin[SIZE][SIZE], int arrayNum [SIZE][SIZE]);
void drawNum(int array[SIZE][SIZE]);
void drawMin(char array[SIZE][SIZE]);

char mineChar = '*';
int main(){
	int arrayNum [SIZE][SIZE];
	char arrayMin [SIZE][SIZE];
	srand(time(NULL));
	mining(arrayMin, arrayNum);

	for(int x=1; x<SIZE; x++){
		for(int y=1; y<SIZE; y++){
			if(arrayMin[x][y] != mineChar)
				arrayNum[x][y] = numerate(x, y, arrayMin);
		}
	}

	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			if( arrayMin[x][y] != mineChar )
				if( arrayNum[x][y] == 0)
					cout << ". ";
				else
					cout << arrayNum[x][y] << " ";
			else
				cout << arrayMin[x][y] << " ";;
		}
	cout << endl;
	}

}


int numerate(int x, int y, char arrayMin[SIZE][SIZE]){
	int counter=0;
	if(arrayMin[x][y+1] == mineChar)
		counter++;
	if(arrayMin[x+1][y+1] == mineChar)
		counter++;
	if(arrayMin[x+1][y] == mineChar)
		counter++;
	if(arrayMin[x+1][y-1] == mineChar)
		counter++;
	if(arrayMin[x][y-1] == mineChar)
		counter++;
	if(arrayMin[x-1][y-1] == mineChar)
		counter++;
	if(arrayMin[x-1][y] == mineChar)
		counter++;
	if(arrayMin[x-1][y+1] == mineChar)
		counter++;

	return counter;
}

void mining(char arrayMin[SIZE][SIZE], int arrayNum [SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			arrayMin[i][j] = '.';
			arrayNum[i][j] = 0;
		}
	}
	int x, y;
	for(int i=0; i<SIZE*DIFFICULTY; i++){
		x = (rand() % (SIZE-3) ) +1;
		y = (rand() % (SIZE-3) ) +1;
		arrayMin[x][y] = mineChar;
	}
}
