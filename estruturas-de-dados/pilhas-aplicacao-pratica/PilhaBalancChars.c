// Autor: Vicente Teixeira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "PilhaTAD.c"

void cabecalho();
int strBalance(char *str);

int main(void)
{
	int resultado;
	char str[71];
	char ch1, ch2, opcao;
	Pilha pilha;
	do
	{
        cabecalho();
        printf("\n   Digite a string para balancear: \n\n    ");
        fflush(stdin);
        gets(str);
        resultado = strBalance(str);
        switch (resultado)
        {
           case 0:
           {
              printf("\n String: \" %s \" ==> BALANCEADA!!!\n", str);
              break;
           }
           case 1:
           {
              printf("\n String: \" %s \" ==> NAO BALANCEADA!!!\n",str);
              break;
           }
           case 2:
           {
              printf("\n Overflow de memoria. String %s NAO pode ser avaliada!!!\n",str);
              break;
           }
        } // fim switch
        printf("\n Deseja processar outra string? (S/N) ");
        opcao = toupper(getch());
    } while (opcao != 'N');
    printf ("\n\n\n     Programa encerrando!!! Obrigado \n     Aperte qualquer tecla... \n \n");
    getch();
    return 0;
}

/*==============================================================================*/
int strBalance(char *str)
//  Recebe string e verifica se está balanceada, quanto aos caracteres ( ) , { } e [ ]
//  Retorna:  0 - Balanceamento OK;   1 - Erro no Balanceamento;  2 - Overflow na pilha
{
    int i, erro = 0;
    Dados chr1, chr2;
    Pilha pilha;
    criaPilha(&pilha);
    for(i = 0; i < strlen(str); i++)
    {
       chr1.ch = str[i];
       switch (chr1.ch)
       {
          case '{':  case '[': case '(':
          {
             push(chr1, &pilha, &erro);
             if (erro != 0) return (2); // overflow de Pilha
             break;
          }
          case '}':  case ']': case ')':
          {
             pop(&chr2, &pilha, &erro);
             if (erro != 0) return (1);
             if (chr1.ch == '}' && chr2.ch != '{')
                 return (1);
             if  (chr1.ch == ']' && chr2.ch != '[')
                 return (1);
             if  (chr1.ch == ')' && chr2.ch != '(')
                 return (1);
             break;
          }
       } // fim do switch
    } // fim do for
    if (isEmpty(&pilha))
         return (0);
    else return (1);
}
/*==============================================================================*/
void cabecalho()
{
   system("cls");
   printf("\n");
   printf("  UPIS - ESTRUTURA DE DADOS                              PROF.VICENTE TEIXEIRA\n");
   printf("                      BALANCEAMENTO DE STRING APLICANDO PILHA    \n");
   printf("  ============================================================================\n\n");
}

