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
    //Bib->HLivros = CriarHashing();
    //Bib->LRequisicoes = CriarListaRequisicoes();
    //Bib->LRequisitantes = CriarListaRequisitantes();
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
    printf("Requisitantes:\n");
    ShowLista(B->LRequisitantes);
    //ShowHashing(B->HLivros);

    fclose(F_Logs);
}
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    DestruirLista(B->LRequisitantes);
    free(B->NOME);
    free(B->FICHEIRO_LOGS);
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
    
    FILE *file = fopen("files/Requisitantes.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return EXIT_FAILURE;
    }

    B->LRequisitantes = CriarLista();
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, "\t");
        int id = atoi(token);

        token = strtok(NULL, "\t");
        char *nome = strdup(token);

        token = strtok(NULL, "\t");
        char *dataNascimento = strdup(token);

        token = strtok(NULL, "\t");
        int idFreguesia = atoi(token);

        PESSOA *pessoa = CriarPessoa(id, nome, dataNascimento, idFreguesia);
        AddInicio(B->LRequisitantes, pessoa);

        free(nome);
        free(dataNascimento);
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

PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}

// Função auxiliar para obter o último sobrenome
char *ObterSobrenome(char *nomeCompleto) {
    char *sobrenome = strrchr(nomeCompleto, ' ');
    if (sobrenome != NULL) {
        return sobrenome + 1;
    }
    return nomeCompleto;
}

char *SobrenomeMaisComum(BIBLIOTECA *B) {
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    HASHING *hashing = CriarHashing();
    
    NO *temp = B->LRequisitantes->Inicio;
    while (temp != NULL) {
        char *sobrenome = ObterSobrenome(temp->Info->NOME);
        AddHashing(hashing, sobrenome);
        temp = temp->Prox;
    }

    NO_CHAVE *maisComum = NULL;
    NO_CHAVE *current = hashing->LChaves->Inicio;
    while (current != NULL) {
        if (maisComum == NULL || current->DADOS->NEL > maisComum->DADOS->NEL) {
            maisComum = current;
        }
        current = current->Prox;
    }

    char *resultado = NULL;
    if (maisComum != NULL) {
        resultado = strdup(maisComum->KEY);
    }

    printf("Sobrenome mais comum: %s\n", resultado);
    DestruirHashing(hashing);
    fclose(F_Logs);
    return resultado;
}
