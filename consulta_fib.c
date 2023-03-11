#include <stdio.h>

int main(){
    int n, i = 0, fib;
    FILE *arq;

    arq = fopen("30_fib.txt", "r");

    printf("Escreva um n entre 1 e 30: \n");
    scanf("%d*c", &n);

    while(i<n){
        fscanf(arq, "%d ", &fib);
        i++;
    }

    printf("%d ", fib);
}
