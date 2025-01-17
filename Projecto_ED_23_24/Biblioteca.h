#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Livro.h"
#include "Lista.h"
#include"ListaRequisicao.h"
#include "ListaLivro.h"
#include "ListaArea.h"
#include "Hashing.h"
#include "Pessoa.h"
#include "Requisicao.h"
#include "Area.h"
typedef struct biblioteca {
    char *NOME;
    char *FICHEIRO_LOGS;
    LISTA_LIVRO *HLivros; 
    LISTA_REQUISICAO *LRequisicoes; 
    LISTA *LRequisitantes; 
} BIBLIOTECA;

void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
int LoadLivrosBiblioteca(BIBLIOTECA *B);
int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod);
char *SobrenomeMaisComum(BIBLIOTECA *B);
LISTA *CarregarFreguesiasValidas();
int AddRequisicaoBiblioteca(BIBLIOTECA *B, REQUISICAO *R);
#endif // BIBLIOTECA_H_INCLUDED
