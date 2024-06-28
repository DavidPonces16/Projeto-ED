#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);

/*void Exemplo_Hashing() {
    printf("Running Exemplo_Hashing\n");
    HASHING *Has = CriarHashing();
    PESSOA *X = CriarPessoa(1234, "Jose", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(567, "Pedro", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(456, "Luis", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(56, "Miguel", "CAT-B");
    AddHashing(Has, X);
    X = CriarPessoa(789, "Ricardo", "CAT-B");
    AddHashing(Has, X);
    ShowHashing(Has);

    DestruirHashing(Has);
}*/

int Menu()
{
    printf("Displaying Menu\n");
    printf("1- Load\n");
    printf("2- Show\n");
    printf("3- Sobrenome mais Comum\n");
    printf("0-Sair\n");
    int op;
    op = LerInteiro("Qual a o opcao? ");
    return op;
}

int main()
{
    printf("Projecto-Biblioteca-Versao-Base!\n");
    // Exemplo_Hashing();
    BIBLIOTECA *biblioteca = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    biblioteca->NOME = "Biblioteca Central";
    biblioteca->FICHEIRO_LOGS = "log.txt";
    int OP;
    do
    {
        OP = Menu();
        printf("Option selected: %d\n", OP);
        switch (OP)
        {
        case 1:
            printf("Loading Biblioteca\n");
            if (LoadFicheiroBiblioteca(biblioteca) == EXIT_SUCCESS)
            {
                printf("Requisitantes carregados com sucesso!\n");
            }
            else
            {
                printf("Falha ao carregar requisitantes.\n");
            }
            break;
        case 2:
            printf("Showing Biblioteca\n");
            ShowBiblioteca(biblioteca);
            break;
        case 3:
            SobrenomeMaisComum(biblioteca);
            break;
        default:
            printf("Opcao nao implementada\n");
            break;
        }

    } while (OP != 0);
    printf("Exiting and destroying Biblioteca\n");
    DestruirBiblioteca(biblioteca);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
