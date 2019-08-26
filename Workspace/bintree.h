#include <stdio.h>
#include <stdlib.h>

typedef struct bt{
    int info;
    struct bt * left;
    struct bt * right;
} bintree;

int search (int, bintree*);

bintree* insertnode (int, bintree*);

bintree* removenode (int, bintree*);

void printnodes(bintree*);
