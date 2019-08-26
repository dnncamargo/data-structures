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

bintree* removenode (int info, bintree* t) {
    if(t != NULL) {
        if(info == t-> info) {
            return 1;
        } else {
            if(info < t-> info) {
                return removenode(info, t-> left);
            } else {
                return removenode(info, t-> right);
            }
        }
    } else {
        return NULL;
    }
}

int search (int info, bintree * t) {
    if(t != NULL) {
        if(info == t-> info) {
            return 1;
        } else {
            if(info < t-> info) {
                return search(info, t-> left);
            } else {
                return search(info, t-> right);
            }
        }
    } else {
        return 0;
    }
}

void printnodes(bintree * t) {
    if(t != NULL) {
        printnodes(t-> left);
        printf("%d\n", t-> info);
        printnodes(t-> right);
    }
}
