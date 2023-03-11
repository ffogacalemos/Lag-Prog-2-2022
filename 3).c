#include <stdio.h>

int main(){
    int n, i, soma = 0;

    FILE *f, *s;

    f = fopen("entrada.dat", "rb");
    s = fopen("saida.dat","wb");

    if(f == NULL || s == NULL){
        printf("Ocorreu um erro ao abrir o arquivo\n");
        return 1;
    }
    for(i = 0; i<2; i++){
        fread(&n, sizeof(int), 1, f);
        soma += n;
    }

    fwrite(&soma, sizeof(int), i, s);

    fclose(f);
    fclose(s);
    return 0;
}
