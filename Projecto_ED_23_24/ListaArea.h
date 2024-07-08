#ifndef LISTA_AREA_H_INCLUDED
#define LISTA_AREA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Area.h"

typedef struct no_area {
    AREA *Info;
    struct no_area *Prox;
} NO_AREA;

typedef struct {
    int NEL;
    NO_AREA *Inicio;
} LISTA_AREA;

//--------------------------------------------------
LISTA_AREA *CriarListaArea();
//--------------------------------------------------
void AddInicioArea(LISTA_AREA *L, AREA *X);
//--------------------------------------------------
void ShowListaArea(LISTA_AREA *L);
//--------------------------------------------------
void DestruirListaArea(LISTA_AREA *L);
//--------------------------------------------------
AREA *PesquisarListaArea(LISTA_AREA *L, char *nome);
//--------------------------------------------------
int SizeListaArea(LISTA_AREA *L);
//--------------------------------------------------

#endif // LISTA_AREA_H_INCLUDED
