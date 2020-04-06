/* Questão 1 */
#include <stdio.h>

void main()
{
    printf("Esta e\’ a linha \“um\”\nEsta e\’ a linha \“dois\’\.");
    
}

/* Questão 2 */
#include <stdio.h>

void main()
{
    int um = 1;
    int dois = 2;
    int tres = 3;
    printf("As variaveis inteiras contem os numeros: %d, %d, %d\n", um, dois, tres);
    
    char a = 'a';
    char b = 'b';
    char c = 'c';
    printf("As variaveis caracteres contem os valores:: %c, %c, %c", a, b, c);
    
}

/* Questão 3 */
#include <stdio.h>

void main()
{
    printf("\| / / / / / / \n| Linguagem\n| \“ C \”\n| / / / / / /");
    
}

/* Questão 4 */
#include <stdio.h>

void main()
{   
    int n = 15;
    printf("%8d", n);
    printf("\n%08d", n);
    printf("\n%8.4d", n);
    printf("\n%d", n);
    printf("\n%04d", n);
    
}

/* Questão 5 */
#include <stdio.h>

void main()
{   
    float n = 16.5;
    printf("%6.4f", n);
    printf("\n%7.1f", n);
    printf("\n%9.2f", n);
}

/* Questão 6 */
#include <stdio.h>

void main()
{   
    printf("Uniao Pioneira de Integracao Social");
    printf("Curso Sistemas de Informacao");
    printf("Disciplina: LTP-1");
}


/* Questão 7 */
Saída: 
1º 00987
2º 123.4560
3º _987
4º _123.4 
5º ___987

/* Questão 8 */
#include <stdio.h>

void main(){
    int x = 10;
    float a = 5.489;
    printf("\n%7.4f", a);
    printf("\n%05d", x);
    printf("\n%4.2f", a);
    printf("\n%7d", x);
    printf("\n%1.0f", x);
}