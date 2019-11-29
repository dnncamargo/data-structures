#include <stdio.h>
#define MAX 10

typedef struct {
    int cod;
    char description[30];
    float price;
} product;

int isfull(int);
void push(int, struct product *p);
void pop(int);


int main() {
    int op;
    int top = -1;
    product storage[10];

    do {
        printf("Enter Option: \n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if(!isfull(top)) {
                    push(top, &storage);
                    top++;
                } else {
                    printf("Stack is full\n");
                }
                break;
            case 2:

        }
    } while (op != 0);
}

int isfull(int top) {
    return top == MAX-1;
}

int isempty(int top) {
    return top == -1;
}

void push(int index, product *p) {
    printf("Enter Product Code\n"); scanf("%d", p[index]->cod);
    printf("Enter Product Description\n"); gets(p[index]->description); fflush(stdin);
    printf("Enter Product Price\n");scanf("%f", p[index]->price);
}

void pop(index) {

}
