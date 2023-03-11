#include <stdio.h>

int main(){
    int n, i;

    FILE *f;

    f = fopen("entrada.dat", "wb");

    if(f == NULL){
        printf("Ocorreu um erro ao abrir o arquivo\n");
        return 1;
    }
    for(i = 0; i<2; i++){
        scanf("%d", &n);
        fwrite(&n, sizeof(int), 1, f);
    }


    return 0;
}
//O binario não é possível interpretar, para se ter uma ideia de interpretação
//se digitar 65 que é o Binario para A e abrir o bloco de notas é o que aparece
