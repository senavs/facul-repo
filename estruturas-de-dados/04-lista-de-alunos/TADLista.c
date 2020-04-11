/*
Implementação do Tipo Abstrato da Dados LISTA LINEAR, utilizando ARRANJO
Desenvolvido por: prof. Vicente    -    Em: 20/03/2019
*/
#include<stdlib.h>
#include<stdio.h>

#define MAX 10
// Estrutura de Dados oara ALUNO
typedef struct {
    char  nome[21];
    int   matr;
    float nota;
}Aluno;

//Estrutura de Dados da LISTA

typedef struct {
        Aluno alunos[MAX];
        int   tamanho;
}Lista;

// ============= CÓDIGOS DE ERRO DEFINIDOS NO TAD LISTA ========================
//     erro = 10 --> LISTA VAZIA (underflow de memória no arranjo)
//     erro = 20 --> Lista Cheia (overflow de memória no arranjo)
//     erro = 30 --> Aluno não encontrado
// =============================================================================

// ======================== OPERAÇÕES DO TAD LISTA =============================
// ===== criaLista =============================================================
void criaLista (Lista *lst)
{
   lst->tamanho  =  0;
}
// ===== vaziaLista ============================================================
int vaziaLista (Lista *lst)
{
    return (lst->tamanho == 0);
}
// ===== cheiaLista ============================================================
int cheiaLista (Lista *lst)
{
    return (lst->tamanho >= MAX);
}
// ===== insereLista ===========================================================
void insereLista (Aluno a, Lista *lst, int *codErro)
/*  Insere Aluno, passado pelo parâmetro a, no final da Lista  */
/*  No caso de overflow do Arranjo, retorna código de erro adequado */
{
      *codErro = 0;
      if (cheiaLista(lst)) {
          *codErro = 20;   // overflow de memória no arranjo
          return;
      }
      lst->alunos[lst->tamanho] = a;
      lst->tamanho++;
}
// ===== buxcaLista ============================================================
int buscaLista(Aluno a, Lista *lst)
//     Pesquisa (pelo nome) se Aluno a está na Lista e retorna sua posição
//     Caso não encontre, retorna -1
{
   int  pos = 0;
   while (pos < lst->tamanho) {
      if (strcmp(lst->alunos[pos].nome, a.nome)==0)
          return(pos);
      else pos++;
   }
   return(-1) ;
}
// ===== excluiLista ===========================================================
void excluiLista(Aluno a, Lista *lst, int *codErro)
/*  Pesquisa o Aluno a e o exclui da Lista;
      Se Lista Vazia, retorna codErro adequado;
      Se Aluno não encontrado, retorna codErro adequado    */
{
   *codErro = 0;
   int i, j;
   if (vaziaLista (lst)) {
      *codErro = 10;   //   Lista vazia!
      return;
   }
   i = buscaLista(a, lst);
   if  (i == -1) {
        *codErro = 30;  //  Aluno não encontrado!!!
        return;
   }
   for (j = i+1; j <= lst->tamanho; j++)  //  “Tapa buraco” !!!
        lst->alunos[j-1] = lst->alunos[j];
   lst->tamanho--;
}
// ===== imprimeLista ==========================================================
void imprimeLista(Lista *lst)
{
    int i;
    for(i = 0; i <= lst->tamanho-1; i++){
        printf("\nAluno %02d: nome = %15s,\t matr = %04d,   nota = %4.1f;",
               i+1, lst->alunos[i].nome, lst->alunos[i].matr, lst->alunos[i].nota);
    }
    printf("\n\n");
}
