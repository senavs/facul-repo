/*
   Autor: Vicente Teixeira
         O objeto da implementação é um Tipo Abstrato de Dados para uma Pilha,
         contemplando sua estrutura (implementada com arranjo) e as principais
         operações de manipulação da pilha.
*/

// MAX é uma cosntante que define o tamanho máximo do arranjo da Pilha
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
//       Implementação das Operações do TAD PILHA
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
/* Condição de Erro = 20 - Pilha cheia   */
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
/* Retorna este objeto para o chamador pelo parâmetro x    */
/* Condição de Erro = 10 - Pilha vazia                    */
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
//   Recupera Objeto do topo da Pilha, sem retirá-lo
//   Retorna este Objeto ao chamador pelo parâmetro x
{
    if(isEmpty(pilha))
    {
        *codErro = 10;       //  Erro cod 10 - Pilha Vazia
        return ;
    }
    *x = pilha->vet[pilha->topo - 1];  // captura elemento do topo da Pilha
}
