// Questão 1

#include <stdio.h>

int EDivisivel(int a, int b);

int main() {
	int n1, n2;
	printf("Digite o primeiro numero: ");
	scanf("%d", &n1);
	printf("Digite o segundo numero: ");
	scanf("%d", &n2);
	
	printf("%d", EDivisivel(n1, n2));
}

int EDivisivel(int a, int b) {
	return a % b == 0;
}

// Questão 2
#include <stdio.h>

float CtoF(float celsius);

int main() {
	int c;
	printf("Temperatura");
	for (c=0; c<41; c++) {
		printf("%d C -- %.2f F\n", c, CtoF(c));
	}
}

float CtoF(float celsius) {
	return (celsius * 9/5) + 32;
}

// Questão 3
#include <stdio.h>

int Cubo(float a);

void main() {
	int n;
	char sn;
	while (1) {
		printf("Digite um numero para ver seu cubo: ");
		scanf("%d", &n);
		printf("%d elevado a 3 é igual a: %d\n", n, Cubo(n));
		
		printf("Deseja continuar? [S/N] ");
		scanf("%s", &sn);
		if (sn == 'n') {
			break;
		} else {
			system("cls");
		}
			
	}
}

int Cubo(float a) {
	return a * a * a;
}

// Questão 4
#include <stdio.h>

int multiplicar(int a, int b) {
	int c, res = 0;
	for (c=0; c<b; c++) {
		res += a;
	}
	return res;
}

void main() {
	int n1, n2;
	printf("Digite o primeiro numero: ");
	scanf("%d", &n1);
	printf("Digite o segundo numero: ");
	scanf("%d", &n2);
	
	printf("O resultado é: %d", multiplicar(n1, n2));
}

// Questão 5
#include <stdio.h>

int maior (int a, int b, int c) {
	if (a > b) 
		if (a > c)
			return a;
		else 
			return c;
	else
		if (b > c)
			return b;
		else
			return c;

}

int menor (int a, int b, int c) {
	if (a < b)
		if (a < c) 
			return a;
		else
			return c;
	else 
		if (b < c) 
			return b;
		else 
			return c;
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
	
	printf("O maior: %d\nO menor: %d", maior(n1, n2, n3), menor(n1, n2, n3));
}


// Questão 6
#include <stdio.h>

int fatorial(int n) {
	if (n==1)
		return n;
	return fatorial(n-1) * n;
}

void main() {
	int n1;
	printf("Digite um numero: ");
	scanf("%d", &n1);
	
	system("cls");
	
	printf("O fatorial de %d é %d", n1, fatorial(n1));
}