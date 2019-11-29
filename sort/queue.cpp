#include <iostream>

#define LEN 10
#define DELIM " - "
using namespace std;
void printarray(int*, int);
void fillwithzero(int*);
void enqueue(int*, int*, int);
void dequeue(int*, int*);
bool isempty(int);
bool isfull(int);
int length(int);

int main()
{
    int queue[LEN];
    int back = -1;
    fillwithzero(queue);

    enqueue(queue, &back, 1);
    enqueue(queue, &back, 1);
    enqueue(queue, &back, 2);
    enqueue(queue, &back, 3);
    enqueue(queue, &back, 5);
    enqueue(queue, &back, 8);
    enqueue(queue, &back, 13);
    enqueue(queue, &back, 21);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    dequeue(queue, &back);
    enqueue(queue, &back, 21);
    enqueue(queue, &back, 13);
    enqueue(queue, &back, 8);
    enqueue(queue, &back, 5);
    enqueue(queue, &back, 3);
    enqueue(queue, &back, 2);
    enqueue(queue, &back, 1);
    enqueue(queue, &back, 1);
    dequeue(queue, &back);

    printarray(queue, length(back));
}

/**
 * Imprime os elementos úteis da fila
 */
void printarray(int* arr, int len)
{
    if(len == 0)
    {
        cout << "Queue is empty. Length is " << len << endl;
    } else {
    for (int i = 0; i < len-1; i++)
        cout << arr[i] << DELIM;
        cout << arr[len-1] << endl << "Length is " << len << endl;
    }
}

/**
 * Preenche a fila com zeros
 */
void fillwithzero(int* arr)
{
    for (int i = 0; i < LEN; i++)
        arr[i] = 0;
}

/**
 * Retorna o tamanho da fila
 */
int length(int back)
{
    return (back + 1);
}

/*
 ** Adiciona um valor à fila
*/
void enqueue(int* arr, int* last, int value)
{
    if(isfull(*last))
    {
        cout << "Queue is full" << endl;
        return;
    } else {
        *last = *last + 1;

        cout << "Queued with " << value << " at " << *last << " position" << endl;
        arr[*last] = value;
    }
    
}

/*
 ** Adiciona um valor à fila
*/
void dequeue(int* arr, int* last)
{
    if(isempty(*last))
    {
        cout << "Queue is empty" << endl;
        return;
    } else {
        cout << "Dequeued value " << arr[0] << endl;
        for(int i = 0; i < length(*last); i++)
        {
            arr[i] = arr[i+1];
        }
        *last = *last - 1;
    }
    
}

/**
 * Verifica se a fila está vazia
 */
bool isempty(int back)
{
    return back == -1;
}

/**
 * Verifica se a fila está cheia
 */
bool isfull(int back)
{
    return back == LEN - 1;
}