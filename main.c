#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#include "tad.h"
#include "simplesmente_encadeada.h"
#include "duplamente_encadeada.h"
#include "funcoes_auxiliares.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    //-----> VARIÁVEIS PRINCIPAIS <------//

    ListaDeAlunos *lda;
    lda = cria_lda();

    //-----> VARIÁVEIS SECUNDÁRIAS <-----//

    int escolha;
    bool condicao = true;

    int id_buscado, id_buscado_2;
    char curso_buscado[255];

    inserir_dados_arquivo(&lda);

    //-----> O RESTO DA MAIN <-----//
    while (condicao)
    {
        escolha = 0;

        linha();
        printf("\n ESCOLHA A OPÇÃO DESEJADA: ");
        linha();
        printf("\n 1 - INSERIR UM NOVO ALUNO");
        printf("\n 2 - ALTERAR OS DADOS DE UM ALUNO");
        printf("\n 3 - REMOVER UM ALUNO");
        printf("\n 4 - IMPRIMIR A LISTA DE ALUNOS");
        printf("\n 5 - INSERIR RELAÇÃO DE AMIZADE");
        printf("\n 6 - REMOVER RELAÇÃO DE AMIZADE");
        printf("\n 7 - IMPRIMIR AMIGOS DE UM ALUNO");
        printf("\n 8 - IMPRIMIR A LISTA DE ALUNOS POR CURSO");
        printf("\n 9 - SAIR");
        linha();
        printf("\n >>> ");
        scanf("%d", &escolha);
        lb();

        switch (escolha)
        {
        case 1:

            inserir_aluno(&lda);

            break;

        case 2:

            alterar_dados(&lda);

            break;

        case 3:

            remover_aluno(&lda);

            break;

        case 4:

            imprime_alunos(&lda);

            break;

        case 5:

            criar_relacao(&lda);

            break;

        case 6:

            remover_relacao(&lda);

            break;

        case 7:

            imprimir_relacao(&lda);

            break;

        case 8:

            alunos_por_curso(&lda);

            break;

        case 9:

            lt();

            salvar_dados_arquivo(&lda);

            linha();

            condicao = false;

            break;

        default:

            lb();
            lt();
            linha();
            printf("\n O VALOR QUE VOCÊ DIGITOU NÃO CORRESPONDE A NENHUMA OPÇÃO,");
            printf("\n POR FAVOR DIGITE UM NÚMERO ENTRE 1 E 9, CORRESPONDENDE COM A OPÇÃO QUE DESEJA!");
            linha();

            continue;
        }
    }

    return EXIT_SUCCESS;
}