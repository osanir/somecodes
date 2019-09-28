#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char board[11][17] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',}
};

int main (){
	srand(time(NULL));
	int zar;
	int x = 1, y = 1;
	int i, j;
	char ch;
	char up = '+', rgt = '+', lft = '+', dwn = '+';
	while(1){
		if(board[x+1][y]!=' ' && board[x-1][y]!=' ' && board[x][y+1]!=' ' && board[x][y-1]!=' ')
			break;
		scanf("%c", &ch);
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		if(ch == 'w' && board[x-1][y] == ' '){
			board[x][y] = up;
			x -= 1;
		} else
		if(ch == 'a' && board[x][y-1] == ' '){
			board[x][y] = lft;
			y -= 1;
		} else
		if(ch == 's' && board[x+1][y] == ' '){
			board[x][y] = dwn;
			x += 1;
		} else
		if(ch == 'd' && board[x][y+1] == ' '){
			board[x][y] = rgt;
			y += 1;
		} else
		printf("Tekrar dene\n");

		board[x][y] = 'o';

		//zar = rand()%6+1;
		//printf("%d\n", zar);
		for(i=0; i<11; i++){
			for(j=0; j<17; j++)
			printf("%c", board[i][j]);
			printf("\n");
		}
	}

	printf("\n\nOyun bitti!\n");

}
