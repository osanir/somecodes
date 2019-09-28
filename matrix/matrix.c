#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand(time(NULL));
	int line = 100;	
	int column = 200;
	int one_zero=0;
	int count_line, count_column;
	int lenght;
	char opt = 'n';

	printf("Değerleri kendiniz belirlemek ister misiniz? (e/h)"
		"\nDo you want to determine the values? (y/n)");
	scanf("%c", &opt);

	if(opt != 'n' && opt != 'h'){
	    printf("\nSatır sayısını girin: "
		   "\nEnter the number of lines: ");
	    scanf("%d", &line);
	    printf("\nSütun sayısını girin: "
		   "\nEnter the number of columns: ");
	    scanf("%d", &column);
	}
	char array[line][column];

	for(count_column = 0; count_column < column; count_column++){
	    lenght = rand()% line -1;
	    for(count_line = 0; count_line < line; count_line++){
		one_zero = rand()%2;
		if(count_line <= lenght){
		    if(one_zero == 1)
			array[count_line][count_column] = '1';
		    else
			array[count_line][count_column] = '0';
		}
		else
		    array[count_line][count_column] = ' ';
	    }
	}

	for(count_line = 0; count_line < line; count_line++){
	    for(count_column = 0; count_column < column; count_column++){
		printf("%c", array[count_line][count_column]);
	    }
	printf("\n");
	}

}
