#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10


typedef struct{
    char nome[50];
}TRegistro;

typedef struct{
    TRegistro item[max+1];
    int n;
}TTabela;

void inicializa(TTabela *t);
int pesquisa_seq(TTabela *t, char x[]);
void insere(TRegistro reg, TTabela *t);


int main(){

    int option=1;
    int i=0;
    TTabela fila;
    TRegistro x;

    inicializa(&fila);

    while(option == 1){
        printf("\n[%d] - Qual nome inserir na fila: ", i);
        fflush(stdin);
        fgets(x.nome, 50, stdin);
        insere(x, &fila);

        printf("\nInserir outro? '1' para sim | '2' para nao: ");
        scanf("%d", &option);
        i++;
    }

    printf("\n.... Pesquisa ....");
    printf("\n Qual nome pesquisar? ");
    fflush(stdin);
    fgets(x.nome, 50, stdin);
    int f = pesquisa_seq(&fila, x.nome);
    if(f == 0){
        printf("\n # NAO EXISTE ! #");
    }else{
        printf("\n # EXISTE ! ESTA NA POSICAO %d #", f);
    }

    return 0;
}


void inicializa(TTabela *t){
    t->n = 0;
}

int pesquisa_seq(TTabela *t, char x[]){
    int i;
    strcpy(t->item[0].nome, x);
    i = t->n;
    while( (strcmp(t->item[i].nome, x)) != 0 ){
        i--;
    }
    return i;
}

void insere(TRegistro reg, TTabela *t){
    if(t->n == max){
        printf("\nTABELA CHEIA\n");
    }else{
        t->n++;
        t->item[t->n]=reg;
    }
}
