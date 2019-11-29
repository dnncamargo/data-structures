#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/* Arquivo com a função principal
Usando gcc para compilação:
$ gcc -c list.c                   #irá produzir um arquivo 'list.o'
$ gcc -c main.c                   #idem para 'main.o'
$ gcc -o main main.c list.c       #produz o executável, 'main' */

int main() {
    list ll; // Quando se usa typedef nao e necessario usar a palavra-chave struct
    ll = createlist();
    ll = insertat(ll, 1.0, 0);
    showcontent(&ll, 0);
    return 0;
}
