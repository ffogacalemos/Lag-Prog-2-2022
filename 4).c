#include <stdio.h>

int main(){
    int n1 = 1, soma = 0, temp;
    FILE *arq;

    arq = fopen("seq30_fib.dat", "wb");
    if(arq == NULL){
        printf("Ocorreu um erro\n");
        return 1;
    }
    else{
        for(int i = 0; i < 30; i++){
            fwrite(&soma, sizeof(int), 1, arq);
            temp = soma;
            soma += n1;
            n1 = temp;
        }
    }

    fclose(arq);
}
