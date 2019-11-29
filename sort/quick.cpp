#include <iostream>
#include <stdlib.h>
#define LEN 30
#define OPEN " |"
#define CLOSE "| "
using namespace std;
void printarray(int*);
void fillwithrandom(int*);
void quick(int*, int, int);
void quick(int*, int, int, bool);
void swap(int*, int*);

int main()
{
    int arr[LEN];
    fillwithrandom(arr);
    printarray(arr);

    quick(arr, 0, LEN-1);

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
 * Ordenação em Quick Sort
 */
 void quick(int* arr, int begin, int end)
 {
    int left, right, pivot;
    left = begin;
    right = end;
    pivot = arr[((left + right)/2)];

    /* Partition */
    while(left < right)
    {

        while (arr[left] < pivot)
        {
            left++;
        }

        while (arr[right] > pivot)
        {
            right--;
        }

        if(left <= right)
        {
            cout << "Swapping values : " << arr[right] << " and " << arr[left] << endl;
            swap(arr[right], arr[left]);
            left++;
            right--;
        }
    }

    /* Recursion */
    if(begin < right)
    {
        quick(arr, begin, right);
    }
    if(left < end)
    {
        quick(arr, left, end);
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