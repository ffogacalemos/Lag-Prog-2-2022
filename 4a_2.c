#include <stdio.h>

int main(){
    int soma = 0, n, n1;

    FILE *arq, *arq_2;

    arq = fopen("entrada.txt", "r");
    if(arq == NULL){
        printf("Ocorreu um erro\n");
        return 1;
    }

    arq_2 = fopen("saida.txt", "w");
    if(arq_2 == NULL){
        printf("Ocorreu um erro\n");
        return 1;
    }

    fscanf(arq, "%d %d", &n, &n1);
    soma = n + n1;
    fprintf(arq_2, "%d ", soma);


    fclose(arq);
    fclose(arq_2);
}
