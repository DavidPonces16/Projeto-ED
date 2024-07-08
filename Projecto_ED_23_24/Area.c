#include "Area.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

AREA *CriarArea(char *nome) {
    AREA *A = (AREA *)malloc(sizeof(AREA));
    A->NOME = strdup(nome);
    A->Livros = CriarListaLivro();
    A->Prox = NULL;
    return A;
}

void AdicionarLivroArea(AREA *A, LIVRO *L) {
    if (A) {
        AddInicioLivro(A->Livros, L);
    }
}

void MostrarLivrosPorArea(AREA *A) {
    if (A) {
        printf("Area: %s\n", A->NOME);
        ShowListaLivro(A->Livros);
    }
}

void DestruirArea(AREA *A) {
    if (A) {
        free(A->NOME);
        DestruirListaLivro(A->Livros);
        free(A);
    }
}
