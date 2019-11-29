#include <iostream>

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

    // Vetor de inteiros ordenado
    int arr[LEN] = {9, 12, 23, 37, 45, 52, 65, 71, 87, 98};
    printarray(arr);

    cout <<"Digite o numero que deseja encontrar: ";
    cin >> num;
    cout << "O valor foi encontrado em " << indexof(arr, num) << endl;

    return 0;
}

void printarray(int* arr)
{
    for (int i = 0; i < LEN -1; i++)
        cout << arr[i] << DELIM;
        cout << arr[LEN-1] << endl;
}

// Binary Search
int indexof(int* arr, int num)
{
    int firstindex = 0;
    int lastindex = LEN-1;
    
    while (firstindex <= lastindex)
    {
        int middleindex = (firstindex + lastindex)/2;

        if(arr[middleindex] == num)
        {
            return middleindex;
        }

        if(arr[middleindex] < num)
        {
            firstindex = middleindex + 1;
        } else {
            lastindex = middleindex - 1;
        }
    }
    return -1;
}