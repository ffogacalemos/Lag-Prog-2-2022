#include <stdio.h>
//3-4-5
void swap( int *, int *);
void print_addr(int *);
int main(){
    int a = 1, b = 2, c = 3, temp;
    int x = 3;
    temp = a;
    swap(&temp, &b);
    swap(&temp, &c);
    swap(&temp, &a);

    printf("%d, %d, %d\n", a,b,c);

    print_addr(&x);
}

void swap( int *p1, int *p2){
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void print_addr(int *x){
    printf("%d,%p", *x, x);
}
/*5 - Não é o esperado, caso passemos apenas o x como argumento, será impresso
 dentro da função o endereço da variavel local daquela função, caso passemos
 por referência então teremos a impressão do endereço da variavel dentro da main*/
