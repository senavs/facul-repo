/*
   Desenvolvido por: prof. Vicente Teixeira   -    Em: 20/03/2019
   Objetivo:  Prova de Conceito do TAD LISTA utilizando ARRANJO
              O objeto de implementação é uma Aplicação para atender ao problema
              proposto no preâmbulo da apostila sobre LISTAS LINEARES.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLista.c"


// ===== Opções do menu ========================================================
typedef enum {INCLUIR=1,EXCLUIR,LISTAR,SAIR} OpcoesDeMenu;

// ===== Cabeçalhos das Funções ================================================
void entraDados(Aluno *rmd);
void listarAlunos(Lista l);
void cabecalho();
void mostraMenu();

// ===== Programa Principal ====================================================
int main(int argc, char *argv[])
{
    Lista cadAlunos;
    Aluno aluno;
    OpcoesDeMenu op;
    char controle;
    int codErro;
    criaLista(&cadAlunos);
    while(op != SAIR )
	{
		codErro = 0;
        mostraMenu();
        scanf( "%d", &op);
		fflush( stdin );
		switch (op)
		{
			case INCLUIR :
                 do {
                     cabecalho();
                     printf( "\t                  ::: Cadastrar Aluno ::: \n\n" );
                     if (cheiaLista(&cadAlunos)) {
                         printf("     Cadastro cheio!!!\n\n");
                         system("pause");
                         controle = 'N';
                     }
                     else {
                         entraDados(&aluno);
                         insereLista (aluno, &cadAlunos, &codErro);
                         if (codErro == 0)
                             printf("\n   Inclusao realizada com sucesso!!!");
                         printf("\n\n   Deseja cadastrar outro Aluno? (S/N) ");
                         controle = getch();
                         fflush(stdin);
                     }
                 } while(controle == 'S' || controle == 's');
				 break;
            case EXCLUIR :
                  do {
                     cabecalho();
                     printf( "\t                    ::: Excluir Aluno :::\n\n" );
                     if (vaziaLista(&cadAlunos)) {
                         printf("     Cadastro vazio!!!\n\n");
                         system("pause");
                         controle = 'N';
                     }
                     else {
                         printf("\n   Informe nome do Aluno a excluir: ");
                         gets(aluno.nome);
                         excluiLista (aluno, &cadAlunos, &codErro);
                         if (codErro != 0)
                              printf("\n   Aluno nao existente no cadastro!!!");
                         else printf("\n   Exclusao realizada com sucesso!!!");
                         printf("\n\n   Deseja excluir outro Aluno? (S/N) ");
                         controle = getch();
                         fflush(stdin);
                     }
                 } while(controle == 'S' || controle == 's');
                 break;
            case LISTAR :
                 cabecalho();
                 if(vaziaLista(&cadAlunos))
                       printf("     Cadastro vazio!!!\n\n");
                 else
                 {
                      printf("\t              ::: Lista de Alunos Cadastrados :::\n\n");
                      printf("\n                          Quantidade cadastrada: %d\n\n", cadAlunos.tamanho);
                      imprimeLista(&cadAlunos);
                 }
                 system("pause");
				 break;
            case SAIR: break;
            default: printf("     Opcao invalida!!!\n\n");
                     system("pause");
		}
	}
    return 0;
}   /* fim de main */

//==== Entrar Dados do Aluno =================================================
void entraDados(Aluno *al)
{
    fflush(stdin);
    printf("  Nome do Aluno: ");
    gets(al->nome);
    fflush(stdin);
    printf("  Matricula ...: ");
    scanf("%d", &al->matr);
    fflush(stdin);
    printf("  Nota ........: ");
    scanf("%f", &al->nota);
    fflush(stdin);
}
//==== cabecalho ===============================================================
void cabecalho ()
{
     system ("cls");
     printf("\n                       UPIS - Sistemas de Informacao \n");
     printf(" ED - Estrutura de Dados                             Prof. Vicente Teixeira\n");
     printf(" --------------------------------------------------------------------------\n");
     printf(" CADASTRO ALUNOS       ::: LISTA LINEAR COM ARRANJO :::              2019/1\n");
     printf(" --------------------------------------------------------------------------\n\n");
}    /* fim de cabecalho */

//==== menu ====================================================================
void mostraMenu() {
     cabecalho();
     printf( "\t                         ::: Menu :::\n\n" );
     printf( "\t                 [%d] - Incluir Aluno\n", INCLUIR);
     printf( "\t                 [%d] - Excluir Aluno\n" , EXCLUIR);
     printf( "\t                 [%d] - Listar Alunos\n" ,  LISTAR);
     printf( "\t                 [%d] - Sair\n\n",   SAIR );
     printf( "                                               Digite sua opcao: " );
}
