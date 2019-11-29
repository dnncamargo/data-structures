#include<stdio.h>
#include"arrays.h"

/* Arquivo com a função principal
Usando gcc para compilação:
$ gcc -c arrays.c                   #irá produzir um arquivo 'arrays.o'
$ gcc -c main.c                     #idem para 'main.o'
$ gcc -o main main.c arrays.c       #produz o executável, 'main' */

int main(){
    char input0[256], input1[10];
    char *output;
    printf("Digite uma palavra\n");
    scanf("%[^\n]", input0);
    getchar();
    //printf("Digite uma palavra\n");
    //scanf("%[^\n]", input1);
    //getchar();
    output = remchar(input0, ' ');
    if(output != NULL){
        printf("%s\n", output);
    } else {
        printf("ERROR\n");
    }
}
