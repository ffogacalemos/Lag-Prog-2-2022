/*1 - Um ponteiro possúi 8 bytes, no caso do codeblock ao perguntarmos o sizeof
ele diz 4 apesar*/

#include <stdio.h>
//2

int main(){
    int x, y, *p, *q;

    x = 2;
    y = 8;
    p = &x;
    q = &y;

    printf("%lu\n",sizeof(p));

    printf("%p: %d\n", x, x);
    printf("%d: %d\n", p, *p);
    printf("%p: %d\n", y, y);
    printf("%p\n", &p);

}

