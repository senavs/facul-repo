// Autor: Vicente Teixeira

// MAX é uma constante que define o tamanho máximo da Fila
#define MAX 5

/*==============================================================================
         Estruturas do Tipo Abstrato de Dados FILA
================================================================================*/

// struct para definir um Objeto genérico, descrito pelo seu nome
typedef struct {
          char nomeObjeto[21];
          // outros campos aderentes ao problema considerado
}Dados;

// struct para definir a Fila, um vetor de Dados e um índice que marca o início
// e outro que marca o fim da Fila
typedef struct {
   Dados dados[MAX];
   int inicio, fim;
}Fila;

/*==============================================================================
       Implementação das Operações do Tipo Abstrato de Dados Fila
================================================================================*/

void iniciaFila (Fila *fila)
{
   fila->inicio = 0;
   fila->fim    = 0;
   int j;
   for (j = 0; j < MAX; j++)
       strcpy(fila->dados[j].nomeObjeto, "");
}
/*==============================================================================*/
int sucessor (int pos)
{
     return ((++pos) % MAX);   // Uso de ARITMÉTICA MODULAR
}
/*==============================================================================*/
int isEmpty (Fila *fila)
{
    return (fila->fim == fila->inicio);
}
/*==============================================================================*/
int isFull (Fila *fila)
{
    return (sucessor(fila->fim) == fila->inicio);
}
/*==============================================================================*/
void enqueue(Dados x, Fila *fila, int *codErro)
{
    *codErro = 0;
    if (isFull(fila))
    {
	    *codErro = 20;     //  Erro cod 20 - Fila Cheia
        return;
    }
    fila->dados[fila->fim] = x;
    fila->fim = sucessor(fila->fim);
}
/*==============================================================================*/
void dequeue (Dados *x, Fila *fila, int *codErro)
{
       *codErro = 0;
       if(isEmpty(fila))
       {
          *codErro = 10;         //  Erro cod 10 - Fila Vazia
          return ;
       }
       *x = fila->dados[fila->inicio];
       strcpy(fila->dados[fila->inicio].nomeObjeto, "");
       fila->inicio = sucessor(fila->inicio);
}
