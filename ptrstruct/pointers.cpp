#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int a = 1;
int main(int argc, char* argv[])
{
    std::cout << argv[1] << std::endl;
    int value = atoi(argv[1]);
    cout << value << endl;

    


    int a = 3;
    printf("local a = %d \n", a);
    printf("global a = %d \n", ::a);


    return 0;
}
