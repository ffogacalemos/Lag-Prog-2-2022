#include <stdio.h>

int main(){
    int n1 = 1, soma = 0, temp;
    FILE *arq;

    arq = fopen("30_fib.txt", "w");
    if(arq == NULL){
        printf("Ocorreu um erro\n");
    }
    else{
        for(int i = 0; i < 30; i++){
            fprintf(arq, "%d ", soma);
            temp = soma;
            soma += n1;
            n1 = temp;
        }
    }

    fclose(arq);
}
