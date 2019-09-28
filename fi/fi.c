#include <stdio.h>
void printer(int);
int main(){
    int num_pre = 1, num = 1, temp, counter = 0;
    printer(num%8);
    while(counter < 50){
        printf(" - ");
        printer(num%8);
        if(num > 1000 )
            num = num-800;
        temp = num;
        num = num + num_pre;
        num_pre = temp;
        counter++;
    }
    printf("\nCounter: %d\n", counter);
}
void printer(int a){
    switch (a){
        case 0: printf("Do"); break;
        case 1: printf("Re"); break;
        case 2: printf("Mi"); break;
        case 3: printf("Fa"); break;
        case 4: printf("Sol"); break;
        case 5: printf("La"); break;
        case 6: printf("Si"); break;
        case 7: printf("Do"); break;
        default : printf("Hoooooop!");
    }
}
