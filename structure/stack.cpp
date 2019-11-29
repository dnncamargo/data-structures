#include <iostream>

#define LEN 10
#define DELIM " - "
using namespace std;
void printarray(int*, int);
void fillwithzero(int*);
void push(int*, int*, int);
void pop(int*, int*);
bool isempty(int);
bool isfull(int);


int main()
{
    int stack[LEN];
    int top = -1;
    fillwithzero(stack);

    push(stack, &top, 5);
    push(stack, &top, 7);
    push(stack, &top, 9);
    push(stack, &top, 11);
    push(stack, &top, 13);
    push(stack, &top, 15);
    push(stack, &top, 17);
    push(stack, &top, 19);
    push(stack, &top, 21);
    push(stack, &top, 23);
    push(stack, &top, 25);
    push(stack, &top, 27);
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    push(stack, &top, 16);
    push(stack, &top, 18);
    push(stack, &top, 20);

    printarray(stack, top);

    cout << isempty(top) << endl;
}

/**
 * Imprime os elementos úteis da pilha
 */
void printarray(int* arr, int top)
{
    for (int i = 0; i < top; i++)
        cout << arr[i] << DELIM;
        cout << arr[top] << endl << "Top is " << top << endl;
}

/**
 * Imprime toda a pilha
 */
void printarray(int* arr)
{
    for (int i = 0; i < LEN -1; i++)
        cout << arr[i] << DELIM;
        cout << arr[LEN-1] << endl;
}

/**
 * Preenche a pilha com zeros
 */
void fillwithzero(int* arr)
{
    for (int i = 0; i < LEN; i++)
        arr[i] = 0;
}

/**
 * Insere um elemento no topo da pilha
 */
void push(int* arr, int *top, int value)
{
    if(isfull(*top))
    {
        cout << "Stack is full" << endl;
    } else {
        *top = *top + 1;

        cout << "Stacking up with " << value << " at " << *top << " position" << endl;
        arr[*top] = value;
    }
}

/**
 * Remove o último elemento da pilha
 */
void pop(int* arr, int *top)
{
    if(isempty(*top))
    {
        cout << cout << "Stack is empty" << endl;
    } else {
        cout << "Value Removed " << arr[*top] << " at " << *top << " position "<< endl;
        arr[*top] = 0;
        *top = *top - 1;

    }
}

/**
 * Verifica se a pilha está vazia
 */
bool isempty(int top)
{
    return top == -1;
}

/**
 * Verifica se a pilha está cheia
 */
bool isfull(int top)
{
    return top == LEN - 1;
}