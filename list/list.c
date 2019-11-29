#include<stdio.h>
#include<stdlib.h>
#include"list.h"

list createlist () {
    list lnklst;
    return lnklst;
}

list insertat(list l, float val, int index) {
    list* pl = &l;
    pl = malloc(sizeof(list));
    pl->val = val;
    return l;
}

list removeat(list l, int index) {
    return l;
}

list setcontent(list l, int index, float val) {
    return l;
}

void showcontent(list* l, int index) {
    if(l->next!=NULL) {
        printf("%f\n", l->val);
        showcontent(l->next, index);
    }
}

void printall(list l) {

}

list concatlist(list l_a, list l_b) {
    return l_a;
}

list copylist(list l) {
    return l;
}

int isempty(list l) {
    return l.next==NULL;
}
