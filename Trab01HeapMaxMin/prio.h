#include <stdio.h>
#include <stdlib.h>

/** value:float   Informacao
  * priority:int  Prioridade */
typedef struct elem {
    float value;
    int priority;
} Node;

/** vdata:Node** Vetor de Nodes
  * n:int        Indice do ultimo valor armazenado
  * len:int      Tamanho total */
typedef struct fprio {
    Node** vdata;
    int n, len;
} Fprio;

void swap(Node*, Node*);

Fprio* create(int);

Node* createnode(float, int);

void insertnode(Fprio*, Node*);

void changeprio(Fprio*, int, int);

void rearrangeup(Fprio*, int);

void rearrangedown(Fprio*, int);

int parentnode(int);

int leftchild(int);

int rightchild(int);

Node* extractmax(Fprio*);

void showdata(Fprio*);

int isEmpty(Fprio*);

int isFull(Fprio*);
