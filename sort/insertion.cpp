#include <iostream>
#include <stdlib.h>
#define LEN 10
#define OPEN " |"
#define CLOSE "| "
using namespace std;
void printarray(int*);
void fillwithrandom(int*);
void insertion(int*);

int main()
{
    int arr[LEN];
    fillwithrandom(arr);
    printarray(arr);

    insertion(arr);

    printarray(arr);

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
 * Ordenação em inserção
 */
 void insertion(int* arr)
 {
    int i, j, k;

    for (i = 1; i < LEN; i++) 
    {
        /* Elemento atual em análise */
        k = arr[i];

        /* Elemento anterior ao analisado */
        j = i-1;
        while ((j >= 0) && (k < arr[j])) 
        {
            cout << "Moving value " << arr[j] << " to " << j+1 << endl;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
        cout << "Inserting value " << k << " at " << j+1 << " position" << endl;
    }
 }
