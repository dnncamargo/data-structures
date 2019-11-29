#include <iostream>
#include <stdlib.h>
#define LEN 10
#define OPEN " |"
#define CLOSE "| "
using namespace std;
void printarray(int*);
void fillwithrandom(int*);
void bubble(int*);
void swap(int*, int*);

int main()
{
    int arr[LEN];
    fillwithrandom(arr);
    printarray(arr);

    bubble(arr);

    printarray(arr, LEN);

}

/**
 * Preenche o vetor com números aleatórios
 */
void fillwithrandom(int* arr)
{
    for(int i = 0; i < LEN; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

/**
 * Imprime os elementos do vetor
 */
 void printarray(int* arr)
 {
     for(int i = 0; i < LEN; i++)
     {
        cout << OPEN << arr[i] << CLOSE;
     }
    cout << endl;
 }

 /**
 * Ordenação em bolha
 */
 void bubble(int* arr)
 {
    int i, j;
    for (i = 0; i < LEN-1; i++) {
        for (j = i+1; j < LEN; j++) {
           if(arr[i] > arr[j])
           {
                cout << "Swapped values " << arr[i] << " and " << arr[j] << endl;
                swap(arr[i], arr[j]);
            }
        }
    }
 }

 /**
 * Troca valores
 */
 void swap(int* a, int* b)
 {
     int *c = a;
     *a = *b;
     *a = *c;
 }