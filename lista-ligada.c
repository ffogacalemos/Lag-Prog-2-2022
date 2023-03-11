#include <stdio.h>
#include <stdlib.h>

struct no {
    int chave;
    struct no *prox;
    struct no *ant;
};

struct lista_ligada{
    struct no *cabeca;
};

void lista_inserir_e_construir(struct lista_ligada *, int);
void lista_inserir(struct lista_ligada* , struct no*);
void lista_remover(struct lista_ligada* , int);
struct no* lista_buscar(struct lista_ligada, int);
void verificar(struct lista_ligada);
void imprimir(struct lista_ligada);

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
			case 1: {
                printf("Digite o valor a inserir: ");
                scanf("%d*c ", &n);
                lista_inserir_e_construir(&l, n);
			}
			break;

			// opcao 2
			case 2: {
			    printf("Digite o elemento a ser removido: ");
			    scanf("%d*c ", &n),
			    lista_remover(&l, n);
			}
			break;

			// opcao 3
			case 3: {
			    printf("digite o elemento a ser buscado: ");
			    scanf("%d*c ", &n);
                t = lista_buscar(l, n);
			    printf("%d ", t->chave);
			}
			break;

			// opcao 4
			case 4: {
				verificar(l);
			}
			break;

			// opcao 5
			case 5: {
				imprimir(l);
			}
			break;

			// opcao 9
			case 9: {
				printf("Finalizando programa ..");
				return 0;
			}
			break;
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
		"[3] – Buscar elemento\n"
		"[4] – Verificar ser a lista esta vazia\n"
		"[5] – Imprimir elementos da lista\n"
		"[9] - Finalizar\n"
		"~~~~~~~~~~~~~~~\n");
}
void lista_inserir(struct lista_ligada *l, struct no *novo){
    struct no *ant = NULL, *p = l->cabeca;

    while(p != NULL && p->chave < novo->chave){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){
        novo->prox = l->cabeca;
        novo->ant = NULL;
        l->cabeca = novo;
    }

    else{
        ant->prox = novo;
        novo->ant = ant;
        novo->prox = p;
    }
}
void lista_inserir_e_construir(struct lista_ligada *l, int k){
    struct no *novo;

    novo = (struct no *) malloc(sizeof(struct no));

    novo->chave = k;
    novo->prox = NULL;
    novo->ant = NULL;

    lista_inserir(l, novo);
}

void lista_remover(struct lista_ligada *l, int k){
    struct no *ant = NULL, *p = l->cabeca;

    while(p!= NULL && p->chave != k){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        printf("Elemento nao encontrado\n");
    }
    else if(ant == NULL){
        l->cabeca = l->cabeca->prox;
    }
    else
        ant->prox = p->prox;

    free(p);
}

struct no* lista_buscar(struct lista_ligada l, int k){
    struct no *p;

    p = l.cabeca;
    while(p!= NULL && p->chave !=k){
        p = p->prox;
    }
    return p;
};

void verificar(struct lista_ligada l){
    struct no *p;
    p = l.cabeca;
    if(p == NULL){
        printf("Lista vazia\n");
    }
    else
        printf("Lista não vazia\n");
}

void imprimir(struct lista_ligada l){
    struct no *p;

    p = l.cabeca;

    while(p!= NULL){
        printf("%d ", p->chave);
        p = p->prox;
    }
}
