#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pergunta {
    char nivel;
    char descricao[200];
    char alt[4][30];
    char alt_correta;
};

int sorteador(int);
void plateia(struct pergunta);
void universitarios(struct pergunta);
void cartas(struct pergunta);
char probabilidade(struct pergunta, int, int, int, int);

int main(){
    int n, i, j, contador = 0, n_pergunta = 0, v[18], sorteio, acerto, valido;
    int contador_p = 3, contador_ap = 3, contador_au = 3, contador_c = 3;
    float valor = 0;
    char opcao;

    struct pergunta perguntas;

    srand(time(0));

    FILE *f;
    f = fopen("perguntas.dat", "rb");

    if(f == NULL){
        printf("Erro ao abrir o arquivo de perguntas");
        return 1;
    }

    for(n = 0; n<3; n++){
        for(i = 0; i<5; i++){
            acerto = 0;
            printf("\n==------------\nPergunta %d\n==Voce possui um total acumulado de R$ %.2f", n_pergunta+1, valor);
            sorteio = sorteador(n);
            v[contador] = sorteio;
            for(j = 0; j < contador; j++){
                if(sorteio == v[j]){
                    sorteio = sorteador(n);
                    j = 0;
                }
            }
            contador++;
            n_pergunta++;

            fseek(f, sorteio*sizeof(struct pergunta), SEEK_SET);
            fread(&perguntas, sizeof(struct pergunta), 1, f);

            while(1){
                valido = 1;
                printf("\n%s\n", perguntas.descricao);
                printf("a) %s\n", perguntas.alt[0]);
                printf("b) %s\n", perguntas.alt[1]);
                printf("c) %s\n", perguntas.alt[2]);
                printf("d) %s\n", perguntas.alt[3]);

                printf("-- Ajuda --\n");
                printf("[1] Pular pergunta(%dx)\n", contador_p);
                printf("[2] Pedir ajuda a plateia(%dx)\n", contador_ap);
                printf("[3] Pedir ajuda aos universitario(%dx)\n", contador_au);
                printf("[4] Pedir ajuda as cartas(%dx)\n", contador_c);
                printf("[5] Parar\n");

                scanf(" %c", &opcao);

                if((contador_p <= 0) && opcao == '1')
                    valido = 0;

                if((contador_ap <= 0) && opcao == '2')
                    valido = 0;

                if((contador_au <= 0) && opcao == '3')
                    valido = 0;

                if((contador_c <= 0) && opcao == '4')
                    valido = 0;

                if(valido == 0)
                    printf("\nVoce ja usou todas estas ajudas, escolha outra opcao\n");
                if(valido == 1)
                    break;

            };

            switch(opcao){
                case 'a':
                    if(perguntas.alt_correta == 'a')
                        acerto = 1;
                    break;
                case 'b':
                    if(perguntas.alt_correta == 'b')
                        acerto = 1;
                    break;
                case 'c':
                    if(perguntas.alt_correta == 'c')
                        acerto = 1;
                    break;
                case 'd':
                    if(perguntas.alt_correta == 'd')
                        acerto = 1;
                    break;
                case '1':
                    i--;
                    contador_p --;
                    n_pergunta --;
                    printf("\nVoce pulou a pergunta\n");
                    break;
                case '2':
                    plateia(perguntas);
                    contador_ap--;

                    printf("\nSua resposta: ");
                    scanf(" %c", &opcao);

                    if(perguntas.alt_correta == opcao)
                        acerto = 1;

                    break;
                case '3':
                    universitarios(perguntas);
                    contador_au--;

                    printf("\nSua resposta: ");
                    scanf(" %c", &opcao);

                    if(perguntas.alt_correta == opcao)
                        acerto = 1;
                    break;
                case '4':
                    cartas(perguntas);
                    contador_c--;

                    printf("\nSua resposta: ");
                    scanf(" %c", &opcao);

                    if(perguntas.alt_correta == opcao)
                        acerto = 1;
                    break;
                default:
                    return 1;
            }

            if(acerto == 1 && opcao != '1'){
                if(n == 0)
                    valor+=1000;
                if(n == 1)
                    valor+=10000;
                if(n == 2)
                    valor+=100000;
            }
            else if (opcao != '1'){
                printf("Voce perdeu.");
                return 1;
            }
        }
        if(n_pergunta == 5)
            valor = 10000;
        if(n_pergunta == 10)
            valor = 100000;
    }

    acerto = 0;
    printf("\nUltima pergunta. A Pergunta final valendo tudo\n");
    printf("Valendo um milhao de reais.\n");
    sorteio = sorteador(3);

    fseek(f, sorteio*sizeof(struct pergunta), SEEK_SET);
    fread(&perguntas, sizeof(struct pergunta), 1, f);

    printf("\n%s\n", perguntas.descricao);
    printf("a) %s\n", perguntas.alt[0]);
    printf("b) %s\n", perguntas.alt[1]);
    printf("c) %s\n", perguntas.alt[2]);
    printf("d) %s\n", perguntas.alt[3]);

    printf("[1] Nao responder e levar R$500000\n");

    scanf(" %c", &opcao);

    switch(opcao){
        case 'a':
            if(perguntas.alt_correta == 'a')
                acerto = 1;
            break;
        case 'b':
            if(perguntas.alt_correta == 'b')
                acerto = 1;
            break;
        case 'c':
            if(perguntas.alt_correta == 'c')
                acerto = 1;
            break;
        case 'd':
            if(perguntas.alt_correta == 'd')
                acerto = 1;
            break;
        case '1':
            printf("voce sai com R$500000, mas desistiu do grande premio, valeu a pena?\n");
            break;
        }
        if(acerto == 1){
            printf("Parabens voce levou um milhao de reais!!!");
        }
        else{
            printf("Voce perdeu TUDO.");
            return 1;
    }
    return 0;
}

int sorteador(int n){
    int sorteio;

    switch(n){
        case 0:
            sorteio = (rand()%20);
            return sorteio;
        case 1:
            sorteio = (rand()%20)+20;
            return sorteio;
        case 2:
            sorteio = (rand()%20)+40;
            return sorteio;
        case 3:
            sorteio = (rand()%10)+60;
            return sorteio;
    }
}

void plateia(struct pergunta perguntas){
    int i;
    printf("\nPlateia:[");
    for(i = 0; i<30; i++){
        printf("%c", probabilidade(perguntas, 40, 60, 80,100));
        printf(" ");
    }
    printf("]\n");
}

void universitarios (struct pergunta perguntas){
    int i;
    printf("\nUniversitarios:[");
    for(i = 0; i<3; i++){
        printf("%c", probabilidade(perguntas,70, 80, 90, 100));
        printf(" ");
    }
    printf("]\n");
}

void cartas (struct pergunta perguntas){
    int sorteio, i, j;
    char a[3];
    sorteio = rand()%4;

    switch(sorteio){
        case 0:
            printf("\n Carta 0: nenhuma opcao excluida.\n");
            break;
        case 1:
            printf("\n Carta 1: Uma opcao excluida. \n");
            printf("\nA opcao excluida eh: ");
            printf("%c", probabilidade(perguntas, 0,4,8,12));
            break;
        case 2:
            printf("\n Carta 2: Duas opcoes excluidas.\n");
            printf("\nas opcao excluida sao: ");
            for(i = 0; i<2;i++){
                a[i] = probabilidade(perguntas, 0,4,8,12);
                for(j = 0; j<i; j++){
                    if(a[j] == a[i])
                        i--;
                }
            }
            for(i = 0; i<2; i++){
                printf("%c", a[i]);
                printf(" ");
            }
            printf("\n");
            break;
        case 3:
            printf("\n Carta 3: Tres opcoes exluidas. \n");
            printf("\nas opcao excluida sao: ");
            for(i = 0; i<3;i++){
                a[i] = probabilidade(perguntas, 0,4,8,12);
                for(j = 0; j<i; j++){
                    if(a[j] == a[i])
                        i--;
                }
            }
            for(i = 0; i<3; i++){
                printf("%c", a[i]);
                printf(" ");
            }
            printf("\n");
            break;
    }
}

char probabilidade(struct pergunta perguntas,int prob_correta, int prob_b, int prob_c, int peso_sorteio){
        int sorteio;
        sorteio = rand()%peso_sorteio+1;
        if(perguntas.alt_correta == 'a'){
            if(sorteio <= prob_correta)
                return 'a';
            if(sorteio > prob_correta && sorteio <= prob_b)
                return 'b';
            if(sorteio > prob_b && sorteio <= prob_c)
                return 'c';
            if(sorteio > prob_c && sorteio <= peso_sorteio)
                return 'd';
        }
        if(perguntas.alt_correta == 'b'){
            if(sorteio <= prob_correta)
               return 'b';
            if(sorteio > prob_correta && sorteio <= prob_b)
               return 'a';
            if(sorteio > prob_b && sorteio <= prob_c)
               return 'c';
            if(sorteio > prob_c && sorteio <= peso_sorteio)
               return 'd';
        }
        if(perguntas.alt_correta == 'c'){
            if(sorteio <= prob_correta)
               return 'c';
            if(sorteio > prob_correta && sorteio <= prob_b)
               return 'a';
            if(sorteio > prob_b && sorteio <= prob_c)
               return 'b';
            if(sorteio > prob_c && sorteio <= peso_sorteio)
               return 'd';
        }
        if(perguntas.alt_correta == 'd'){
            if(sorteio <= prob_correta)
               return 'd';
            if(sorteio > prob_correta && sorteio <= prob_b)
               return 'a';
            if(sorteio > prob_b && sorteio <= prob_c)
               return 'b';
            if(sorteio > prob_c && sorteio <= peso_sorteio)
               return 'c';
        }
}
