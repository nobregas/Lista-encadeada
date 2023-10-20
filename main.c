#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void exibirInterface() {
    printf("Editor de lista\n");
    printf("--------------------------------------------------\n");
    printf("1 - Exibir Lista\n");
    printf("2 - Inserir\n");
    printf("3 - Remover\n");
    printf("4 - Exibir elemento\n");
    printf("5 - Exibir posicao\n");
    printf("6 - Esvaziar lista\n");
    printf("7 - Inserir na posicao\n");
    printf("8 - Sair\n\n");
    printf("Digite a opcao: ");
}

int main(void) {

    Lista *lista = criarLista();
    
    while (1) {
        system("cls");
        int opcao;
        
        exibirInterface();
        scanf("%d", &opcao);

        if (opcao == 8) {
            break;
        }

        system("cls");
        switch (opcao) {
            case 1:
                exibirLista(*lista);
                system("pause");
                break;
            
            case 2:
                int elemento_add;
                printf("Digite o elemento a ser adicionado: ");
                scanf("%d", &elemento_add);
                addElemento(lista, elemento_add);
                break;
            
            case 3:
                int elemento_remover;
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento_remover);
                lista = removerElemento(lista, elemento_remover);
                break;

            case 4:
                int posicao;
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                exibirElementoByPosicao(*lista, posicao);
                system("pause");
                break;
            
            case 5:
                int elemento_exibir_posicao;
                printf("Digite o elemento a ser exibido: ");
                scanf("%d", &elemento_exibir_posicao);
                exibirPosicaoByElemento(*lista, elemento_exibir_posicao);
                system("pause");
                break;

            case 6:
                int remover;
                printf("Digite 1 se deseja esvaziar a lista, 0 se nao: ");
                scanf("%d", &remover);
                
                if (remover == 1) {
                    esvaziarLista(lista);
                }
                break;

            case 7:
                int posicao_add, elemento_pos_add;
                printf("Digite a posicao em que o elemento deve ser adicionado: ");
                scanf("%d", &posicao_add);
                printf("Digite o elemento que deve ser adicionado: ");
                scanf("%d", &elemento_pos_add);

                lista = addElementoByPosicao(lista, posicao_add, elemento_pos_add);
                break;
        }

    }

    free(lista);

    return 0;
}

