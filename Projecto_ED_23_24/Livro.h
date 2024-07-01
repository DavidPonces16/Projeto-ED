#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *NOME;
    int ID;
    char *AREA;
    int ANO;
} LIVRO;

LIVRO *CriarLivro(int _id, char *_nome, char *_area, int _ano);
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);

#endif // LIVRO_H_INCLUDED
