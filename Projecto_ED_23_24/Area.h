#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED

#include "Lista.h"
#include "Livro.h"

typedef struct area {
    char *NOME;
    LISTA *Livros;
    struct area *Prox;
} AREA;

AREA *CriarArea(char *nome);
void AdicionarLivroArea(AREA *A, LIVRO *L);
void MostrarLivrosPorArea(AREA *A);
void DestruirArea(AREA *A);
#endif // AREA_H_INCLUDED
