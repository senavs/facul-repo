// Autor: Vicente Teixeira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TAD-Fila-ArranjoCirc.c"

void cabecalho ();
void linhaMenu ();
void imprimeAtendido(Aeronave atendida, char acao[]);
void imprimeFila (Fila *fila, char tipo[]);
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
	Aeronave aviao;
	Fila pouso, decol, emerg;
	char acao[31];

    iniciaFila(&pouso);
    iniciaFila(&decol);
    iniciaFila(&emerg);
    codErro = 10;  // Fila Vazia
    strcpy(aviao.descrAviao, " ");
    strcpy(acao, " ");
    do
    {
       cabecalho();
       imprimeAtendido(aviao, acao);
       imprimeFila(&pouso, "Pouso");
       imprimeFila(&decol, "Decolagem");
       imprimeFila(&emerg, "Emergencia");0
       trataErro (codErro);
       linhaMenu();
       opcao = getch();
       codErro = 0;
       switch (opcao)
       {
            case '1':
            {
                if (isFull(&pouso))
                {
                   codErro = 20;
                   break;
                }
                printf ("\n\n Informe o nome da aeronave: ");
                fflush(stdin);
                gets(aviao.descrAviao);
                enqueue(aviao, &pouso, &codErro);
                strcpy(acao, "entrou na FILA de POUSO!");
                break;
            }
            case '2':
            {
                if (isFull(&decol))
                {
                   codErro = 20;
                   break;
                }
                printf ("\n\n Informe o nome da aeronave: ");
                fflush(stdin);
                gets(aviao.descrAviao);
                enqueue(aviao, &decol, &codErro);
                strcpy(acao, "entrou na FILA de DECOLAGEM!");
                break;
            }
            case '3':
            {
                if (isFull(&emerg))
                {
                   codErro = 20;
                   break;
                }
                printf ("\n\n Informe o nome da aeronave: ");
                fflush(stdin);
                gets(aviao.descrAviao);
                enqueue(aviao, &emerg, &codErro);
                strcpy(acao, "entrou na FILA de EMERGENCIA!");
                break;
            }
            case '4':
            {
                if(!isEmpty(&emerg)){
                    dequeue(&aviao, &emerg, &codErro);
                    strcpy(acao, "acabou de POUSAR!");
                }
                else{
                    dequeue(&aviao, &pouso, &codErro);
                    strcpy(acao, "acabou de POUSAR!");
                }
                break;
            }
            case '5':
            {

                if(!isEmpty(&emerg)){
                    dequeue(&aviao, &emerg, &codErro);
                    strcpy(acao, "acabou de POUSAR!");

                }
                else{
                    dequeue(&aviao, &decol, &codErro);
                    strcpy(acao, "acabou de DECOLAR!");

                }
                break;
            }
            case '0' :  break;
            default  :  codErro = 99;
       }
    }
    while (opcao != '0');
    printf ("\n\n\n     Programa encerrando!!! Obrigado \n     Aperte qualquer tecla...\n\n");
    getch();
    return 0;
} /*  main */

/*==============================================================================*/
void cabecalho ()
{
     system("cls");
     printf("\n                         UPIS - Sistemas de Informacao      \n");
     printf(" ED - Estrutura de Dados                               Prof. Vicente Teixeira\n");
     printf("                           CONTROLE DE TRAFEGO AEREO            \n");
     printf(" ----------------------------------------------------------------------------\n\n");
} /*  cabecalho  */

/*==============================================================================*/
void linhaMenu()
{
  printf("\n 1=Entrar Pouso|2=Entrar Decolagem|3=Emergencia|4=Pousar|5=Decolar|0=Encerrar\n");
  printf("\n                 Escolha a opcao: ");
}
/*==============================================================================*/
void imprimeAtendido(Aeronave atendida, char* acao)
{
  printf("\n\t %s %s",  atendida.descrAviao, acao);
}
/*==============================================================================*/
void imprimeFila (Fila *fila, char tipo[])
{
   int i;
   printf("\nFila de %s:\n", tipo);
   for (i = 0; i<MAX; i++)
   {
       printf("   |---------------------------|\n");
       if (strcmp(fila->dados[i].descrAviao, "") != 0)
           printf(" %d | %25s | ", i, fila->dados[i].descrAviao);
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


