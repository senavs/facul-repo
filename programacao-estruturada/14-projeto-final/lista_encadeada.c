#include <stdlib.h>
// Autor: Vicente Teixeira

//================================================================================
//         Estruturas do Tipo Abstrato de Dados LISTA
//================================================================================
typedef struct {
    char descr[26];
}Elemento;

typedef struct Cel * Ponteiro;
typedef struct Cel {
      Elemento elemento;
      Ponteiro prox;
}Celula;

typedef struct {
       Ponteiro inicio, fim;
       int tamanho;
}Lista;
//==============================================================================
//     Implementação das Operações do Tipo Abstrato de Dados Lista
//==============================================================================
void criaLista (Lista *lst)
{
   lst->inicio = NULL;
   lst->fim    = lst->inicio;
   lst->tamanho    =  0;
}
//==============================================================================
int vazia (Lista *lst)
{
    return (lst->inicio == NULL);
}
//==============================================================================
void insereFinal(Elemento elem, Lista *lst)
{
    Ponteiro pAux  = (Ponteiro)malloc(sizeof (Celula));  // Passo1
    pAux->elemento = elem;           // Passo2
    pAux->prox = NULL;            // Passo3
    if (vazia(lst))              // Passo4
        lst->inicio    = pAux;
    else
        lst->fim->prox = pAux;
    lst->fim = pAux;          // Passo5
    lst->tamanho++;          // Passo6

}
//==============================================================================
Ponteiro buscaLista(Elemento elem, Lista *lst)
{
     Ponteiro pAux = lst->inicio;
     while(pAux != NULL)
     {
         if (strcmp(pAux->elemento.descr, elem.descr) == 0)
             return pAux;
         else
             pAux = pAux->prox;
     }
     return pAux;
}
//==============================================================================
int excluiLista(Elemento elem, Lista *lst)
{
    Ponteiro pAux, pAux1;
    pAux = buscaLista(elem, lst);
    if(pAux == NULL)
        return 999;   // Elemento não encontrado
    if(pAux == lst->inicio){    // Exclusão do 1º elemento
        lst->inicio = lst->inicio->prox;           // Passo1
        if(lst->inicio == NULL)
           lst->fim = NULL;  // Ajusta FIM se a lista se tornar vazia
    }
    else {   // Exclusão de elemento que não o 1º
         pAux1 = lst->inicio;   // Passo 0
         while(pAux1->prox != pAux)
             pAux1 = pAux1->prox;
         pAux1->prox = pAux->prox;     // Passo 1
         if(lst->fim == pAux)
            lst->fim = pAux1;   //Ajusta FIM se for exclusão do último elemento
    }
    free(pAux);         // Passo 2
    lst->tamanho--;    // Passo 3
    return 0;         //  Exclusão realizada com sucesso!!!
}
