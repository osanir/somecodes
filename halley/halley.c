#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bekle (int);

int main(int argc, char *argv[]){
    int i,j,c,d;
    int space = 10;
    int chs = 1;
    int sayac=1;
    int sn;
    if(argc == 2)
	sn = atoi(argv[1]);
    else
	sn = 50;

    srand(time(NULL));
    while(1){
	chs = rand()%3;
	if(chs == 1 && space<2000)
	    space++;
	else if (chs == 0 && space > 0)
	    space--;
	else
	    space = space;
	for(i=1; i<space; i++){
	        printf(" ");
	}
    printf("*\t\t\n");
    sayac++;
   bekle(sn);
    }
}

void bekle(int sn){
	int c,d;
	for (c=1; c<= 32767; c++)
		for (d=1; d<=13050/sn; d++)
		{}
}
