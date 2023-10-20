#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista* criarLista(){
    Lista *newLista = (Lista*)malloc(sizeof(Lista));

    if(newLista == NULL) {
        printf("Erro na alocacao da memoria");
        exit(1);
    }
    newLista->qntdElementos = 0;

    return newLista;
}

int isFull(Lista lista) {
    return (lista.qntdElementos == MAX);
}

int isEmpty(Lista lista) {
    return (lista.qntdElementos == 0);
}

void addElemento(Lista *lista, int elemento) {
    if (isFull(*lista)) {
        printf("ERRO - LISTA CHEIA!");
    } else {
        lista->elementos[lista->qntdElementos] = elemento;
        lista->qntdElementos++;
    }
}

void exibirLista(Lista lista) {
    if (isEmpty(lista)) {
        printf("Lista VAZIA!");
    } else {
        for (int i = 0; i < lista.qntdElementos; i++) {
            printf("%d ", lista.elementos[i]);
        }
    }
    printf("\n");
}

void exibirElementoByPosicao(Lista lista, int posicao) {
    if (lista.qntdElementos < posicao) {
        printf("Erro - posicao invalida");
    } else {
        printf("%d", lista.elementos[posicao]);
    }
    printf("\n");
}

void exibirPosicaoByElemento(Lista lista, int elemento) {
    int possui = 0;
    for (int i = 0; i < lista.qntdElementos; i++) {
        if (lista.elementos[i] == elemento) {
            printf("%d", i);
            possui++;
            break;
        }
    }
    if (!possui) {
        printf("Erro - a lista nao possui o elemento");
    }
    printf("\n");
}

void esvaziarLista(Lista *lista) {
    free(lista);
    
    lista = criarLista();
}

Lista* removerElemento(Lista *lista, int elemento) {
    if (isEmpty(*lista)) {
        return lista;
    }

    int possui = 0;
    Lista *temp = criarLista();

    for(int i = 0; i < lista->qntdElementos; i++) {
        if(lista->elementos[i] != elemento) {
            addElemento(temp, lista->elementos[i]);
        } else {
            possui = 1;
        }
    }
    if (!possui) {
        free(temp);
        return lista;
    }
    free(lista);
    return temp;
}

Lista* addElementoByPosicao(Lista *lista, int posicao, int elemento) {
    if (isFull(*lista) || posicao < 0 || posicao > lista->qntdElementos) {
        return lista;
    }
    
    Lista *temp = criarLista();

    for(int i = 0; i < lista->qntdElementos + 1; i++) {
        if ((i == posicao)) {
            addElemento(temp, elemento);
        }
        if(i < lista->qntdElementos) {
            addElemento(temp, lista->elementos[i]);
        }
    }
    free(lista);
    return temp;
}