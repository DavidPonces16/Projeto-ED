#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct no_chave
{
    char *KEY; 
    LISTA *DADOS;
    struct no_chave *Prox;
}NO_CHAVE;

typedef struct
{
    int NEL;
    NO_CHAVE *Inicio;
}LISTA_CHAVES;

typedef struct
{
    LISTA_CHAVES *LChaves;
}HASHING;
//--------------------------------------------------------
//--------------------------------------------------------
//--------------------------------------------------------
HASHING *CriarHashing();
//--------------------------------------------------------
void DestruirHashing(HASHING *H);
//--------------------------------------------------------
void AddHashing(HASHING *H, char *P);
//--------------------------------------------------------
void ShowHashing(HASHING *H);
//--------------------------------------------------------
NO_CHAVE *FuncaoHashing(HASHING *H, PESSOA *X);
//--------------------------------------------------------
//--------------------------------------------------------
//--------------------------------------------------------

#endif // HASHING_H_INCLUDED
