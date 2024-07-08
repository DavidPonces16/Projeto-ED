#include "ListaLivro.h"

LISTA_LIVRO *CriarListaLivro() {
    LISTA_LIVRO *L = (LISTA_LIVRO *)malloc(sizeof(LISTA_LIVRO));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicioLivro(LISTA_LIVRO *L, LIVRO *X) {
    NO_LIVRO *novo = (NO_LIVRO *)malloc(sizeof(NO_LIVRO));
    novo->Info = X;
    novo->Prox = L->Inicio;
    L->Inicio = novo;
    L->NEL++;
}

void ShowListaLivro(LISTA_LIVRO *L) {
    NO_LIVRO *aux = L->Inicio;
    while (aux != NULL) {
        MostrarLivro(aux->Info);
        aux = aux->Prox;
    }
}

void DestruirListaLivro(LISTA_LIVRO *L) {
    NO_LIVRO *aux = L->Inicio;
    while (aux != NULL) {
        NO_LIVRO *temp = aux;
        aux = aux->Prox;
        DestruirLivro(temp->Info);
        free(temp);
    }
    free(L);
}

LIVRO *PesquisarListaLivro(LISTA_LIVRO *L, int id) {
    NO_LIVRO *aux = L->Inicio;
    while (aux != NULL) {
        if (aux->Info->ID == id) {
            return aux->Info;
        }
        aux = aux->Prox;
    }
    return NULL;
}

int SizeListaLivro(LISTA_LIVRO *L) {
    return L->NEL;
}
