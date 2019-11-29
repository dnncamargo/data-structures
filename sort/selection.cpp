#include <iostream>
#include <stdlib.h>
#define LEN 10
#define OPEN " |"
#define CLOSE "| "
using namespace std;
void printarray(int*);
void fillwithrandom(int*);
void selection(int*);
void swap(int*, int*);

int main()
{
    int arr[LEN];
    fillwithrandom(arr);
    printarray(arr);

    cout << "Starting Selection Sort" << endl;
    selection(arr);

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
 * Ordenação em seleção
 */
 void selection(int* arr)
 {
    int i, j, min;

    for (i = 0; i < LEN-1; i++) 
    {

        /* Posição do menor valor encontrado */
        min = i;
        cout << "DEBUG: Init Loop: i> " << i << " j> " << j << " min> " << min << endl;
        /* Analisa os elementos na frente */
        for (j = i+1; j < LEN; j++)
        {

            /* Caso encontre um valor menor após os valores analisados */
            if(arr[j] < arr[min])
            {
                cout << "Found " << arr[j] << "<" << arr[min] << " :: I: " << i << " J: " << j << " MIN: " << min << endl;
                min = j;
            }
        }

        /* Verifica se houve mudança e troca os valores */
        if(min != i)
        {
            cout << "Swapping " << arr[i] << " with " << arr[min] << endl;
            swap(arr[i], arr[min]);
        }
        printarray(arr);

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