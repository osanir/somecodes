#include <iostream>
using namespace std;

void connectNodes();
void printNodes();

struct node{
	int value;
	node *right;
	node *left;
	node *up;
	node *down;
}spaces[9];
node *iter = &spaces[5];

int main(){
	connectNodes();


	// value assignment (1 and 0)
	for(int i=0; i<9; i++)
	 	spaces[i].value = 0;
	spaces[5].value = 1;

	// values assignment (2-9)
	int currentValue=1;
	for(int i=2; i<=9; i++){
		switch ( choose ) {
			case 1:
				currentValue = iter->right->down->value;
				break;
			case 2:
				currentValue = iter->up->right->value;
				break;
			case 3:
				currentValue = iter->left->up->value;
				break;
			case 4:
				currentValue = iter->down->left->value;
				break;
		}

		if( iter->right->down->value == 0)
			iter = iter->right->down;
		else
			iter = iter->left;
		iter->value = i;
	}

	printNodes();
}

void printNodes(){
	for(int i=0; i<9; i++){
		cout << spaces[i].value << " ";
		if( ((i+1)%3) == 0)
			cout << endl;
	}
}
void connectNodes(){
	// 1
	spaces[0].right = &spaces[1];
	spaces[0].left	= &spaces[2];
	spaces[0].up	= &spaces[6];
	spaces[0].down	= &spaces[3];

	// 2
	spaces[1].right = &spaces[2];
	spaces[1].left	= &spaces[0];
	spaces[1].up	= &spaces[7];
	spaces[1].down	= &spaces[4];

	// 3
	spaces[2].right = &spaces[0];
	spaces[2].left	= &spaces[1];
	spaces[2].up	= &spaces[8];
	spaces[2].down	= &spaces[5];

	// 4
	spaces[3].right = &spaces[4];
	spaces[3].left	= &spaces[5];
	spaces[3].up	= &spaces[0];
	spaces[3].down	= &spaces[6];

	// 5
	spaces[4].right = &spaces[5];
	spaces[4].left	= &spaces[3];
	spaces[4].up	= &spaces[1];
	spaces[4].down	= &spaces[7];

	// 6
	spaces[5].right = &spaces[3];
	spaces[5].left	= &spaces[4];
	spaces[5].up	= &spaces[2];
	spaces[5].down	= &spaces[8];

	// 7
	spaces[6].right = &spaces[7];
	spaces[6].left	= &spaces[8];
	spaces[6].up	= &spaces[3];
	spaces[6].down	= &spaces[0];

	// 8
	spaces[7].right = &spaces[8];
	spaces[7].left	= &spaces[6];
	spaces[7].up	= &spaces[4];
	spaces[7].down	= &spaces[1];

	// 9
	spaces[8].right = &spaces[6];
	spaces[8].left	= &spaces[7];
	spaces[8].up	= &spaces[5];
	spaces[8].down	= &spaces[2];
}
int patternVal(int x){
	switch (x) {
		case 1:
			return iter->right->down->value;
		case 2:
			return iter->up->right->value;
		case 3:
			return iter->left->up->value;
		case 4:
			return iter->down->left->value;
	}
}

void patternNode(){
		switch (x) {
			case /* value */:
		}
}
