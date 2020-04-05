/*
   Autor: Vicente Teixeira
         O objeto da implementa��o � um Tipo Abstrato de Dados para uma Pilha,
         contemplando sua estrutura (implementada com arranjo) e as principais
         opera��es de manipula��o da pilha.
*/

// MAX � uma cosntante que define o tamanho m�ximo do arranjo da Pilha
#define MAX 70

//==============================================================================
//         Estrutura do TAD PILHA
//==============================================================================

typedef struct {
    char ch;
}Dados;

typedef struct {
    Dados vet[MAX];
    int topo;
}Pilha;

//==============================================================================
//       Implementa��o das Opera��es do TAD PILHA
//==============================================================================

void criaPilha (Pilha *pilha)
{
   pilha->topo =  0;
}
//==============================================================================
int isEmpty (Pilha *pilha)
{
    return (pilha->topo <= 0);
}
//==============================================================================
int isFull (Pilha *pilha)
{
    return (pilha->topo >= MAX);
}
//==============================================================================
void push(Dados x, Pilha *pilha, int *codErro)
/* Insere o objeto x no topo da Pilha     */
/* Condi��o de Erro = 20 - Pilha cheia   */
{
    *codErro = 0;
    if (isFull(pilha))
    {
	    *codErro = 20;     //  Erro cod 20 - Pilha Cheia
        return;
    }
    pilha->vet[pilha->topo] = x;   // insere x no topo da Pilha
    pilha->topo++;                // atualiza marca do topo da Pilha
}
//==============================================================================
void  pop (Dados *x, Pilha *pilha, int *codErro)
/* Exclui  o objeto localizado no topo da Pilha             */
/* Retorna este objeto para o chamador pelo par�metro x    */
/* Condi��o de Erro = 10 - Pilha vazia                    */
{
       *codErro = 0;
       if(isEmpty(pilha))
       {
          *codErro = 10;         //  Erro cod 10 - Pilha Vazia
          return ;
       }
       *x = pilha->vet[pilha->topo - 1];  // captura elemento do topo da Pilha
       pilha->topo--;                    // atualiza marca do topo da Pilha
}
//==============================================================================
void peek(Dados *x, Pilha *pilha, int *codErro)
//   Recupera Objeto do topo da Pilha, sem retir�-lo
//   Retorna este Objeto ao chamador pelo par�metro x
{
    if(isEmpty(pilha))
    {
        *codErro = 10;       //  Erro cod 10 - Pilha Vazia
        return ;
    }
    *x = pilha->vet[pilha->topo - 1];  // captura elemento do topo da Pilha
}
