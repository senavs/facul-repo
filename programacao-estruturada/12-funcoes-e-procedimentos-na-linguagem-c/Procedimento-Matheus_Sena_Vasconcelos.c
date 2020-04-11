// Questão 1
#include <stdio.h>

int zerar(int *n) {
	*n = 0;
}

void main() {
	int n1;
	printf("Digite um numero: ");
	scanf("%d", &n1);
	
	system("cls");
	
	printf("A variável n1, que antes era %d, ", n1);
	zerar(&n1);
	printf("agora é igual a %d", n1);
}

//Questão 2
#include <stdio.h>

int quadrado_e_cubo(int n, int *quadrado, int *cubo) {
	*quadrado = n * n;
	*cubo = n * n * n;
}

void main() {
	int n1;
	printf("Digite um numero inteiro: ");
	scanf("%d", &n1);
	
	system("cls");
	
	int quadrado, cubo;
	quadrado_e_cubo(n1, &quadrado, &cubo);
	printf("Número: %d\nQuadrado: %d\nCubo: %d", n1, quadrado, cubo);

}

//Questão 3
#include <stdio.h>

int dividir(int *dividendo, int *divisor, int *resultado, int *resto) {
	*resto = *dividendo % *divisor;
	*resultado = *dividendo / *divisor;
}

void main() {
	int dividendo, divisor;
	printf("Digite o dividendo: ");
	scanf("%d", &dividendo);
	printf("Digite o divisor: ");
	scanf("%d", &divisor);
	
	system("cls");
	
	int resultado, resto;
	dividir(&dividendo, &divisor, &resultado, &resto);
	printf("%d divido por %d é igual a %d com resto %d", dividendo, divisor, resultado, resto);
}

// Questão 4
#include <stdio.h>

int troca(int *a, int *b) {
	int aux; 
	aux = *a;
	*a = *b;
	*b = aux;
}

int ordenar(int *a, int *b, int *c) {
	if (*a < *b) {
		if (*b < *c) {
			// abc
			int pass;
		} else {
			if (*a < *c) {
				// cab
				troca(&a, &b);
				troca(&b, &c);
			} else {
				// acb
				troca(&b, &c);
			}
		}
	} else {
		if (*a < *c) {
			if (*b < *c) {
				// bca
				troca(&a, &b);
				troca(&a, &c);
			} else {
				// cba
				troca(&a, &c);
			}
		} else {
			// bac
			troca(&a, &b);
		}
	}
}


void main() {
	int n1, n2, n3;
	printf("Digite o primeiro numero: ");
	scanf("%d", &n1);
	printf("Digite o segundo numero: ");
	scanf("%d", &n2);
	printf("Digite o terceiro numero: ");
	scanf("%d", &n3);
	
	system("cls");
	
	ordenar(&n1, &n2, &n3);
	
	printf("%d %d %d ", n1, n2, n3);
	

}