#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int v[100], i, n;

    FILE *f, *q;

    f = fopen("seq.dat", "wb+");
    q = fopen("seq.txt", "w");

    srand(time(0));

    for(i = 0; i<100; i++){
        v[i] = (rand()%999 + 1);
        fprintf(q, "%d ", v[i]);
    }

    fwrite(&v, sizeof(int), 100, f);

    fseek(f, 2*sizeof(int), SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    printf("%d ", n);

    fseek(f, 9*sizeof(int), SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    printf("%d ", n);

    fseek(f, 49*sizeof(int), SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    printf("%d ", n);

    fseek(f, 98*sizeof(int), SEEK_SET);
    fread(&n, sizeof(int), 1, f);
    printf("%d ", n);

    fclose(f);
    fclose(q);
    return 0;
}
