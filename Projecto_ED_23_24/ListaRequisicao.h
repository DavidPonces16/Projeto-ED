#ifndef LISTA_REQUISICAO_H_INCLUDED
#define LISTA_REQUISICAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Requisicao.h"

typedef struct no_requisicao
{
    REQUISICAO *Info;
    struct no_requisicao *Prox;
} NO_REQUISICAO;

typedef struct
{
    int NEL;
    NO_REQUISICAO *Inicio;
} LISTA_REQUISICAO;

//--------------------------------------------------
LISTA_REQUISICAO *CriarListaRequisicao();
//--------------------------------------------------
void AddInicioRequisicao(LISTA_REQUISICAO *L, REQUISICAO *X);
//--------------------------------------------------
void ShowListaRequisicao(LISTA_REQUISICAO *L);
//--------------------------------------------------
void DestruirListaRequisicao(LISTA_REQUISICAO *L);
//--------------------------------------------------
REQUISICAO *PesquisarListaRequisicao(LISTA_REQUISICAO *L, int id);
//--------------------------------------------------
int SizeListaRequisicao(LISTA_REQUISICAO *L);
//--------------------------------------------------

#endif // LISTA_REQUISICAO_H_INCLUDED
