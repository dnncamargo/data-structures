#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

bintree * insertnode (int info, bintree * t) {
    if(t == NULL) {
        t = (bintree *) malloc (sizeof(bintree));
        t-> info = info;
        t-> right = NULL;
        t-> left = NULL;
    } else {
        if(info < t-> info) {
            t-> left = insertnode(info, t-> left);
        } else {
            t-> right = insertnode(info, t-> right);
        }
    }
    return t;
}


int verifyifexists (int info, bintree * t) {
    if(t != NULL) {
        if(info == t-> info) {
            printf("Have\n");
            return 1;
        } else {
            if(info < t-> info) {
                return verifyifexists(info, t-> left);
            } else {
                return verifyifexists(info, t-> right);
            }
        }
    } else {
        printf("Do not have\n");
        return 0;
    }
}

void printnodes(bintree * t) {
    if(t != NULL) {
        printf("%d\n", t-> info);
        printnodes(t-> left);
        printnodes(t-> right);

    }
}
