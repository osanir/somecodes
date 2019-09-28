/*
Format:
./brtwl word1 word2 word3 ...
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    FILE *dosya;
    int num = argc-1, mod, holder;
    int array[num];
    double pow_num = pow(num, num);
    holder = num;
    dosya = fopen("wordlist.txt", "w");
    int i,j;
    for(j=0; j<pow_num; j++){
    printf("%d:\t", j);
    holder = j;
        for(i=0; i<num; i++){
            mod = holder % num;
            holder -= mod;
            array[i] = mod;
            holder = holder / num;
        }
        for(i=num-1; i>=0; i--){
            fprintf(dosya,"%s", argv[array[i]+1]);
            printf("%s", argv[array[i]+1]);
        }
    fprintf(dosya,"\n");
    printf("\n");
    }
    fclose(dosya);
    return 0;
}