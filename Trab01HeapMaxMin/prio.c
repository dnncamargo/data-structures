#include <stdio.h>
#include <stdlib.h>
#include "prio.h"

/*
 * Function: create(int)
 * -----------------------------------
 *   Cria a estrutura principal
 *
 *   @param tamanho total do vetor
 *   @returns ponteiro para a estrutura criada
 */
Fprio* create(int length) {

    // criar a estrutura principal
    Fprio* fp = malloc (sizeof(Fprio));

    // criar os nodos do vetor
    fp-> vdata = malloc (sizeof(Node) * length);
    fp-> n = 0;
    fp-> len = length;
    return fp;
}

/*
 * Function: Node* createnode(float, int)
 * -----------------------------------
 *   Funcao para criar novo Node e atribuir valores informados por parametro
 *
 *   @param val Valor do elemento
 *   @param prio Prioridade do Node
 *   @returns Node*
 */
Node* createnode(float val, int prio) {
    Node* n = malloc (sizeof(Node));
    n-> value = val;
    n-> priority = prio;
    return n;
}

void swap(Node* na, Node* nb) {

    printf("============SWAPPINGING NODES============\n");
    printf("NODE PRIORITY %d <=======> NODE PRIORITY %d\n", na-> priority, nb-> priority);
    Node nc = *na;
    *na = *nb;
    *nb = nc;
}

/*
 * Function: showdata(Fprio*)
 * -----------------------------------
 *   Funcao para exibir todos os dados da fila de prioridade
 *
 *   @param fp Ponteiro para a fila
 *   @returns void
 */
void showdata(Fprio* fp) {
    int i;
    printf("===========DISPLAYING ALL DATA===========\n");
    printf("INDEX: %d\n", fp-> n);
    printf("LENGTH: %d\n", fp-> len);
    for(i = 0; i < fp-> n; i++) {
        printf("NODE[%d] VALUE %2.2f :: NODE[%d] PRIORITY %d\n", i, fp-> vdata[i]->value, i, fp-> vdata[i]->priority);
    }
    printf("=========================================\n");
}
