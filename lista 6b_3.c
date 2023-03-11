#include <stdio.h>
#include <stdlib.h>

struct no {
    int chave;
    struct no *prox;
};

struct lista_ligada{
    struct no *cabeca;
};

void lista_inserir(struct lista_ligada *, struct no *);
void lista_inserir_e_construir(struct lista_ligada *, int);
int lista_remover(struct lista_ligada*);
void verificar(struct lista_ligada);


int ler_opcao();
void menu();

int main (int argc, char const *argv[])
{
	int opcao, n;
	struct lista_ligada l;
	l.cabeca = NULL;
	struct no *t;

	while (1) {
		menu();
		opcao = ler_opcao();

		switch(opcao) {
			case 1:
                printf("Digite o valor a inserir na fila: ");
                scanf("%d*c ", &n);
                lista_inserir_e_construir(&l, n);
                break;
			case 2:
                if(l.cabeca != NULL)
                    printf("foi removido: %d", lista_remover(&l));
                else
                    printf("\nFila vazia\n");
                break;

			case 3:
				verificar(l);
				break;
			case 9:
				printf("Finalizando programa ..");
				return 0;
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
// ENTRE OPCAO
//
// faz a leitura da opcao do usuario
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int ler_opcao() {
	int opcao;

	printf("\nEntre com a sua opcao: ");
	scanf("%d*c ", &opcao);

	return opcao;
}

//////////////////////////////////////////////////////////////////////////
// MENU
//
// funcao responsavel por imprimir o menu principal
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void menu() {
	printf("\n// ----- // ----- // MENU // ----- // ----- //\n"
		"[1] – Inserir elemento\n"
		"[2] – Remover elemento\n"
		"[3] – Verificar ser a fila esta vazia\n"
		"[9] - Finalizar\n"
		"~~~~~~~~~~~~~~~\n");
}
void lista_inserir(struct lista_ligada *l, struct no *novo){
    int i;

    struct no *n;
    n = l->cabeca;

    if(l->cabeca == NULL){
        l->cabeca = novo;
    }
    else{
        while(n->prox != NULL)
            n = n->prox;

        n->prox = novo;
    }
}
void lista_inserir_e_construir(struct lista_ligada *l, int k){
    struct no *novo;

    novo = (struct no *) malloc(sizeof(struct no));

    novo->chave = k;
    novo->prox = NULL;

    lista_inserir(l, novo);

}

int lista_remover(struct lista_ligada *l){
    int x;
    struct no *p;
    p = l->cabeca;

    if(p!=NULL){
        x = p->chave;
        l->cabeca = p->prox;
    }
    else{
        printf("\nFila vazia\n");
        return -1;
    }
    free(p);

    return x;
}


void verificar(struct lista_ligada l){
    struct no *p;
    p = l.cabeca;
    if(p == NULL){
        printf("Fila vazia\n");
    }
    else
        printf("Fila não vazia\n");
}

