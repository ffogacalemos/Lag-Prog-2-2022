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
/*5 - N�o � o esperado, caso passemos apenas o x como argumento, ser� impresso
 dentro da fun��o o endere�o da variavel local daquela fun��o, caso passemos
 por refer�ncia ent�o teremos a impress�o do endere�o da variavel dentro da main*/
