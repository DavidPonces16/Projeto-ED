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
            {
                int id = LerInteiro("ID do Livro: ");
                char nome[100];
                printf("Nome do Livro: ");
                scanf(" %[^\n]", nome);
                char area[100];
                printf("Area do Livro: ");
                scanf(" %[^\n]", area);
                int ano = LerInteiro("Ano de Lançamento: ");
                LIVRO *novoLivro = CriarLivro(id, nome, area, ano);
                if (AddLivroBiblioteca(biblioteca, novoLivro)) {
                    printf("Livro adicionado com sucesso!\n");
                } else {
                    printf("Erro ao adicionar o livro.\n");
                }
            }
            break;
        case 2:
            printf("Listar Todos os Livros por Area\n");
            ListarLivrosPorArea(biblioteca);
            break;
        case 3:
            {
                printf("Área com mais Livros\n");
                char *areaMaisComum = AreaMaisComum(biblioteca);
                if (areaMaisComum) {
                    printf("A área com mais livros é: %s\n", areaMaisComum);
                    free(areaMaisComum);
                } else {
                    printf("Não foi possível determinar a área com mais livros.\n");
                }
            }
            break;
        case 4:
            printf("Livros mais recentes\n");
            LivrosMaisRecentes(biblioteca);
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
            SobrenomeMaisComum(biblioteca);
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
            {
                char *idReqStr = GerarNovoIdRequisicao();
                int idPessoa = LerInteiro("ID do Requisitante: ");
                int idLivro = LerInteiro("ID do Livro: ");
                PESSOA *pessoa = PesquisarRequisitante(biblioteca, idPessoa);
                LIVRO *livro = NULL;
                printf("ID Req: %s\n", idReqStr);
                NO *noLivro = biblioteca->HLivros->Inicio;
                while (noLivro) {
                    if (((LIVRO *)noLivro->Info)->ID == idLivro) {
                        livro = (LIVRO *)noLivro->Info;
                        break;
                    }
                    noLivro = noLivro->Prox;
                }
                printf("Pessoa: %p, Livro: %p\n", pessoa, livro);
                if (pessoa && livro) {
                    int idReq = atoi(idReqStr + 3);
                    REQUISICAO *novaRequisicao = CriarRequisicao(idReq, pessoa, livro);
                    printf("Requisicao: %p\n", novaRequisicao);
                    if (AddRequisicaoBiblioteca(biblioteca, novaRequisicao)) {
                        printf("Requisição adicionada com sucesso!\n");
                    } else {
                        printf("Erro ao adicionar a requisição.\n");
                    }
                    free(idReqStr);
                } else {
                    printf("Requisitante ou Livro não encontrado.\n");
                    free(idReqStr);
                }
            }
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
