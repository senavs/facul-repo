// Autor: Vicente Teixeira

#define MAX 5

/*==============================================================================
         Estruturas do Tipo Abstrato de Dados FILA
================================================================================*/
typedef struct {
          char descrAviao[31];
          int qtComb;
}Aeronave;

typedef struct  {
   Aeronave dados[MAX];
   int inicio, fim, tamanho;
}Fila;
/*==============================================================================
       Implementação das Operações do Tipo Abstrato de Dados Fila
================================================================================*/
void iniciaFila (Fila *fila)
{
   fila->inicio = 0;
   fila->fim    = 0;
   fila->tamanho = 0;
   int j;
   for (j = 0; j < MAX; j++){
       strcpy(fila->dados[j].descrAviao, "");
       fila->dados[j].qtComb = 0;
   }
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
void enqueue(Aeronave x, Fila *fila)
{
    if (isFull(fila))
    {
        return;
    }
    fila->dados[fila->fim] = x;
    fila->fim = sucessor(fila->fim);
    fila->tamanho++;
}
/*==============================================================================*/
void dequeue (Aeronave *x, Fila *fila)
{
       if(isEmpty(fila))
       {
          return ;
       }
       *x = fila->dados[fila->inicio];
       strcpy(fila->dados[fila->inicio].descrAviao, "");
       fila->inicio = sucessor(fila->inicio);
       fila->tamanho--;
}
