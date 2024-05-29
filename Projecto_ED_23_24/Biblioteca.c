#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */

// Definição da estrutura BIBLIOTECA
typedef struct {
    char* NOME;
    char* FICHEIRO_LOGS;
    void *HLivros; //ponteiro

} BIBLIOTECA;

BIBLIOTECA* reservaBiblioteca(const char* _nome, const char* _logs) {
    // Reserva memória para a estrutura BIBLIOTECA
    BIBLIOTECA* biblioteca = (BIBLIOTECA*)malloc(sizeof(BIBLIOTECA));
    if (biblioteca == NULL) {
        fprintf(stderr, "Erro ao reservar memoria para a biblioteca\n");
        return NULL;
    }

    // Reserva memória e copia o nome da biblioteca
    biblioteca->NOME = (char*)malloc(strlen(_nome) + 1);
    if (biblioteca->NOME == NULL) {
        fprintf(stderr, "Erro ao reservar memoria para o nome da biblioteca\n");
        free(biblioteca);  // Disponibiliza a memória da estrutura em caso de falha
        return NULL;
    }
    strcpy(biblioteca->NOME, _nome);

    // Reserva memória e copia o nome do ficheiro dos logs
    biblioteca->FICHEIRO_LOGS = (char*)malloc(strlen(_logs) + 1);
    if (biblioteca->FICHEIRO_LOGS == NULL) {
        fprintf(stderr, "Erro ao reservar memoria para o ficheiro dos logs\n");
        free(biblioteca->NOME);  // Disponibiliza a memória do nome
        free(biblioteca);        // Disponibiliza a memória da estrutura
        return NULL;
    }
    strcpy(biblioteca->FICHEIRO_LOGS, _logs);

    return biblioteca;
}

// Função para liberar a memória reservada para a BIBLIOTECA
void disponibilizaBiblioteca(BIBLIOTECA* biblioteca) {
    if (biblioteca != NULL) {
        free(biblioteca->NOME);
        free(biblioteca->FICHEIRO_LOGS);
        free(biblioteca);
    }
}

int main() {
    // Exemplo de uso da função reservaBiblioteca
    const char* nome = "Minha Biblioteca";
    const char* logs = "logs.txt";
    
    BIBLIOTECA* biblioteca = reservaBiblioteca(nome, logs);
    if (biblioteca != NULL) {
        printf("Biblioteca reservada com sucesso!\n");
        printf("Nome: %s\n", biblioteca->NOME);
        printf("Logs: %s\n", biblioteca->FICHEIRO_LOGS);
        
        // Libera a memória alocada
        Biblioteca(biblioteca);
    }

    return 0;
}


BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs)
{
    BIBLIOTECA *Bib = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    Bib->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(Bib->NOME, _nome);
    strcpy(Bib->FICHEIRO_LOGS, _logs);
    Bib->HLivros = CriarHashing();
    //Bib->LRequisicoes = CriarListaRequisicoes();
    //Bib->LRequisitantes = CriarListaPessoas();
    return Bib;
}

/** \brief Funcao para Mostrar toda a Biblioteca
 *
 * \param B BIBLIOTECA* : Pnteiro para a Biblioteca
 * \return void
 * \author : Docentes e Alunos
 * \date   : 11/04/2024
 */
void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    // Vosso Codigo.....
    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Vosso Codigo.....
    free (B->NOME);
    //------
    free(B);

    fclose(F_Logs);
}
int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Vosso Codigo.....
    PESSOA *X = CriarPessoa(1234, "Jose", "CAT-A");
    AddHashing(B->HLivros, X);
    X = CriarPessoa(567, "Pedro", "CAT-A");
    AddHashing(B->HLivros, X);
    X = CriarPessoa(456, "Luis", "CAT-A");
    AddHashing(B->HLivros, X);
    X = CriarPessoa(56, "Miguel", "CAT-B");
    AddHashing(B->HLivros, X);
    X = CriarPessoa(5690, "James Bond", "CAT-Z");
    AddHashing(B->HLivros, X);

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
char *ApelidoMaisComum(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
char *AreaMaisComum(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fprintf(F_Logs, "Sai de %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
int AddRequisitante(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
