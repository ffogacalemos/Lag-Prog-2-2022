#include <stdio.h>
#include <stdlib.h>
#define MAXFILA 6


struct fila {
    int itens[MAXFILA];
    int inicio, final;
};

void enfileirar (struct fila *, int);
int desenfileirar (struct fila *);
int esta_vazia(struct fila);
int primeiro (struct fila);
int ultimo(struct fila);
void inicializar(struct fila *);
void imprimir(struct fila);

int main(){
    struct fila q;

    inicializar(&q);

    enfileirar(&q,33);
    imprimir(q);

    enfileirar(&q, 7);
    imprimir(q);

    enfileirar (&q, 11);
    imprimir(q);

    desenfileirar(&q);
    imprimir(q);

    desenfileirar (&q);
    imprimir(q);

    enfileirar(&q, 2);
    imprimir(q);

    return 0;
}

void enfileirar (struct fila *q, int x){
    q->itens[q->final] = x;

    if(q->inicio == -1)
        q->inicio = 0;

    q->final += 1;

    if(q->final == MAXFILA)
        q->final = 0;

}

int desenfileirar (struct fila *q){
    int x;

    if(esta_vazia(*q)){
        printf(stderr, "\nUnderflow!");
        return -1;
    }

    x = q->itens[q->inicio];

    q->inicio += 1;

    if(q->inicio == MAXFILA)
        q->inicio = 0;

    return x;
}

int esta_vazia(struct fila q){
    return q.inicio == q.final;
}

int primeiro (struct fila q){
    int x;

    if(esta_vazia(q)){
        printf(stderr, "Stack underflow!");
        return -1;
    }

    return q.itens[q.inicio];
}

int ultimo(struct fila q){
    int i;

    i = q.final -1;

    if(i == -1)
        i = MAXFILA -1;

    return q.itens[i];
}

void imprimir(struct fila q){
    int i = q.inicio;

    for(i; i<q.final; i++)
        printf(" %d", q.itens[i]);

    printf("\n");
}

void inicializar(struct fila *q){
    q->inicio = -1;
    q->final = 0;
}
