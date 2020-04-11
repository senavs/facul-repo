// Autor: Vicente Teixeira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TAD-ListaEncad.c"

//==============================================================================
//  PROTÓTIPOS DAS FUNÇÕES DA APLICAÇÃO
//==============================================================================
void cabecalho ();
void menu ();
void imprimeLista(Lista *lst);
//==============================================================================
int main()
{
	Lista lista;
	Elemento elemento;
	char op, continua;
    criaLista(&lista);
    do
    {
       cabecalho();
       menu();
       op = getch();
       switch (op)
       {
            case '1': case 'i':  case 'I':
            {
                do
                {
                    cabecalho();
                    printf("\n            Inserir elemento no final da lista ");
                    printf("\n\n\t Informe descricao do elemento: ");
                    fflush(stdin);
                    gets(elemento.descr);
                    insereFinal(elemento, &lista);
                    imprimeLista(&lista);
                    printf ("\n      Deseja inserir outro elemento?(S/N) ");
                    continua = toupper(getch());
                } while (continua == 'S');
                break;
            }
            case '2': case 'c':  case 'C':
            {
                do
                {
                    cabecalho();
                    printf("\n            Consultar elemento na lista ");
                    printf("\n\n\t Informe descricao do elemento: ");
                    fflush(stdin);
                    gets(elemento.descr);
                    Ponteiro pElem = buscaLista(elemento, &lista);
                    if(pElem == NULL)
                        printf("\n\t\t Elemento %s NAO existente na lista!\n", elemento.descr);
                    else
                        printf("\n\t\t Elemento %s encontrado na lista!\n", elemento.descr);
                    imprimeLista(&lista);
                    printf ("\n      Deseja consultar outro elemento?(S/N) ");
                    continua = toupper(getch());
                } while (continua == 'S');
                break;
            }
            case '3':  case 'e':  case 'E':
            {
                do
                {
                    cabecalho();
                    printf("            Excluir elemento da lista");
                    printf("\n\n\t Informe descricao do elemento: ");
                    fflush(stdin);
                    gets(elemento.descr);
                    int retorno = excluiLista(elemento, &lista);
                    if(retorno == 0)
                        printf("\n\t\t Elemento %s excluido da lista!\n", elemento.descr);
                    else
                        printf("\n\t\t Elemento %s NAO encontrado na lista!\n", elemento.descr);
                    imprimeLista(&lista);
                    printf ("\n      Deseja excluir outro elemento?(S/N) ");
                    continua = toupper(getch());
                } while (continua == 'S');
                break;
            }
            case '0':  case 'f':  case 'F':
            {
                printf ("\n\n    Programa ENCERRANDO ... Obrigado!!! \n\n");
                printf ("\t        Aperte qualquer tecla... \n");
                getch();
                break;
            }
            default:
            {
                printf ("\n\t\t Opcao invalida! ");
                printf ("\n\t\t\t Aperte qualquer tecla... \n \n");
                getch();
            }
       }  //switch
    } while ((op != '0')&&(op != 'f')&&(op != 'F'));
    return 0;
}  // fim função MAIN
//==============================================================================
void cabecalho ()
{
     system("cls");
     printf("\n");
     printf(" |===========================================================================|\n");
     printf(" |  UPIS - Sistemas de Informacao                    ED - Estrutura de Dados |\n");
     printf(" |                            Prof. Vicente Teixeira                         |\n");
     printf(" |===========================================================================|\n");
     printf(" |                    PROVA DE CONCEITO  ==  LISTA ENCADEADA                 |\n");
     printf(" |===========================================================================|\n");
}
//==============================================================================
void menu ()
{
     cabecalho();
     printf("\n\t     | = = = = = = = = MENU  PRINCIPAL = = = = = = = = = |");
     printf("\n\t     |             1 - Incluir na lista                  |");
     printf("\n\t     |             2 - Consultar na lista                |");
     printf("\n\t     |             3 - Excluir da lista                  |");
     printf("\n\t     |             0 - Finalizar aplicacao               |");
     printf("\n\t     | = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
     printf("\n\t                       Escolha uma opcao: ");
}
//==============================================================================
void imprimeLista(Lista *lst){
    printf("\n\t     | = = = = = = =  LISTAGEM COMPLETA  = = = = = = = = |");
    Ponteiro pAux = lst->inicio;
    if(pAux == NULL)
         printf("\n\t     |                   LISTA VAZIA!!!                  |");
    else{
         while(pAux != NULL){
             printf("\n\t\t %s", pAux->elemento.descr);
             pAux = pAux->prox;
         }
    }
    printf("\n\t     | = = = = = = = = = = = = = = = = = = = = = = = = = |\n");

}
