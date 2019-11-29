#include<stdio.h>
#include<stdlib.h>

typedef struct {
    unsigned char value;
}bit;

typedef struct {
    bit num[32];
}binarray;

int main(int argc, char const *argv[]) {
    /* code */
    binarray* a;
    int i;
    a = (binarray*) malloc(sizeof(binarray));
    if(a != NULL) {
        for(i = 0; i < 32; i++)
        a[i]->value = 0;
    }
    for(i = 0; i < 32; i++)
        printf("%u\n", a[i]->value);

    return 0;
}
