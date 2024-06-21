#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *NOME;
    int ID;
    char *DATA_NASCIMENTO;
    int *ID_FREGUESIA;
    struct Pessoa *proxima;
}PESSOA;

PESSOA *CriarPessoa(int _id, char *_nome,  char *_dataNascimento, int _idFreguesia);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);

#endif // PESSOA_H_INCLUDED
