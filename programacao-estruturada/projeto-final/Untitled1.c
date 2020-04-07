#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada.c"

typedef struct restalrante {
	char nome[30];
	char endereco[50];
	char tipo[50];
	int nota;
} Restalrante;


int menu_principal(){
	
	printf("----------------------------------------\n");
	printf("|             Revista 4 Pneus          |\n");
	printf("|  Sistema de Gestão de Restaurantes   |\n");
	printf("|             Menu Principal           |\n");
	printf("----------------------------------------\n");
	
	printf("1 - Cadastrar restaurante\n");
	printf("2 - Modificar nota de restaurante\n");
	printf("3 - Excluir restaurante\n");
	printf("4 - Listar restaurantes por tipo\n");
	printf("5 - Listar restaurantes por nota\n");
	printf("0 - Encerrar\n\n");
	
	printf("Escolha uma opcao: ");
	
	int opcao;
	scanf("%d", &opcao);
	
	if (opcao >= 0 && opcao < 6)
		return opcao;
	else
		return -1;
	
}

void main() {
	int opcao;
	Lista lista;
	criaLista(&lista);
	Elemento elemento;
	
	while (1) {
		system("cls");
		opcao = menu_principal();
		
		if (opcao == 0)
			break;
			
		Restalrante rest;
		system("cls");
		switch (opcao) {
			case 1:
				printf("Nome do restalrante: ");
				scanf("%s", &rest.nome);
				printf("Endereco do restalrante: ");
				scanf("%s", &rest.endereco);
				printf("Tipo do restalrante: ");
				scanf("%s", &rest.tipo);
				printf("Nota do restalrante: ");
				do {
					printf("Nota do restalrante [0-5]: ");
					scanf("%d", &rest.nota);
				} while (rest.nota < 0 || rest.nota > 5);
				
				
				
				printf("Restalrante cadastrado com sucesso\n");
				system("pause");
				break;
		}
	}
	
	system("cls");
	printf("Volte sempre", opcao);
}

