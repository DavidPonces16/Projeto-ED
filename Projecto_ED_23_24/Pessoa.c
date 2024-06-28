

#include "Pessoa.h"

/** \brief Permite Alocar e inicializar uma estrutura Pessoa
 *
 * \param _id int
 * \param _nome char*
 * \param _dataNascimento date*
 * \param _idFreguesia int*
 * \return PESSOA*
 *
 */

PESSOA *CriarPessoa(int _id, char *_nome, char *_dataNascimento, int _idFreguesia) {
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    if (P == NULL) {
        fprintf(stderr, "Erro ao alocar memória para PESSOA\n");
        return NULL;
    }

    P->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    if (P->NOME == NULL) {
        fprintf(stderr, "Erro ao alocar memória para NOME\n");
        free(P);
        return NULL;
    }
    strcpy(P->NOME, _nome);

    P->DATA_NASCIMENTO = (char *)malloc((strlen(_dataNascimento) + 1) * sizeof(char));
    if (P->DATA_NASCIMENTO == NULL) {
        fprintf(stderr, "Erro ao alocar memória para DATA_NASCIMENTO\n");
        free(P->NOME);
        free(P);
        return NULL;
    }
    strcpy(P->DATA_NASCIMENTO, _dataNascimento);

    P->ID = _id;
    P->ID_FREGUESIA = _idFreguesia;

    return P;
}

void MostrarPessoa(PESSOA *P)
{
    printf("\tPESSOA: ID: %d [%s] [%s] %d\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->ID_FREGUESIA);
}
void DestruirPessoa(PESSOA *P)
{
    if (P != NULL) {
        free(P->NOME);
        free(P->DATA_NASCIMENTO);
        free(P);
    }
}
