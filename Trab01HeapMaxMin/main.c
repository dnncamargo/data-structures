#include <stdio.h>
#include <stdlib.h>
#include "prio.h"

#define MAXLEN 10

int main(){
    Fprio* fp = create(MAXLEN);
    Node* node0 = createnode(1.5, 5);
    Node* node1 = createnode(1.6, 3);
    Node* node2 = createnode(1.7, 1);
    Node* node3 = createnode(1.9, 9);
    Node* node4 = createnode(1.4, 4);
    Node* node5 = createnode(2.0, 2);

    return 0;

}
