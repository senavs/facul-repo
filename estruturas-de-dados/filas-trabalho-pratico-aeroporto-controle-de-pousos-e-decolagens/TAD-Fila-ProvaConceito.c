// Autor: Vicente Teixeira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TAD-Fila-ArranjoCirc.c"

void cabecalho ();
void linhaMenu ();
void imprimeTela (Fila *fila, Dados atendido);
void trataErro (int codErro);

/*==================================================================
              Função Main
 Condição de Erro = 10 - Fila vazia
 Condição de Erro = 20 - Fila cheia
 Condição de Erro = 99 - Opção inválida
==================================================================*/

int main(void)
{
	int codErro;
	char opcao;
	int i;
	Dados dado, emAtendimento;
	Fila fila;

    iniciaFila(&fila);
    codErro = 10;  // Fila Vazia
    strcpy(emAtendimento.nomeObjeto, "");
    do
    {
       cabecalho();
       imprimeTela(&fila, emAtendimento);
       trataErro (codErro);
       linhaMenu();
       opcao = getch();
       codErro = 0;
       switch (opcao)
       {
            case '1':  case 'e': case 'E':
            {
                if (isFull(&fila))
                {
                   codErro = 20;
                   break;
                }
                printf ("\n\n Informe o nome da pessoa chegando na fila: ");
                fflush(stdin);
                gets(dado.nomeObjeto);
                enqueue(dado, &fila, &codErro);
                break;
            }
            case '2': case 'd': case 'D':
            {
                dequeue(&emAtendimento, &fila, &codErro);
                break;
            }
            case '3':  case 'f':  case 'F':  break;
            default: codErro = 99;
       }
    }
    while ((opcao != '3') && (opcao != 'f') && (opcao != 'F'));
    printf ("\n\n\n     Programa encerrando!!! Obrigado \n     Aperte qualquer tecla...\n\n");
    getch();
    return 0;
} /*  main */

/*==============================================================================*/
void cabecalho ()
{
     system("cls");
     printf("\n                        UPIS - Sistemas de Informacao \n");
     printf(" ED - Estrutura de Dados                               Prof. Vicente Teixeira\n");
     printf("                        P R O V A   D E   C O N C E I T O     \n");
     printf("                  F I L A  -  A R R A N J O   C I R C U L A R \n");
     printf(" ----------------------------------------------------------------------------\n\n");
} /*  cabecalho  */

/*==============================================================================*/
void linhaMenu()
{
  printf("\n 1=Enfileirar | 2=Desenfileirar | 3=Finalizar programa\n");
  printf("\n                 Escolha a opcao: ");
} /*  linhaMenu  */

/*==============================================================================*/
void imprimeTela (Fila *fila, Dados atendido)
{
   int i;
   cabecalho();
   printf("\n                                      ATENDIDO NO CAIXA: %s\n", atendido.nomeObjeto);
   for (i = 0; i<MAX; i++)
   {
       printf("   |---------------------------|\n");
       if (strcmp(fila->dados[i].nomeObjeto, "") != 0)
           printf(" %d | %25s | ", i, fila->dados[i].nomeObjeto);
       else
           printf(" %d |                           | ", i);
       if (fila->inicio == i && fila->fim == i)
          printf(" <-- Inicio/Fim \n");
       else if (fila->inicio == i)
          printf(" <-- Inicio \n");
       else if (fila->fim == i)
          printf(" <-- Fim \n");
       else
          printf(" \n");
   }
   printf("   |---------------------------|\n");
}
/*==============================================================================*/
void trataErro (int codErro)
{
    switch (codErro)
    {
       case 10: printf("\n             Fila Vazia! \n"); break;
       case 20: printf("\n             Fila Cheia! \n"); break;
       case 99: printf("\n             Erro: Opcao Invalida! \n"); break;
       default: printf("\n             Processamento realizado com sucesso!!! \n");
    }
}
/*==============================================================================*/


