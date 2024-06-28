#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);

int Menu()
{
    printf("Displaying Menu\n");
    printf("1- Livros\n");
    printf("2- Requisitantes\n");
    printf("3- Requisicoes\n");
    printf("0-Sair\n");
    int op;
    op = LerInteiro("Qual a opcao? ");
    return op;
}

void MenuLivros(BIBLIOTECA *biblioteca)
{
    int op;
    do
    {
        printf("Displaying Menu Livros\n");
        printf("1- Adicionar Livro\n");
        printf("2- Listar Todos os Livros por Area\n");
        printf("3- Area com mais Livros\n");
        printf("4- Livros mais recentes\n");
        printf("5- Livros mais requisitados\n");
        printf("6- Area mais requisitada\n");
        printf("0-Sair\n");
        op = LerInteiro("Qual a opcao? ");
        printf("Option selected: %d\n", op);
        switch (op)
        {
        case 1:
            printf("Adicionar Livro\n");
            // addLivro();
            break;
        case 2:
            printf("Listar Todos os Livros por Area\n");
            // listarLivrosPorArea();
            break;
        case 3:
            printf("Area com mais Livros\n");
            // areaComMaisLivros();
            break;
        case 4:
            printf("Livros mais recentes\n");
            // livrosMaisRecentes();
            break;
        case 5:
            printf("Livros mais requisitados\n");
            // livrosMaisRequisitados();
            break;
        case 6:
            printf("Area mais requisitada\n");
            // areaMaisRequisitada();
            break;
        default:
            if (op != 0)
                printf("Opcao nao implementada\n");
            break;
        }

    } while (op != 0);
}

void MenuRequisitantes(BIBLIOTECA *biblioteca)
{
    int op;
    do
    {
        printf("Displaying Menu Requisitantes\n");
        printf("1- Adicionar Requisitante\n");
        printf("2- Pesquisar por Nome\n");
        printf("3- Listagem de Requisitantes\n");
        printf("4- Idade máxima\n");
        printf("5- Idade média\n");
        printf("6- Idade superior a numero customizavel\n");
        printf("7- Idade com mais Requisitantes\n");
        printf("8- Requicoes de um Requisitante\n");
        printf("9- Pessoas que ainda nao Requisitaram\n");
        printf("10- Sobrenome mais usado\n");
        printf("11- Pessoas por Distrito ou Conselho por nome\n");
        printf("12- Requisitantes que nasceram em domingo\n");
        printf("13- Requisitantes que nasceram durante a quaresma\n"); 
        printf("0-Sair\n");
        op = LerInteiro("Qual a opcao? ");
        printf("Option selected: %d\n", op);
        switch (op)
        {
        case 1:
            printf("Adicionar Requisitante\n");
            // addRequisitante();
            break;
        case 2:
            printf("Pesquisar por Nome\n");
            // pesquisarPorNome();
            break;
        case 3:
            printf("Listagem de Requisitantes\n");
            ShowBiblioteca(biblioteca);
            break;
        case 4:
            printf("Idade máxima\n");
            // idadeMaxima();
            break;
        case 5:
            printf("Idade média\n");
            // idadeMedia();
            break;
        case 6:
            printf("Idade superior a numero customizavel\n");
            // idadeSuperiorCustomizavel();
            break;
        case 7:
            printf("Idade com mais Requisitantes\n");
            // idadeComMaisRequisitantes();
            break;
        case 8:
            printf("Requicoes de um Requisitante\n");
            // requisicoesDeUmRequisitante();
            break;
        case 9:
            printf("Pessoas que ainda nao Requisitaram\n");
            // pessoasSemRequisicoes();
            break;
        case 10:
            char *sobrenome = SobrenomeMaisComum(biblioteca);
            if (sobrenome) {
                printf("Sobrenome mais usado: %s\n\n", sobrenome);
                free(sobrenome);
            } else {
                printf("Não foi possível determinar o sobrenome mais usado.\n");
            }
            break;
        case 11:
            printf("Pessoas por Distrito ou Conselho por nome\n");
            // pessoasPorDistritoOuConselho();
            break;
        case 12:
            printf("Requisitantes que nasceram em domingo\n");
            // requisitantesNasceramDomingo();
            break;
        case 13:
            printf("Requisitantes que nasceram durante a quaresma\n");
            // requisitantesNasceramQuaresma();
            break;
        default:
            if (op != 0)
                printf("Opcao nao implementada\n");
            break;
        }

    } while (op != 0);
}

void MenuRequisicoes(BIBLIOTECA *biblioteca)
{
    int op;
    do
    {
        printf("Displaying Menu Requisicoes\n");
        printf("1- Requisitar\n");
        printf("2- Devolver\n");
        printf("3- Requisicoes Ativas\n");
        printf("0-Sair\n");
        op = LerInteiro("Qual a opcao? ");
        printf("Option selected: %d\n", op);
        switch (op)
        {
        case 1:
            printf("Adicionar Requisicao\n");
            // adicionarRequisicao();
            break;
        case 2:
            printf("Remover Requisicao\n");
            // removerRequisicao();
            break;
        case 3:
            printf("Mostrar Requisicoes Ativas\n");
            // mostrarRequisicoesAtivas();
            break;
        default:
            if (op != 0)
                printf("Opcao nao implementada\n");
            break;
        }

    } while (op != 0);
}

int main()
{
    printf("Projecto-Biblioteca-Versao-Base!\n");
    BIBLIOTECA *biblioteca = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    biblioteca->NOME = strdup("Biblioteca Central");
    biblioteca->FICHEIRO_LOGS = strdup("log.txt");
    LoadLivrosBiblioteca(biblioteca);
    LoadFicheiroBiblioteca(biblioteca);
    int OP;
    do
    {
        OP = Menu();
        printf("Option selected: %d\n", OP);
        switch (OP)
        {
        case 1:
            MenuLivros(biblioteca);
            break;
        case 2:
            MenuRequisitantes(biblioteca);
            break;
        case 3:
            MenuRequisicoes(biblioteca);
            break;
        default:
            if (OP != 0)
                printf("Opcao nao implementada\n");
            break;
        }

    } while (OP != 0);
    printf("Exiting and destroying Biblioteca\n");
    DestruirBiblioteca(biblioteca);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
