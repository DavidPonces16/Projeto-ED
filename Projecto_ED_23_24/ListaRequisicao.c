#include "ListaRequisicao.h"

LISTA_REQUISICAO *CriarListaRequisicao() {
    LISTA_REQUISICAO *L = (LISTA_REQUISICAO *)malloc(sizeof(LISTA_REQUISICAO));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicioRequisicao(LISTA_REQUISICAO *L, REQUISICAO *X) {
    NO_REQUISICAO *novo = (NO_REQUISICAO *)malloc(sizeof(NO_REQUISICAO));
    novo->Info = X;
    novo->Prox = L->Inicio;
    L->Inicio = novo;
    L->NEL++;
}

void ShowListaRequisicao(LISTA_REQUISICAO *L) {
    NO_REQUISICAO *aux = L->Inicio;
    while (aux != NULL) {
        MostrarRequisicao(aux->Info);
        aux = aux->Prox;
    }
}

void DestruirListaRequisicao(LISTA_REQUISICAO *L) {
    NO_REQUISICAO *aux = L->Inicio;
    while (aux != NULL) {
        NO_REQUISICAO *temp = aux;
        aux = aux->Prox;
        DestruirRequisicao(temp->Info);
        free(temp);
    }
    free(L);
}

REQUISICAO *PesquisarListaRequisicao(LISTA_REQUISICAO *L, int id) {
    NO_REQUISICAO *aux = L->Inicio;
    while (aux != NULL) {
        if (aux->Info->ID == id) {
            return aux->Info;
        }
        aux = aux->Prox;
    }
    return NULL;
}

int SizeListaRequisicao(LISTA_REQUISICAO *L) {
    return L->NEL;
}
