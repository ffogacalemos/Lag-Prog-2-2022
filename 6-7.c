#include <stdio.h>
//6
void ref(int *, int *);
int valor(int );
int main(){
    int n, soma = 0;

    printf("Digite um n: ");
    scanf("%d", &n);

    printf("%d\n", valor(n));
    ref(&n, &soma);
    printf("%d\n", soma);
}

void ref(int *n, int *soma){
    while(*n>0){
        *soma = *soma +*n;
        *n -= 1;
    }
}

int valor(int n){
    int soma = 0;
    while(n>0){
        soma = soma + n;
        n -= 1;
    }
    return soma;
}
/*7 - Primeiramente falamos que utilizaremos um ponteiro v, após na segunda
 linha você esta alocando memória o suficiente para 10 ints para o ponteiro
 v*/
