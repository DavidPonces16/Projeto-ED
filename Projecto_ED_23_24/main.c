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
    printf("3- Nome mais Comum\n");
    printf("0-Sair\n");
    int op;
    op = LerInteiro("Qual a o opcao? ");
    return op;
}

int main()
{
    printf("Projecto-Biblioteca-Versao-Base!\n");
    // Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    Bib->requisitantes = NULL;
    if (Bib == NULL)
    {
        fprintf(stderr, "Erro ao criar a biblioteca\n");
        return EXIT_FAILURE;
    }
    printf("Biblioteca criada com sucesso\n");
    int OP;
    do
    {
        OP = Menu();
        printf("Option selected: %d\n", OP);
        switch (OP)
        {
        case 1:
            printf("Loading Biblioteca\n");
            if (LoadFicheiroBiblioteca(Bib) == EXIT_SUCCESS)
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
            ShowBiblioteca(Bib);
            break;
        case 3:
            ApelidoMaisComum(Bib);
            break;
        default:
            printf("Opcao nao implementada\n");
            break;
        }

    } while (OP != 0);
    printf("Exiting and destroying Biblioteca\n");
    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
