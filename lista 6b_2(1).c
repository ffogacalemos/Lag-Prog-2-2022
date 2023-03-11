#include <stdio.h>
#include <stdlib.h>
#define MAXFILA 10


struct fila {
    int itens[MAXFILA];
    int inicio, final;
};

void enfileirar (struct fila *, int);
int desenfileirar (struct fila *);
int esta_vazia(struct fila);
void inicializar(struct fila *);

int main(){
    int n, j;
    struct fila q;

    inicializar(&q);

    while(1){
        printf("\nEscreva a opção desejada\n");
        printf("[1] - Enfileirar\n[2] - Desenfileirar\n[3] - Checar se esta vazia\n[0] Sair\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("\nEscreva o numero a adicionar: ");
                scanf("%d", &j);
                enfileirar(&q,j);
                break;
            case 2:
                printf("\nNumero desenfileirado: %d", desenfileirar(&q));
                break;
            case 3:
                if(esta_vazia(q))
                    printf("\nEsta vazia");
                else
                    printf("\nNao esta vazia");
                break;
            case 0:
                return -1;
        }

    }

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


void inicializar(struct fila *q){
    q->inicio = -1;
    q->final = 0;
}

