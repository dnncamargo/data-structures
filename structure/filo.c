#include <stdio.h>
#include <stdlib.h>

typedef struct {
    node prox;
    int num;
} node;

int vazia (node *PILHA) {
    if(PILHA->prox == NULL)
        return 1;
    else return 0;
}

node *aloca(){
    node *novo= (node*) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } else {
        printf("Novo elemento:");
        scanf("%d", &novo->num);
    }
}

int main(){
    node pi;
    pi = aloca();

}
