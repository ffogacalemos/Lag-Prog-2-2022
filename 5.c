#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main(){
    int v[6], v2[6], i, j, k, ganhou = 1;
    FILE *f, *q;

    f = fopen("seq.txt", "wr+");
    q = fopen("sorteio.txt", "r");

    if(f == NULL || q == NULL){
        printf("Houve um erro\n");
        return 1;
    }


    srand(time(0));
    for(k = 0; k<10000; k++){

        for(i = 0; i<6; i++){
            v[i] = (rand()%60 + 1);

            for(j = 0; j<i; j++)
                if(v[i] == v[j])
                    v[i] = (rand()%60 + 1);
                    j = 0;
        }

        qsort(v,6, sizeof(int), cmpfunc);

        for(i = 0; i<6; i++){
            fprintf(f,"%d ", v[i]);
        }
        fprintf(f, "\n");
    }

    for(i = 0; i<6; i++)
        fscanf(q, "%d", &v2[i]);

    while(!feof(f)){
        for(i = 0; i<6; i++){
            fscanf(f, "%d ", &v[i]);
            if(v[i] != v2[i]){
                ganhou = 0;
            }
        }
    }

    if(ganhou == 1)
        printf("\nVENCEDOR");
    else
        printf("\nNao foi dessa vez");
    fclose(f);
    fclose(q);

    return 0;
}
