/*
Implementa��o do Tipo Abstrato da Dados LISTA LINEAR, utilizando ARRANJO
Desenvolvido por: prof. Vicente    -    Em: 31/03/2019
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

// ============= C�DIGOS DE ERRO DEFINIDOS NO TAD LISTA ========================
//     erro = 10 --> LISTA VAZIA (underflow de mem�ria no arranjo)
//     erro = 20 --> Lista Cheia (overflow de mem�ria no arranjo)
//     erro = 30 --> Aluno n�o encontrado
//     erro = 40 --> Posi��o inv�lida
// =============================================================================

// ======================== OPERA��ES DO TAD LISTA =============================
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
/*  Insere Aluno, passado pelo par�metro a, no final da Lista  */
/*  No caso de overflow do Arranjo, retorna c�digo de erro adequado */
{
      *codErro = 0;
      if (cheiaLista(lst)) {
          *codErro = 20;   // overflow de mem�ria no arranjo
          return;
      }
      lst->alunos[lst->tamanho] = a;
      lst->tamanho++;
}
// ===== insereNaPos ===========================================================
void insereNaPos (int i, Aluno a, Lista *lst, int *codErro)
/*  Insere Aluno, passado pelo par�metro a, na posi��o passada pelo param i  */
/*  No caso de overflow do Arranjo, retorna c�digo de erro adequado          */
/*  No caso de posi��o inv�lida, retorna c�digo de erro adequado          */
{
      *codErro = 0;
      if (cheiaLista(lst)) {
          *codErro = 20;   // overflow de mem�ria no arranjo
          return;
      }
      if (i < 0 || i > lst->tamanho) {
          *codErro = 40;   // posi��o inv�lida para inser��o
          return;
      }
      if (i == lst->tamanho)
          insereLista(a, lst, codErro);
      else {
          int j;
          for(j = lst->tamanho; j > i; j--)
              lst->alunos[j] = lst->alunos[j-1];
          lst->alunos[i] = a;
          lst->tamanho++;
      }
}
// ===== buxcaLista ============================================================
int buscaLista(Aluno a, Lista *lst)
//     Pesquisa (pelo nome) se Aluno a est� na Lista e retorna sua posi��o
//     Caso n�o encontre, retorna -1
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
      Se Aluno n�o encontrado, retorna codErro adequado    */
{
   *codErro = 0;
   int i, j;
   if (vaziaLista (lst)) {
      *codErro = 10;   //   Lista vazia!
      return;
   }
   i = buscaLista(a, lst);
   if  (i == -1) {
        *codErro = 30;  //  Aluno n�o encontrado!!!
        return;
   }
   for (j = i+1; j < lst->tamanho; j++)  //  �Tapa buraco� !!!
        lst->alunos[j-1] = lst->alunos[j];
   lst->tamanho--;
}
// ===== excluiDaPos ===========================================================
void excluiDaPos(int i, Lista *lst, int *codErro)
/*  Verifica se posi��o i � v�lida, caso afirmativo exclui elemento desta posi��o. */
{
   *codErro = 0;
   int j;
   if (vaziaLista (lst)) {
      *codErro = 10;   //   Lista vazia!
      return;
   }
   if  (i < 0 || i >= lst->tamanho) {
        *codErro = 40;  //  posi��o inv�lida para exclus�o!!!
        return;
   }
   for (j = i+1; j < lst->tamanho; j++)  //  �Tapa buraco� !!!
        lst->alunos[j-1] = lst->alunos[j];
   lst->tamanho--;
}
// ===== modifica ===========================================================
void modifica(int i, Aluno a, Lista *lst, int *codErro)
/*  Verifica se posi��o i � v�lida, caso afirmativo substitui elemento nesta posi��o. */
{
   *codErro = 0;
   if (vaziaLista (lst)) {
      *codErro = 10;   //   Lista vazia!
      return;
   }
   if  (i < 0 || i >= lst->tamanho) {
        *codErro = 40;  //  posi��o inv�lida para sobreposicao!!!
        return;
   }
   lst->alunos[i] = a;
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
// ===== ordenaLista ==========================================================
Lista ordenaLista(Lista lst)
{
    int i, j;
    Aluno al;
    for(i = 0; i <= lst.tamanho-2; i++)
        for(j = i+1; j <= lst.tamanho-1; j++)
            if(strcmp(lst.alunos[j].nome, lst.alunos[i].nome) < 0) {
               al            = lst.alunos[i];
               lst.alunos[i] = lst.alunos[j];
               lst.alunos[j] = al;
            }
    return lst;
}
