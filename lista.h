#ifndef LISTA_H
#define LISTA_H


#define MAX 100

typedef struct{
    int elementos[MAX];
    int qntdElementos;
}Lista;

Lista* criarLista();
int isFull(Lista lista);
int isEmpty(Lista lista);
void addElemento(Lista *lista, int elemento);
void exibirLista(Lista lista);
void exibirElementoByPosicao(Lista lista, int posicao);
void exibirPosicaoByElemento(Lista lista, int elemento);
void esvaziarLista(Lista *lista);
Lista* removerElemento(Lista *lista, int elemento);
Lista* addElementoByPosicao(Lista *lista, int posicao, int elemento);

#endif