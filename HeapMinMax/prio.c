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


/*
 * Function: insert(Fprio*, Node)
 * -----------------------------------
 *   Funcao para inserir elemento
 *
 *   @param fp Ponteiro para a estrutura principal
 *   @param item Elemento a ser inserido
 *   @returns void
 */
void insertnode(Fprio* fp, Node* item) {
    printf("=============INSERTING  NODE=============\n");
    printf("NODE[%d] VALUE %2.2f :: NODE[%d] PRIORITY %d\n", fp-> n, item->value, fp-> n, item-> priority);
    fp-> vdata[fp-> n] = item;
    fp-> n++;
    rearrangeup(fp, fp-> n-1);
}

/*
 * Function: Node* extractmax(Fprio*)
 * -----------------------------------
 *   Funcao para extrair Node de maior prioridade da lista e retornar seu ponteiro
 *
 *   @param fp Ponteiro para a estrutura principal
 *   @returns Node*
 */
Node* extractmax(Fprio* fp) {
    printf("=============EXTRACING  NODE=============\n");
    printf("NODE[%d] VALUE %2.2f :: NODE[%d] PRIORITY %d\n", 0, fp-> vdata[0]->value, 0, fp-> vdata[0]-> priority);
    // vdata[0] sempre contem o node de maior prioridade
	Node* max = fp-> vdata[0];
    // Troca ponteiros entre os nodes de maior prioridade e o ultimo node inserido
	swap ((fp-> vdata[0]), (fp-> vdata[fp-> n-1]));
    fp-> n--;
    rearrangedown(fp, 0);
	return max;
}

/*
 * Function: changeprio(Fprio*, int, int)
 * -----------------------------------
 *   Funcao para alterar a prioridade de um Node
 *
 *   @param fp Ponteiro para a estrutura principal
 *   @param index Indice do elemento no vetor
 *   @param priority Valor da nova prioridade do Node
 *   @returns Node*
 */
void changeprio(Fprio* fp, int index, int priority) {
    int oldprio = fp-> vdata[index]-> priority;
    fp-> vdata[index]-> priority = priority;
    if(oldprio < fp-> vdata[index]-> priority) {
        rearrangeup(fp, index);
    } else {
        rearrangedown(fp, index);
    }
}


/*
 * Function: rearrangeup(Fprio*, int)
 * -----------------------------------
 *   Funcao para reorganizar Nodes por prioridade no heap
 *
 *   @param fp Ponteiro para a estrutura principal
 *   @param index Indice do elemento no vetor
 *   @returns Node*
 */
void rearrangeup(Fprio* fp, int childindex) {
    // Condicao para verificar se o node pai tem prioridade menor que o node informado
    if(childindex > 0 &&
        fp-> vdata[parentnode(childindex)]-> priority < fp-> vdata[childindex]-> priority) {
        swap ((fp-> vdata[parentnode(childindex)]), (fp-> vdata[childindex]));
        rearrangeup(fp, parentnode(childindex));
    }
}

/*
 * Function: rearrangedown(Fprio*, int)
 * -----------------------------------
 *   Funcao para reorganizar Nodes por prioridade no heap
 *
 *   @param fp Ponteiro para a estrutura principal
 *   @param index Indice do elemento no vetor
 *   @returns Node*
 */
void rearrangedown(Fprio* fp, int parentindex) {

    // maxchild e o index do filho com maior prioridade
    if(leftchild(parentindex) < fp-> n) {
        int maxchild = leftchild(parentindex);
        // a segunda condicao assegura qual dos filhos tem prioridade maior
        if(rightchild(parentindex) < fp-> n &&
            fp-> vdata[leftchild(parentindex)]-> priority < fp-> vdata[rightchild(parentindex)]-> priority) {
            maxchild = rightchild(parentindex);
        }

        // Verifica se o node pai tem prioridade menor que o node filho
        if(fp-> vdata[parentindex]-> priority < fp-> vdata[maxchild]-> priority) {
            swap(fp-> vdata[parentindex], fp-> vdata[maxchild]);
            rearrangedown(fp, maxchild);
        }
    }

}

int parentnode(int i) {
    return ((i-1)/2);
}

int leftchild(int i) {
    return 2*i+1;
}

int rightchild(int i) {
    return 2*i+2;
}

/*
 * Function: swap(Node*, Node*)
 * -----------------------------------
 *   Funcao para realizar troca entre dois ponteiros do tipo Node
 *
 *   @param na, nb Ponteiros para Nodes
 *   @returns void
 */
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
