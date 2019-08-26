#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(){
    bintree * bt = NULL;
    bt = insertnode(2, bt);
    bt = insertnode(4, bt);
    bt = insertnode(-6, bt);
    bt = insertnode(0, bt);
    bt = insertnode(8, bt);
    bt = insertnode(12, bt);
    bt = insertnode(-10, bt);
    if(search(-10, bt)){
        printf("Have\n");
    }

    printf("printing\n");
    printnodes(bt);
}
