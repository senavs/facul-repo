// Autor: Vicente Teixeira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "TAD-Fila-Simul.c"
#include "TAD-Log-Eventos.c"

void cabecalho ();
void imprimeFila (Fila *fila, char tipo[]);
Aeronave iniciaAeronave();
int sorteiaEvento();

int main(void)
{
	Aeronave aviao;
	Fila pouso, decol, emerg;
	Eventos logEv;
	char regEvento[71];

    iniciaFila(&pouso);
    iniciaFila(&decol);
    iniciaFila(&emerg);
    iniciaEventos(&logEv);
    srand(time(NULL));
    int contTempo = 0;
    int sorte;
    char continuar;
    do
    {
       strcpy(regEvento, "");
       contTempo++;
       if(!isEmpty(&emerg)){ // EMERGÊNCIA !!! OBRIGATÓRIO POUSAR AERONAVE EM EMERGÊNCIA
           dequeue(&aviao, &emerg);
           strcpy(regEvento, aviao.descrAviao);
           strcat(regEvento, " pousou. EM EMERGENCIA!!!");
       }
       else  // SEM EMERGÊNCIA - SORTEAR EVENTO DESTE INSTANTE DE TEMPO
       {
           sorte = sorteiaEvento();
           switch (sorte)
           {
                case 1:  // AVIÃO ENTRANDO NA FILA DE POUSO
                {
                    aviao = iniciaAeronave();
                    if(aviao.qtComb < (pouso.tamanho+decol.tamanho+3))  // TEM POUCO COMBUSTÍVEL - EMERGÊNCIA
                    {
                        enqueue(aviao, &emerg);
                        strcpy(regEvento, aviao.descrAviao);
                        strcat(regEvento, " entrou na fila de EMERGENCIA!!!");
                        break;
                    }
                    if (isFull(&pouso))    // FILA DE POUSO CHEIA
                    {
                        strcpy(regEvento, "Pedido para POUSO com fila CHEIA.");
                        break;
                    }
                    enqueue(aviao, &pouso);
                    strcpy(regEvento, aviao.descrAviao);
                    strcat(regEvento, " entrou na fila de POUSO.");
                    break;
               }
               case 2:  // AVIÃO ENTRANDO NA FILA DE DECOLAGEM
               {
                   if (isFull(&decol))
                   {
                        strcpy(regEvento, "Pedido para DECOLAGEM com fila CHEIA.");
                        break;
                    }
                    aviao = iniciaAeronave();
                    enqueue(aviao, &decol);
                    strcpy(regEvento, aviao.descrAviao);
                    strcat(regEvento, " entrou na fila de DECOLAGEM.");
                    break;
                }
                case 3:   // AVIÃO POUSANDO
                {
                    if (isEmpty(&pouso))
                    {
                        strcpy(regEvento, "Tentativa de POUSO com fila VAZIA.");
                        break;
                    }
                    dequeue(&aviao, &pouso);
                    strcpy(regEvento, aviao.descrAviao);
                    strcat(regEvento, " POUSOU.");
                    break;
                }
                case 4:   // AVIÃO DECOLANDO
                {
                    if(isEmpty(&decol)){
                        strcpy(regEvento, "Tentativa de DECOLAGEM com fila VAZIA.");
                        break;
                    }
                    dequeue(&aviao, &decol);
                    strcpy(regEvento, aviao.descrAviao);
                    strcat(regEvento, " DECOLOU.");
                    break;
                }
                default  :  strcpy(regEvento, "Situacao nao prevista.");
           }  // FIM DO BLOCO switch
       }  // FIM DO BLOCO else
       registraEventos (&logEv, regEvento, contTempo);
       if (contTempo % 5 == 0) {  // DISPLAY GERAL A CADA 5 UNID. DE TEMPO
           cabecalho();
           imprimeFila(&pouso, "Pouso");
           imprimeFila(&decol, "Decolagem");
           imprimeFila(&emerg, "Emergencia");
           imprimeEventos(&logEv);
           iniciaEventos(&logEv);
           printf("\n Aperte qualquer tecla para continuar - 0 para ENCERRAR SIMULACAO.");
           continuar = getch();
       }
    }
    while (continuar != '0' && contTempo < 1000);
    printf ("\n\n\n     Programa encerrando!!! Obrigado \n     Aperte qualquer tecla...\n\n");
//    getch();
    return 0;
} /*  main */

/*==============================================================================*/
void cabecalho ()
{
     system("cls");
     printf("\n                         UPIS - Sistemas de Informacao      \n");
     printf(" ED - Estrutura de Dados                              Prof. Vicente Teixeira\n");
     printf("                     CONTROLE DE TRAFEGO AEREO - SIMULADO           \n");
     printf(" ----------------------------------------------------------------------------\n");
} /*  cabecalho  */

/*==============================================================================*/
void imprimeFila (Fila *fila, char tipo[])
{
   int i;
   printf("\nFila de %s:\n", tipo);
   for (i = 0; i<MAX; i++)
   {
       printf("   |---------------------------|\n");
       if (strcmp(fila->dados[i].descrAviao, "") != 0)
           printf(" %d | %25s | ", i, fila->dados[i].descrAviao);
       else
           printf(" %d |                           | ", i);
       if (fila->inicio == i && fila->fim == i)
          printf(" <-- Inicio/Fim \n");
       else if (fila->inicio == i)
          printf(" <-- Inicio \n");
       else if (fila->fim == i)
          printf(" <-- Fim \n");
       else
          printf(" \n");
   }
   printf("   |---------------------------|\n");
}
/*==============================================================================*/
Aeronave iniciaAeronave(){
    Aeronave a;
    char nomeAviao[21];
    int sorteio = rand()%4;
    switch (sorteio) {
         case 0: strcpy(nomeAviao, "AZUL"); break;
         case 1: strcpy(nomeAviao, "AVIANCA"); break;
         case 2: strcpy(nomeAviao, "GOL"); break;
         case 3: strcpy(nomeAviao, "LATAM"); break;
    }
    strcat(nomeAviao, "-");
    char seq[4];
    int digito, i;
    for(i=0; i< 3; i++){
        digito = rand()%10;
        seq[i] =  digito + '0';
    }
    seq[3] = '\0';
    strcat(nomeAviao, seq);
    strcpy(a.descrAviao, nomeAviao);
    a.qtComb = rand()%100+1;
    return a;
}
/*==============================================================================*/
int sorteiaEvento(){
    int evento = rand() % 100 + 1;
    if(evento >=  1 && evento <= 33) return 1;    // 33% para ENTRAR FILA POUSO
    if(evento >= 34 && evento <= 60) return 2;   // 27% para ENTRAR FILA DECOLAGEM
    if(evento >= 61 && evento <= 80) return 3;  // 20% para POUSAR AVIAO
    return 4;                                  // 20% para DECOLAR AVIAO
}
