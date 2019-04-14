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
    Node* node6 = createnode(1.1, 7);

    insertnode(fp, node0);
    insertnode(fp, node1);
    insertnode(fp, node2);
    insertnode(fp, node3);
    insertnode(fp, node4);
    insertnode(fp, node5);
    insertnode(fp, node6);

    extractmax(fp);
    extractmax(fp);
    extractmax(fp);

    showdata(fp);

    changeprio(fp, 1, 0);

    showdata(fp);

    return 0;

}
