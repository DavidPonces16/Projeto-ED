#include "Lista.h"

//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma lista
 *
 * \return LISTA* : Retorna a lista alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTA *CriarLista()
{
    LISTA *L = (LISTA *)malloc(sizeof(LISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

//--------------------------------------------------
void AddInicio(LISTA *L, PESSOA *X)
{
    if (!L) return;
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}

//--------------------------------------------------
void ShowLista(LISTA *L) {
    NO *temp = L->Inicio;
    while (temp != NULL) {
        if (((PESSOA *)temp->Info)->NOME != NULL) {
            MostrarPessoa((PESSOA *)temp->Info);
        } else if (((LIVRO *)temp->Info)->NOME != NULL) {
            MostrarLivro((LIVRO *)temp->Info);
        }
        temp = temp->Prox;
    }
}

//--------------------------------------------------
void DestruirLista(LISTA *L) {
    if (!L) return;
    NO *temp = L->Inicio;
    while (temp != NULL) {
        NO *prox = temp->Prox;
        if (((PESSOA *)temp->Info)->NOME != NULL) {
            DestruirPessoa((PESSOA *)temp->Info);
        } else if (((LIVRO *)temp->Info)->NOME != NULL) {
            DestruirLivro((LIVRO *)temp->Info);
        }
        free(temp);
        temp = prox;
    }
    free(L);
}

//--------------------------------------------------
void *PesquisarLista(LISTA *L, char *_nome) {
    NO *temp = L->Inicio;
    while (temp != NULL) {
        if (strcmp(((PESSOA *)temp->Info)->NOME, _nome) == 0) {
            return temp->Info;
        }
        temp = temp->Prox;
    }
    return NULL;
}

//--------------------------------------------------
int SizeLista(LISTA *L)
{
    if (!L) return -1;
    return L->NEL;
}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
