#ifndef LISTA_LIVRO_H_INCLUDED
#define LISTA_LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Livro.h"

typedef struct no_livro
{
    LIVRO *Info;
    struct no_livro *Prox;
} NO_LIVRO;

typedef struct
{
    int NEL;
    NO_LIVRO *Inicio;
} LISTA_LIVRO;

//--------------------------------------------------
LISTA_LIVRO *CriarListaLivro();
//--------------------------------------------------
void AddInicioLivro(LISTA_LIVRO *L, LIVRO *X);
//--------------------------------------------------
void ShowListaLivro(LISTA_LIVRO *L);
//--------------------------------------------------
void DestruirListaLivro(LISTA_LIVRO *L);
//--------------------------------------------------
LIVRO *PesquisarListaLivro(LISTA_LIVRO *L, int id);
//--------------------------------------------------
int SizeListaLivro(LISTA_LIVRO *L);
//--------------------------------------------------

#endif // LISTA_LIVRO_H_INCLUDED
