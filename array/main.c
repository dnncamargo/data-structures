#include<stdio.h>
#include<stdlib.h>
#include"arrays.h"

#define LEN 6

int main() {

    /*float *a;
    a = create(LEN);
    a = assign(a, LEN);
    a = oparith(a, LEN, '*', -1);
    printarray(a, LEN);*/

    float **a;
    a = creatematrix(2, 3);
    a = assignmatrix(a, 2, 3);
    
    return 0;
}
