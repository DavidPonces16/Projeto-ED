#include "Area.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

AREA *CriarArea(char *nome) {
    AREA *A = (AREA *)malloc(sizeof(AREA));
    A->NOME = strdup(nome);
    A->Livros = CriarLista();
    A->Prox = NULL;
    return A;
}

void AdicionarLivroArea(AREA *A, LIVRO *L) {
    if (A) {
        AddInicio(A->Livros, L);
    }
}

void MostrarLivrosPorArea(AREA *A) {
    if (A) {
        printf("Área: %s\n", A->NOME);
        ShowLista(A->Livros);
    }
}

void DestruirArea(AREA *A) {
    if (A) {
        free(A->NOME);
        DestruirLista(A->Livros);
        free(A);
    }
}
