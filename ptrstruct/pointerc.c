#include<stdio.h>

int * doublepointer(int*);
void swap(int*, int*);

int main(){
    int a, b;
    int *pa = &a; // Lê-se "Ponteiro pa recebe o endereço de memória de a".
    int *pb = pointer(&b); // Ao passar por parâmetro, não é necessário o *. Pode-se também usar pb ou pa

    a = 13;
    b = 26;

    swap(pa, pb);
    printf("%d\n", *pb); // Note que é necessário o * para obter o valor.
}

int * doublepointer(int * p){
    *p = 2*p;
    return p;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *a = temp;
}
