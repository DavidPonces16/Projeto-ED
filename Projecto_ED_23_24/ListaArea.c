#include "ListaArea.h"

LISTA_AREA *CriarListaArea() {
    LISTA_AREA *L = (LISTA_AREA *)malloc(sizeof(LISTA_AREA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicioArea(LISTA_AREA *L, AREA *X) {
    NO_AREA *novo = (NO_AREA *)malloc(sizeof(NO_AREA));
    novo->Info = X;
    novo->Prox = L->Inicio;
    L->Inicio = novo;
    L->NEL++;
}

void ShowListaArea(LISTA_AREA *L) {
    NO_AREA *aux = L->Inicio;
    while (aux != NULL) {
        MostrarLivrosPorArea(aux->Info);
        aux = aux->Prox;
    }
}

void DestruirListaArea(LISTA_AREA *L) {
    NO_AREA *aux = L->Inicio;
    while (aux != NULL) {
        NO_AREA *temp = aux;
        aux = aux->Prox;
        DestruirArea(temp->Info);
        free(temp);
    }
    free(L);
}

AREA *PesquisarListaArea(LISTA_AREA *L, char *nome) {
    NO_AREA *aux = L->Inicio;
    while (aux != NULL) {
        if (strcmp(aux->Info->NOME, nome) == 0) {
            return aux->Info;
        }
        aux = aux->Prox;
    }
    return NULL;
}

int SizeListaArea(LISTA_AREA *L) {
    return L->NEL;
}
