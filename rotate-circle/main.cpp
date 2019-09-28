#include <iostream>
#define SIZE 22

using namespace std;

void plane_draw(char plane[SIZE][SIZE]);
void plane_clear(char plane[SIZE][SIZE]);
void pl_fill_line(char plane[SIZE][SIZE]);
void pl_fill_parabola(char plane[SIZE][SIZE]);
void pl_fill_circle(char plane[SIZE][SIZE]);
void pl_fill_elips(char plane[SIZE][SIZE], int, int, int, int);

int main(){
    char plane[SIZE][SIZE];
    int selection = 0;
    int flag = 0, i=5;
    int flag2= 1, j=0;
    while (1){
        if(i == -5 || i == 5) flag = 1 - flag;
        if(flag == 0 && i++);
        if(flag == 1 && i--);

        if(j == -7 || j == 7) flag2 = 1 - flag2;
        if(flag2 == 0 && j++);
        if(flag2 == 1 && j--);



        plane_clear(plane);
        pl_fill_elips(plane, i, j, 0, 0);
        plane_draw(plane);
        
        for(int j=0; j<1000000; j++)
            for(int k=0; k<50; k++)
        ;
    }
/*
    printf("which shape would like to draw?\n"
            " 1. Line\n 2. Parabola\n 3. Circle\n 4. Elips\n 5. Exit\n");
    scanf("%d", &selection);
    switch (selection) {
        case 1 :
            pl_fill_line(plane);
            plane_draw(plane);
            break;
        case 2 :
             pl_fill_parabola(plane);
             plane_draw(plane);
            break;
        case 3 :
             pl_fill_circle(plane);
             plane_draw(plane);
            break;
        case 4 :
             pl_fill_elips(plane);
             plane_draw(plane);
            break;
        case 5 :
            return 0;
        default:
            printf("Invalid selection!"); return 0;
    }
*/
    //printf("Val a: %d\n Val b: %d\n Val c: %d\n Radius: %d\n", val_a, val_b, val_c, radius);
    //printf("Selection: %d\n", selection);

}


void pl_fill_line(char plane[SIZE][SIZE]){
    float a, b;
    printf("Line formula is y = ax + b\n"
            "Please enter coefficients a and b: ");
    scanf("%f%f", &a, &b);
    int x, y;
    for(x=-10; x<10; x++){
        y = a*x+b;
        if(y<=10 && y >= -10){
            plane[10-y][10+x] = '*';
        }
    }
}

void pl_fill_parabola(char plane[SIZE][SIZE]){
    float a, b, c;
    printf("Parabola formula is y = ax^2 + bx + c\n"
            "Please enter coefficients a, b and c:\n");
    scanf("%f%f%f", &a, &b, &c);
    int x, y;
    for(x=-10; x<10; x++){
        y = a*x*x + b*x + c;
        if(y<=10 && y >= -10){
            plane[10-y][10+x] = '*';
        }
    }
}

void pl_fill_circle(char plane[SIZE][SIZE]){
    int a, b, radius;
    printf("Circle formula is (x-a)^2 + (y-b)^2 = r^2\n"
        "Please enter center's coordinates (a,b) and radius:\n");
    scanf("%d%d%d", &a, &b, &radius);
    int x, y;
    for (y = -10; y < 10; y++) {
        for (x = -10; x < 10; x++) {
    	    if (radius*radius == (x-a)*(x-a) + (y-b)*(y-b)) {
    	        plane[10-y][10+x] = '*';
    	    }
	    }
    }
}

void pl_fill_elips(char plane[SIZE][SIZE], int a, int b, int h, int k){
    //int a, b, h, k;
 //   printf("Elip formula is xxxx\n"
 //       "Please enter center's coordinates (a,b) and (h,k):\n");
    //scanf("%d%d%d%d", &a, &b, &h, &k);
    int x, y;
    for (y = -10; y < 10; y++) {
        for (x = -10; x < 10; x++) {
            if(a==0 || b==0)
                return;
    	    if ( ( ( ( (x-h) * (x-h) ) / (a*a) ) + ( (y-k) * (y-k) ) / (b*b) ) == 1) {
    	        plane[10-y][10+x] = '*';
    	    }
	    }
    }
}

void plane_draw(char plane[SIZE][SIZE]){
    int i,j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            printf("%c ", plane[i][j]);
        }
        printf("\n");
    }
}

void plane_clear(char plane[SIZE][SIZE]){
    int i,j;
    for(i=0; i<22;i++){
        for(j=0; j<22;j++){

            if(i==10){
                plane[i][j]='-';
            }
            else if(j==10){
                plane[i][j]='|';
            }
            else
                plane[i][j]=' ';

        }

    }
    plane[0][10]='y';
    plane[10][21]='x';
    plane[10][10]='o';
}