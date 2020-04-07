// Questão 1
#include <stdio.h>
#include <string.h>

typedef struct pessoa
	{
		char nome[50];
		float peso;
		float altura;
	} Pessoa;

float IMC(Pessoa* p) {
	return p->peso/(p->altura * p->altura);
};

void main() {
	int c;
	char nome;
	float peso, altura;
	Pessoa p;
	for (c=0; c<3; c++) {
		printf("Digite o nome da pessoa: \n");
		scanf("%s", &nome);
		strcpy(p.nome, &nome);
		printf("Digite o peso de %s: \n", p.nome);
		scanf("%f", &peso);
		p.peso = peso;
		printf("Digite a altura de %s: \n", p.nome);
		scanf("%f", &altura);
		p.altura = altura;
		
		printf("IMC de %s e: %f\n", p.nome, IMC(&p));
		
		system("pause");
		system("cls");
	}
};


// Questão 2
#include <stdio.h>
#include <math.h>

typedef struct ponto {
	int x;
	int y;
} Ponto;

float distancia_Pitagoras(Ponto *ponto_principal, Ponto *outro_ponto) {
	return pow((ponto_principal->x - outro_ponto->x) + (ponto_principal->y - outro_ponto->y), 2);
}

Ponto menor_distancia_de_todos(Ponto ponto_principal, Ponto lista_ponto[], int qt_ponto) {
	int c;
	float menor_distancia, distancia;
	Ponto menor_ponto;
	for (c=0; c<qt_ponto; c++) {
			distancia = distancia_Pitagoras(&ponto_principal, &lista_ponto[c]);
		if (c==0) {
			menor_distancia = distancia;
			menor_ponto = lista_ponto[c];
		}
		else {
			if (distancia < menor_distancia) {
				menor_distancia = distancia;
				menor_ponto = lista_ponto[c];
			}
		}	
	}
	
	return menor_ponto;
	
}

void main(){
	Ponto ponto_principal, outro_ponto, lista_ponto[3], menor_ponto;
	int c;

	printf("Digite o X do pronto principal: ");
	scanf("%d", &ponto_principal.x);
	printf("Digite o Y do pronto principal: ");
	scanf("%d", &ponto_principal.y);

	system("cls");

	for (c=1; c<4; c++)	{
		printf("Digite o X do %dº ponto: ", c);
		scanf("%d", &outro_ponto.x);
		printf("Digite o Y do %dº ponto: ", c);
		scanf("%d", &outro_ponto.y);
		lista_ponto[c-1] = outro_ponto;

		system("cls");
	}
	
	menor_ponto = menor_distancia_de_todos(ponto_principal, lista_ponto, 3);
	printf("Ponto com menor distancia: (%d, %d)", menor_ponto.x, menor_ponto.y);
}

// Questão 3
#include <stdio.h>
#include <math.h>

typedef struct livro {
	char nome[30];
	char autor[20];
} Livro;

int pesquisa_livro(char livro_desejado[30], Livro lista_livro[], int qt_livro) {
	int c;
	Livro livro_atual;
	for (c=0; c<qt_livro; c++) {
		livro_atual = lista_livro[c];
		if (livro_desejado == livro_atual.nome) {
			return 1;
		}
	}
	return 0;
}

void main(){
	int c;
	Livro l, lista_livro[5];
	for (c=0; c<5; c++) {
		printf("Digite o nome do %d livro: ", c+1);
		scanf("%s\n", &l.nome);
		printf("Digite o nome do autor: ", c+1);
		scanf("%s\n", &l.autor);
		lista_livro[c] = l;
		system("cls");
	}
	
	char nome_pesquisa[20];
	while (1) {
		printf("Nome para pesquisar: ");
		scanf("%s\n", &nome_pesquisa);
		printf("%d", pesquisa_livro(nome_pesquisa, lista_livro, 5));
		system("cls");
	}
}

// Questão 5
#include <stdio.h>
#include <stdlib.h>


typedef struct produto {
	int cod;
	double preco;
	int estoque;
} Produto;

int pega_menor(Produto *lista_p) {
	int menor_cod, c;
	Produto p;
	for (c=0; c<50; c++) {
		p = lista_p[c];
		if (c==0) {
			menor_cod = p.cod;
		} else {
			if (p.cod < menor_cod) {
				menor_cod = p.cod;
			} 
		}
	}

	return menor_cod;
}

void main(){
	srand(time(NULL)); 
	Produto p, lista_p[50];

	int c;
	for (c=0; c<50; c++) {
		p.cod = (rand() % (4000 - 1000 + 1) + 1000);
		p.preco = (rand() % (100 - 1 + 1) + 1);
		p.estoque = rand() % 1001;
		lista_p[c] = p;
	}

	printf("Produto com menor Codigo: %d \n", pega_menor(&lista_p));

}