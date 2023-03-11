#include <stdio.h>

struct no {
    int chave;
    struct no *prox;
};

struct lista_ligada{
    struct no *cabeca;
};

int main(){
    int i;

    i = sizeof(struct no);
    printf("%d ", i);

    return 0;
}

/*2 - O tamanho da lista ligada seria 800 bytes, no caso de um vetor
seria 400 bytes pois seriam 100 ints, o qual cada representado é por 4 bytes*/
