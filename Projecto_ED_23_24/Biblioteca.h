#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Livro.h"
#include "Lista.h"
#include "Hashing.h"
#include "Pessoa.h"
#include "Requisicao.h"
typedef struct biblioteca {
    char *NOME;
    char *FICHEIRO_LOGS;
    LIVRO **HLivros; 
    LISTA *LRequisicoes; 
    LISTA *LRequisitantes; 
} BIBLIOTECA;

void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
//char *AreaMaisComum(BIBLIOTECA *B);
//int AddRequisitante(BIBLIOTECA *B, PESSOA *X);
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod);
char *SobrenomeMaisComum(BIBLIOTECA *B);
LISTA *CarregarFreguesiasValidas();
#endif // BIBLIOTECA_H_INCLUDED
