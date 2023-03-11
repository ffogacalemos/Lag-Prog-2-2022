#include <stdio.h>

int main(){
    int n, i;

    FILE *f;

    f = fopen("saida.dat", "rb");

    if(f == NULL){
        printf("Ocorreu um erro ao abrir o arquivo\n");
        return 1;
    }

    fread(&n, sizeof(int), 1, f);
    printf("%d", n);


    return 0;
}
