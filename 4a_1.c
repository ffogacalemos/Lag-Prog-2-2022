#include <stdio.h>

int main(){
    int n;
    FILE *arq;
    arq = fopen("entrada.txt", "w");

    if(arq == NULL){
        printf("Ocorreu um erro.\n");
    }
    else{
        for(int i = 0; i<8; i++){
          scanf("%d", &n);
          fprintf(arq, "%d ", n);
        }
    }
    fclose(arq);
}
