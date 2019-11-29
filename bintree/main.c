#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(){
    bintree * bt = NULL;
    bt = insertnode(49, bt);
    bt = insertnode(28, bt);
    bt = insertnode(18, bt);
    bt = insertnode(11, bt);
    bt = insertnode(19, bt);
    bt = insertnode(40, bt);
    bt = insertnode(32, bt);
    bt = insertnode(44, bt);
    bt = insertnode(83, bt);
    bt = insertnode(71, bt);
    bt = insertnode(72, bt);
    bt = insertnode(69, bt);
    bt = insertnode(97, bt);
    bt = insertnode(92, bt);
    bt = insertnode(99, bt);

    //removenode(12, bt);
    printnodes(bt);
}
