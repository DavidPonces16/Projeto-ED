#include "Hashing.h"

LISTA_CHAVES *CriarListaCHAVES() {
    LISTA_CHAVES *L = (LISTA_CHAVES *)malloc(sizeof(LISTA_CHAVES));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

NO_CHAVE *AddCHAVE(LISTA_CHAVES *L, char *key) {
    if (!L) return NULL;
    NO_CHAVE *aux = (NO_CHAVE *)malloc(sizeof(NO_CHAVE));
    aux->KEY = strdup(key);
    aux->DADOS = CriarLista();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}

HASHING *CriarHashing() {
    HASHING *H = (HASHING *)malloc(sizeof(HASHING));
    H->LChaves = CriarListaCHAVES();
    return H;
}

void DestruirHashing(HASHING *H) {
    if (!H || !H->LChaves) return;
    NO_CHAVE *current = H->LChaves->Inicio;
    while (current != NULL) {
        NO_CHAVE *prox = current->Prox;
        printf("Destruindo chave: %s\n", current->KEY);
        free(current->KEY);
        DestruirLista(current->DADOS);
        free(current);
        current = prox;
    }
    printf("Destruindo lista de chaves\n");
    free(H->LChaves);
    free(H);
}


void AddHashing(HASHING *H, char *sobrenome) {
    NO_CHAVE *current = H->LChaves->Inicio;
    while (current != NULL) {
        if (strcmp(current->KEY, sobrenome) == 0) {
            AddInicio(current->DADOS, NULL);
            return;
        }
        current = current->Prox;
    }

    NO_CHAVE *novo = (NO_CHAVE *)malloc(sizeof(NO_CHAVE));
    novo->KEY = strdup(sobrenome);
    novo->DADOS = CriarLista();
    AddInicio(novo->DADOS, NULL);
    novo->Prox = H->LChaves->Inicio;
    H->LChaves->Inicio = novo;
    H->LChaves->NEL++;
}

void ShowHashing(HASHING *H) {
    NO_CHAVE *current = H->LChaves->Inicio;
    while (current != NULL) {
        printf("Sobrenome: %s, Contagem: %d\n", current->KEY, current->DADOS->NEL);
        current = current->Prox;
    }
}

NO_CHAVE *FuncaoHashing(HASHING *H, PESSOA *X) {
    if (!H || !H->LChaves) return NULL;

    NO_CHAVE *P = H->LChaves->Inicio;
    while (P) {
        if (strcmp(P->KEY, X->ID_FREGUESIA) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}
