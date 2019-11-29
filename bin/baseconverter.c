
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main(int argc, char* argv[])
{
        int a, b;
        char c[10];

        printf("Digite um numero: ");
        scanf("%d",&a);

        printf("Digite a base a ser convertida: ");
        scanf("%d",&b);

        itoa(a,c,b);

        printf("\nO numero %d na base %d e: %s",a,b,c);

        getch();
        return 0;
}
