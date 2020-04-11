// Autor: Vicente Teixeira
/*==============================================================================
         Estruturas do TAD Log-Eventos
================================================================================*/
typedef struct {
          int tempo;
          char descrEvento[71];
}Evento;

typedef struct {
   Evento eventos[20];
   int tamanho;
}Eventos;
/*==============================================================================*/
void iniciaEventos (Eventos *ev)
{
    int j;
    for (j = 0; j < ev->tamanho; j++)
         strcpy(ev->eventos[j].descrEvento, "");
    ev->tamanho = 0;
}
/*==============================================================================*/
void registraEventos (Eventos *ev, char* descr, int t)
{
    ev->eventos[ev->tamanho].tempo = t;
    strcpy(ev->eventos[ev->tamanho].descrEvento, descr);
    ev->tamanho++;
}
/*==============================================================================*/
void imprimeEventos (Eventos *ev)
{
    int i;
    printf("\nLog de Eventos:");
    printf("\n  |==============|=============================================");
    printf("\n  |  UNID TEMPO  |         DESCRICAO");
    printf("\n  |==============|=============================================");
    for (i = 0; i < ev->tamanho; i++)
    {
        printf("\n  |     %4d     | %s", ev->eventos[i].tempo, ev->eventos[i].descrEvento);
    }
    printf("\n  |==============|=============================================\n\n");
}

