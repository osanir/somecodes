#include <stdio.h>

void go(char lab[6][7], int *x, int *y);
int find(char lab[6][7], int x, int y);
void draw(char [6][7], int, int);

int  main(){
    int stack[4][2] = {{0,0}, {0,0}, {0,0}, {0,0}};
    char lab[6][7] = {{'#','#','#','#','#','#','#'},
                      {'#','.','#','.','.','#','.'},
                      {'#','.','.','.','.','#','#'},
                      {'#','#','.','#','.','#','#'},
                      {'#','#','.','#','.','.','.'},
                      {'#','#','#','#','#','#','#'}};
    int x = 1, y = 1, dir=0;    // dir gidilebilecek yön sayısı
    int *xptr = &x, *yptr = &y;


    lab[x][y] = 'O';
    printf("Labirent:\n");
    draw(lab, x, y);
    int i = 0;
    while(x != 5 && y != 6){
        dir = find(lab, x, y);  //gidilecek yönlerin sayısı tutulur
//        draw(lab, x, y);   // DEBUG: her adımda labirenti yazdır
//        printf("stack: %d %d i: %d\n\n", stack[i-1][0], stack[i-1][1], i);     // DEBUG: stackleri yazdır
        if(dir > 1){    // gidilebilecek yön 1 den fazla ise konum kaydedilir.
            stack[i][0] = x;
            stack[i][1] = y;
            i++;
        } else if(dir < 1){ // gidecek yön yoksa son kaydedilen yere dönülür.
            i--;
            x = stack[i][0];
            y = stack[i][1];
        }
        go(lab, xptr, yptr);
        lab[x][y] = 'O';

    }

    printf("\nÇözülmüş Labirent:\n");
    draw(lab, x, y);


}

// karakteri hareket ettirir
void go(char lab[6][7], int *x, int *y){

    if(lab[*x+1][*y] == '.')
        *x = *x + 1;
    else if(lab[*x][*y+1] == '.')
        *y = *y+1;
    else if(lab[*x-1][*y] == '.')
        *x = *x-1;
    else if(lab[*x][*y-1] == '.')
        *y = *y-1;
}

// gidilebilecek konumların sayısını bulur
int find(char lab[6][7], int x, int y){
    int dir=0, i;
    if(lab[x+1][y] == '.')
        dir++;
    if(lab[x][y+1] == '.')
        dir++;
    if(lab[x-1][y] == '.')
        dir++;
    if(lab[x][y-1] == '.')
        dir++;

    return dir;
}

// labirenti yazdırır
void draw(char lab[6][7], int x, int y){
    int i,j;
    for(i=0; i<6; i++){
        for(j=0; j<7; j++){
            printf("%c ", lab[i][j]);
        }
        printf("\n");
        //printf(" x: %d y: %d \n", x, y);  // DEBUG: konumları yazdır
    }
}
