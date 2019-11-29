#include <iostream>
#include <stdlib.h>
#define OPEN " |"
#define CLOSE "| "
using namespace std;
void printarray(int*, int);
void fillwithrandom(int*, int);
void shell(int*, int, int);
int interval(int);

int main(int argc, char* argv[])
{
    int len = atoi(argv[1]);

    int arr[len];
    fillwithrandom(arr, len);
    printarray(arr, len);
    cout << "Length: " << len << endl;
    
    shell(arr, len, interval(len));

    printarray(arr, len);

}

/**
 * Preenche o vetor com números aleatórios
 */
void fillwithrandom(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

/**
 * Imprime os elementos do vetor
 */
 void printarray(int* arr, int len)
 {
     for(int i = 0; i < len; i++)
     {
        cout << OPEN << arr[i] << CLOSE;
     }
    cout << endl;
 }
/**
 * Calcula o intervalo
 */
 int interval(int len)
 {
    int interval = 1;
    while (interval < len/3)
    {
        interval = interval * 3 + 1;
    }
    cout << "Interval: " << interval << endl;
    return interval;
 }
 /**
 * Ordenação Shell Sort
 */
 void shell(int* arr, int len, int interval)
 {
    int i, j, k;
    while (interval > 0)
    {
        cout << "Outer loop :: i: " << i << endl;
        for (i = interval; i < len; i++) 
        {
            /* Elemento atual em análise */
            k = arr[i];

            /* Elemento anterior ao analisado */
            j = i;
            while ((j > interval -1) && (arr[j - interval] >= k)) 
            {
                cout << "Moving value " << arr[j - interval] << " to " << j << endl;
                arr[j] = arr[j - interval];
                j = j - interval;
            }
            arr[j] = k;
            cout << "Shelling value " << k << " into " << j << " position" << endl;
        }
        interval = (interval -1) /3;
    }
    
    
 }
