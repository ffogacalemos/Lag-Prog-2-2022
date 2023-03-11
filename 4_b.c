#include <stdio.h>

int main(){
    int n, fib = 0;
    FILE *f;

    f = fopen("seq30_fib.dat", "rb");

    printf("Digite um numero entre 1 e 30: ");
    scanf("%d", &n);


    fseek(f, (n-1)*sizeof(int), SEEK_SET);
    fread(&fib, sizeof(int), 1, f);

    printf("%d", fib);

    fclose(f);
    return 0;
}
