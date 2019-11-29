#include<stdio.h>
#include<stdlib.h>

#define MAXLEN (3)

typedef struct btree {
    int nkeys;    /* número de chaves incluídas */
    int keys[MAXLEN]; /* vetor de chaves (elementos) */
    int isleaf;     /* se o nó atual é uma folha */
    struct btree *btchildren[MAXLEN+1];  /* vetor de ponteiros para os nós filhos */
} Btree;

Btree * createbtree();

void destroybtree(Btree *);

int getposition(int, const int *, int);

int searchbtree(Btree *, int);

Btree * insertinto(Btree *, int, int *);

void insertbtree(Btree *, int);

void printbtree(Btree *);