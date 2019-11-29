/* 
 * File:   main.c
 * Author: Daniel Neves
 *
 * Created on 29 de Novembro de 2019, 11:25
 */

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(int argc, char** argv) {
    Btree * b = createbtree();
    insertbtree(b, 32);
    insertbtree(b, 64);
    insertbtree(b, 128);
    insertbtree(b, 256);
    printbtree(b);
    return (EXIT_SUCCESS);
}