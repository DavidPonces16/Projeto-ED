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

/*************************************************************
 *                     SEÇÃO DE Loading                      *
 * Este bloco de código é responsável por carregar os dados  *
 * necessários a partir de arquivos externos.                *
                                                             *
 *************************************************************/

int LoadFicheiroBiblioteca(BIBLIOTECA *B) {
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o ficheiro de logs\n");
        return EXIT_FAILURE;
    }
    
    LISTA *freguesiasValidas = CarregarFreguesiasValidas();
    if (freguesiasValidas == NULL) return EXIT_FAILURE;

    FILE *file = fopen("files/Requisitantes.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return -1;
    }

    fprintf(F_Logs, "A iniciar a leitura do ficheiro de requisitantes\n");

    B->LRequisitantes = CriarLista();
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;

        char linha_original[256];
        strncpy(linha_original, linha, sizeof(linha_original));
        linha_original[sizeof(linha_original) - 1] = '\0';

        char *token = strtok(linha, "\t");
        int id = atoi(token);
        if (!ValidarIDRequisitante(id)) {
            fprintf(F_Logs, "Requisitante [%s] inválido, Id mal estruturado\n", linha_original);
            continue;
        };

        token = strtok(NULL, "\t");
        char *nome = strdup(token);

        token = strtok(NULL, "\t");
        char *dataNascimento = strdup(token);
        if (!ValidarDataNascimento(dataNascimento)) {
            fprintf(F_Logs, "Requisitante [%s] inválido, Data de Nascimento mal estruturada\n", linha_original);
            free(nome);
            free(dataNascimento);
            continue;
        }

        token = strtok(NULL, "\t");
        int idFreguesia = atoi(token);
        if (!ValidarIDFreguesia(idFreguesia, freguesiasValidas)) {
            fprintf(F_Logs, "Requisitante [%s] inválido, Id da Freguesia mal estruturado\n", linha_original);
            free(nome);
            free(dataNascimento);
            continue;
        }

        PESSOA *pessoa = CriarPessoa(id, nome, dataNascimento, idFreguesia);
        AddInicio(B->LRequisitantes, pessoa);

        free(nome);  // Libertar memória alocada por strdup
        free(dataNascimento);  // Libertar memória alocada por strdup
    }
    fclose(file);
    DestruirLista(freguesiasValidas);
    fprintf(F_Logs, "Leitura do ficheiro de requisitantes concluída com sucesso\n");
    fclose(F_Logs);
    
    return EXIT_SUCCESS;
}

int LoadLivrosBiblioteca(BIBLIOTECA *B) {

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o ficheiro de logs\n");
        return EXIT_FAILURE;
    }
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    FILE *file = fopen("files/Livros.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro de livros");
        return -1;
    }

    fprintf(F_Logs, "A iniciar a leitura do ficheiro de livros\n");

    B->HLivros = CriarLista();
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, "\t");
        char *nome = strdup(token);

        token = strtok(NULL, "\t");
        int id = atoi(token);

        token = strtok(NULL, "\t");
        char *area = strdup(token);

        LIVRO *livro = CriarLivro(id, nome, area);
        AddInicio(B->HLivros, livro);
        fprintf(F_Logs, "Livro [%s] adicionado com sucesso\n", nome);

        free(nome);
        free(area); 
    }
    fclose(file);
    fclose(F_Logs);
    return 0;
}

/*************************************************************
 *                      SEÇÃO DE LIVROS                      *
 * Esta seção de código é responsável pelo gerenciamento de  *
 * livros na biblioteca.                                     *
 *************************************************************/

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

/*************************************************************
 *                  SEÇÃO DE REQUISITANTE                    *
 * Esta seção de código é responsável pelo gerenciamento de  *
 * requisitantes na biblioteca.                              *
 *************************************************************/

PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    NO *temp = B->LRequisitantes->Inicio;
    while (temp != NULL) {
        if (temp->Info->ID == cod) {
            return temp->Info;
        }
        temp = temp->Prox;
    }

    fclose(F_Logs);
    return temp->Info;
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
    time_t now = time(NULL);
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

    fclose(F_Logs);
    //DestruirHashing(hashing);
    return resultado;
}

/*************************************************************
 *                      SEÇÃO DE VALIDAÇÕES                  *
 * Este bloco de código é responsável por realizar as        *
 * validações necessárias dos dados lidos e processados.     *
 *************************************************************/

// Função para validar id_requisitante
int ValidarIDRequisitante(int id) {
    char idStr[10];
    sprintf(idStr, "%09d", id);

    if (strlen(idStr) != 9) return 0;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        if (!isdigit(idStr[i])) return 0;
        soma += idStr[i] - '0';
    }

    return soma % 10 == 0;
}

// Função para validar data_nasc
int ValidarDataNascimento(const char *data) {
    if (strlen(data) != 10) return 0;
    if (data[2] != '-' || data[5] != '-') return 0;

    int dia = atoi(&data[0]);
    int mes = atoi(&data[3]);
    int ano = atoi(&data[6]);

    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (ano < 1900 || ano > 2100) return 0;

    return 1;
}

// Função para carregar freguesias válidas
LISTA *CarregarFreguesiasValidas() {
    FILE *file = fopen("files/Freguesias.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro de freguesias");
        return NULL;
    }

    LISTA *freguesiasValidas = CriarLista();
    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, "\t");
        if (token != NULL) {
            char *codigo = strdup(token);
            PESSOA *freguesia = CriarPessoa(0, codigo, "", 0);
            AddInicio(freguesiasValidas, freguesia);
            free(codigo);
        }
    }
    fclose(file);
    return freguesiasValidas;
}

// Função para validar id_freguesia
int ValidarIDFreguesia(int idFreguesia, LISTA *freguesiasValidas) {

    char idStr[7];
    sprintf(idStr, "%06d", idFreguesia);

    NO *temp = freguesiasValidas->Inicio;
    while (temp != NULL) {
        if (strcmp(temp->Info->NOME, idStr) == 0) {
            return 1;
        }
        temp = temp->Prox;
    }
    return 0;
}
