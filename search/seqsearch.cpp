#include <iostream>
#include <locale.h>
#define LEN 10
#define DELIM " - "
using namespace std;

void printarray(int*);
int indexof(int*, int);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Número a ser encontrado
    int num;

    // Vetor de inteiros
    int arr[LEN] = {52, 65, 23, 98, 12, 45, 87, 9, 37, 71};
    printarray(arr);

    cout <<"Digite o numero que deseja encontrar: ";
    cin >> num;

    cout << indexof(arr, num) << endl;

    return 0;
}

void printarray(int* arr)
{
    for (int i = 0; i < LEN -1; i++)
        cout << arr[i] << DELIM;
        cout << arr[LEN-1] << endl;
}

// Sequential Search
int indexof(int* arr, int num)
{
    for(int i = 0; i < LEN; i++)
    {
        if(arr[i] == num)
            return i;
    }
    return -1;
}