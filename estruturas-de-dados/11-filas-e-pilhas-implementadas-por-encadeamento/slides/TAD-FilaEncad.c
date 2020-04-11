// Autor: Vicente Teixeira


/*==============================================================================
         Estruturas do TAD FILA
================================================================================*/

// struct para definir um Objeto genérico, descrito pelo seu nome e descrição
typedef struct {
          char nomeObjeto[21];
          // aqui pode vir outros atributos aderentes ao problema considerado
}Elemento;

// struct para definir a Fila, uma celula com um Ponteiro para celula
typedef struct Cel * Ponteiro;

typedef struct Cel {
        Elemento elemento;
        Ponteiro prox;
} Celula;

typedef struct  {
        Ponteiro inicio, fim;
        int tamanho;
} Fila;
/*==============================================================================
       Implementação das Operações do TAD Fila
================================================================================*/
void iniciaFila (Fila *fila)
{
      fila->inicio  = NULL;
      fila->fim     = fila->inicio;
      fila->tamanho = 0;
}
/*==============================================================================*/
int isEmpty (Fila *fila)
{
    return (fila->inicio == NULL);
}
/*==============================================================================*/
void enqueue (Elemento x, Fila *fila)
{
      Ponteiro pAux;
      pAux = (Ponteiro)malloc(sizeof (Celula));
      pAux->elemento = x;
      pAux->prox = NULL;
      if (isEmpty(fila))
            fila->inicio = pAux;
      else
             fila->fim->prox = pAux;
      fila->fim = pAux;
      fila->tamanho++;
}
/*==============================================================================*/
int dequeue(Elemento *x, Fila *fila)
{
     if (isEmpty(fila))       //Passo 0
            return  999;       // Código para fila vazia
     Ponteiro primeiro = fila->inicio;       //Passo 1
     *x = primeiro->elemento;
     fila->inicio = fila->inicio->prox;   //Passo 2
     fila->tamanho--;                            //Passo 3
     if(fila->fim == primeiro)             //Passo 4
          fila->fim = NULL;
     free (primeiro);
     return 0;     // Desempilhou com sucesso
}


