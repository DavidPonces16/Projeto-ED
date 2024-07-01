#include "Livro.h"

LIVRO *CriarLivro(int _id, char *_nome, char *_area, int _ano)
{
    LIVRO *P = (LIVRO *)malloc(sizeof(LIVRO));
    P->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(P->NOME, _nome);
    P->AREA = (char *)malloc((strlen(_area) + 1) * sizeof(char));
    strcpy(P->AREA, _area);
    P->ID = _id;
    P->ANO = _ano;
    return P;
}

void MostrarLivro(LIVRO *P)
{
    printf("\tLIVRO: ID: %d [%s] [%s] Ano: %d\n", P->ID, P->NOME, P->AREA, P->ANO);
}

void DestruirLivro(LIVRO *P)
{
    free(P->NOME);
    free(P->AREA);
    free(P);
}
