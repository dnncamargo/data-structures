#include <stdio.h>
#include <stdlib.h>

struct gradeNode {
    char lastName[20];
    double grade;
    struct gradeNode *NextPtr;
};

typedef struct gradeNode *gradeNode;
typedef gradeNode *gradeNodePtr;

int main() {
gradeNode* startPtr;

gradeNode n;
n->lastName[20] = 'a';
n->grade = 8.5;
n->NextPtr = NULL;

gradeNodePtr newPtr = &n;

}
