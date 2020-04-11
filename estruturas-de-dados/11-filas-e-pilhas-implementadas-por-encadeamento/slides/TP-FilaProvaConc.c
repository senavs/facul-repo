// Autor: Vicente Teixeira

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "TAD-FilaEncad.c"

void cabecalho ();
void linhaMenu ();
void imprimeTela (Fila *fila, Elemento atendido, char * msg);
void trataErro (int codErro);

/*==================================================================
         Função Main
 Condição de Erro = 10 - Fila vazia
 Condição de Erro = 20 - Fila cheia
 Condição de Erro = 99 - Opção inválida
==================================================================*/

int main(void)
{
	char opcao, msgErro[30] = "";
	Elemento objt, emAtendimento;
	Fila fila;
	int retorno;

    iniciaFila(&fila);
    strcpy(emAtendimento.nomeObjeto, "");

    do
    {
       imprimeTela(&fila, emAtendimento, msgErro);
       linhaMenu();
       opcao = getch();
       switch (opcao)
       {
            case '1':  case 'e': case 'E':
            {
                printf ("\n\n Informe o nome da pessoa chegando na fila: ");
                fflush(stdin);
                gets(objt.nomeObjeto);
                enqueue(objt, &fila);
                strcpy(msgErro, "Processamento realizado com sucesso!");
                break;
            }
            case '2': case 'd': case 'D':
            {
                retorno = dequeue(&emAtendimento, &fila);
                if(retorno == 0)
                    strcpy(msgErro, "Processamento realizado com sucesso!");
                else
                    strcpy(msgErro, "Fila Vazia!");
                break;
            }
            case '0':  case 'f':  case 'F':  break;
            default:  strcpy(msgErro, "Opcao invalida!");
       }
    }
    while ((opcao != '0') && (opcao != 'f') && (opcao != 'F'));
    printf ("\n\n\n     Programa encerrando!!! Obrigado \n     Aperte qualquer tecla... \n \n");
    getch();
    return 0;
} /*  main */

/*==============================================================================*/
void cabecalho ()
{
     system("cls");
     printf("\n                       UPIS - Sistemas de Informacao \n");
     printf(" ED - Estrutura de Dados                              Prof. Vicente Teixeira\n");
     printf("                       P R O V A   D E   C O N C E I T O      \n");
     printf("       F I L A   E N C A D E A D A -  A L O C A C A O   D I N A M I C A \n");
     printf(" ---------------------------------------------------------------------------\n\n");
} /*  cabecalho  */

/*==============================================================================*/
void linhaMenu()
{
  printf("\n1=Enfileirar | 2=Desenfileirar | 0=Finalizar programa\n");
  printf("\n               Escolha a opcao: ");
} /*  linhaMenu  */

/*==============================================================================*/
void imprimeTela (Fila *fila, Elemento atendido, char *msg)
{
   cabecalho();
   printf("                                     ATENDIDO NO CAIXA: %s\n", atendido.nomeObjeto);
   if (isEmpty(fila)){
      printf("   |---------------------------|\n");
      printf("   |                           | <-- Inicio/Fim\n");
      printf("   |---------------------------|\n");
   }
   else
   {
      Ponteiro ap = fila->inicio;
      int i = 0;
      while (ap != NULL)
      {
          printf("   |---------------------------|\n");
          i++;
          printf(" %d | %25s |", i, ap->elemento.nomeObjeto);
          if (fila->inicio == ap)
             printf(" <-- Inicio \n");
          else
             printf("\n");
          ap = ap->prox;
      }
      printf("   |---------------------------|\n");
      printf(" %d |                           | <-- Fim\n", ++i);
      printf("   |---------------------------|\n");
   }
   printf("\n             %s \n", msg);
}   /*  ImprimeTela  */
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
}   /*  trataErro  */
/*==============================================================================*/
