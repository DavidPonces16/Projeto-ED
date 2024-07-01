
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//necess�rio p/ fun��o time()

#define REQUISICAO_ID_FILE "files/ultimo_id_requisicao.txt"

int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int Factorial(int N)
{
    if (N == 0) return 1;
    return N * Factorial(N-1);
}

int LerInteiro(char *txt)
{
    int x;
    printf("%s : ", txt);
    scanf("%d", &x);
    return x;
}

int LerUltimoIdRequisicao() {
    FILE *file = fopen(REQUISICAO_ID_FILE, "r");
    if (!file) return 0;

    int ultimoId;
    fscanf(file, "%d", &ultimoId);
    fclose(file);
    return ultimoId;
}

void AtualizarUltimoIdRequisicao(int ultimoId) {
    FILE *file = fopen(REQUISICAO_ID_FILE, "w");
    if (file) {
        fprintf(file, "%d", ultimoId);
        fclose(file);
    }
}

char *GerarNovoIdRequisicao() {
    int ultimoId = LerUltimoIdRequisicao();
    ultimoId++;

    char *novoId = (char *)malloc(10 * sizeof(char));
    snprintf(novoId, 10, "RQ-%03d", ultimoId);

    AtualizarUltimoIdRequisicao(ultimoId);
    return novoId;
}
