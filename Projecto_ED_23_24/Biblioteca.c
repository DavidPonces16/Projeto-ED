#include "Biblioteca.h"

#define BUFFER_SIZE 1024

/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */

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

int LoadFicheiroBiblioteca(BIBLIOTECA *B) {
    printf("LoadFicheiroBiblioteca\n");
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o ficheiro de logs\n");
        return EXIT_FAILURE;
    }
    
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fflush(F_Logs);

    FILE *file = fopen("files/requisitantes.txt", "r");
    if (file == NULL) {
        fprintf(F_Logs, "Erro ao abrir o ficheiro requisitantes.txt\n");
        fclose(F_Logs);
        return EXIT_FAILURE;
    }
    
    char buffer[BUFFER_SIZE];
    
    printf("A carregar ficheiro de requisitantes\n");
    fprintf(F_Logs, "A carregar ficheiro de requisitantes\n");
    fflush(F_Logs);

    while (fgets(buffer, BUFFER_SIZE, file)) {
        buffer[strcspn(buffer, "\n")] = 0;

        char* token = strtok(buffer, "\t");
        if (token == NULL) {
            fprintf(F_Logs, "Linha malformada: %s\n", buffer);
            fflush(F_Logs);
            continue;
        }

        int id = atoi(token);

        char* nome = strtok(NULL, "\t");
        if (nome == NULL) {
            fprintf(F_Logs, "Nome ausente na linha: %s\n", buffer);
            fflush(F_Logs);
            continue;
        }

        char* data_nascimento = strtok(NULL, "\t");
        if (data_nascimento == NULL) {
            fprintf(F_Logs, "Data de nascimento ausente na linha: %s\n", buffer);
            fflush(F_Logs);
            continue;
        }

        char* id_freguesia_str = strtok(NULL, "\t");
        if (id_freguesia_str == NULL) {
            fprintf(F_Logs, "ID de freguesia ausente na linha: %s\n", buffer);
            fflush(F_Logs);
            continue;
        }
        int id_freguesia = atoi(id_freguesia_str);

        PESSOA* novaPessoa = CriarPessoa(id, nome, data_nascimento, id_freguesia);
        if (novaPessoa == NULL) {
            fprintf(F_Logs, "Erro ao criar pessoa para a linha: %s\n", buffer);
            fflush(F_Logs);
            continue;
        }
        
        if (AddRequisitante(B, novaPessoa) == EXIT_FAILURE) {
            fprintf(F_Logs, "Erro ao adicionar requisitante para a linha: %s\n", buffer);
            fflush(F_Logs);
            free(novaPessoa);
            continue;
        }
    }

    fclose(file);
    fprintf(F_Logs, "Leitura do ficheiro de requisitantes concluída com sucesso\n");
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
char* ApelidoMaisComum(BIBLIOTECA *B) {
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    typedef struct ApelidoNode {
        char apelido[50];
        int count;
        struct ApelidoNode *proxima;
    } APELIDO_NODE;

    APELIDO_NODE *apelidos = NULL;

    PESSOA *atual = B->requisitantes;
    while (atual != NULL) {
        char *ultimo_espaco = strrchr(atual->NOME, ' ');
        if (ultimo_espaco != NULL) {
            char *apelido = ultimo_espaco + 1;
            
            APELIDO_NODE *node = apelidos;
            APELIDO_NODE *prev = NULL;
            while (node != NULL && strcmp(node->apelido, apelido) != 0) {
                prev = node;
                node = node->proxima;
            }
            if (node == NULL) {
                node = (APELIDO_NODE*)malloc(sizeof(APELIDO_NODE));
                if (node == NULL) {
                    fprintf(F_Logs, "Erro de memória ao adicionar apelido\n");
                    fclose(F_Logs);
                    return NULL;
                }
                strcpy(node->apelido, apelido);
                node->count = 1;
                node->proxima = NULL;
                if (prev == NULL) {
                    apelidos = node;
                } else {
                    prev->proxima = node;
                }
            } else {
                node->count++;
            }
        }
        atual = atual->proxima;
    }

    APELIDO_NODE *mais_comum = apelidos;
    APELIDO_NODE *node = apelidos;
    while (node != NULL) {
        if (node->count > mais_comum->count) {
            mais_comum = node;
        }
        node = node->proxima;
    }

    char *result = NULL;
    if (mais_comum != NULL) {
        result = (char*)malloc(strlen(mais_comum->apelido) + 1);
        if (result != NULL) {
            strcpy(result, mais_comum->apelido);
        }
    }

    while (apelidos != NULL) {
        node = apelidos;
        apelidos = apelidos->proxima;
        free(node);
    }

    fclose(F_Logs);
    printf("Apelido mais comum: %s\n", result);
    return result;
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

int AddRequisitante(BIBLIOTECA *B, PESSOA *novaPessoa) {
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL) {
        fprintf(F_Logs, "Erro ao abrir o ficheiro de logs add\n");
        return EXIT_FAILURE;
    }

    time_t now = time(NULL);

    if (B == NULL || novaPessoa == NULL) {
        return EXIT_FAILURE;
    }

    novaPessoa->proxima = B->requisitantes;
    B->requisitantes = novaPessoa;

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
