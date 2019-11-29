#include <iostream>
#include <stdlib.h>
#include <new>
#include <string>

#define CASE1 cout << "1- Insert Node At Start" << endl;
#define CASE2 cout << "2- Insert Node At End" << endl;
#define CASE3 cout << "3- Insert Node At Index" << endl;
#define CASE4 cout << "4- Remove Node At Start" << endl;
#define CASE5 cout << "5- Remove Node At End" << endl;
#define CASE6 cout << "6- Remove Node At Index" << endl;
#define CASE7 cout << "7- Search Node" << endl;
#define CASE8 cout << "8- Print List" << endl;
#define CASE9 cout << "9- Exit" << endl;

int showMenu();
void insAtStart();
void insAtEnd();
void insAtIndex();
void remAtStart();
void remAtEnd();
void remAtIndex();
using namespace std;

struct person
{
    int id;
    string name;
}

int main()
{
    int op, len = 0;
    person *p;
    
    do
    {
        switch(op)
        {
            case 1:
            system("CLS");
            insAtStart();
            break;
            case 8:
            system("CLS");
            printList();
            break;
        }
    op = showMenu();
    } while((op > 0) && (op < 10));
}

int showMenu()
{
    
    cout << "SEQUENTIAL LIST" << endl;
    CASE1;CASE2;CASE3;CASE4;CASE5;CASE6;CASE7;CASE8;CASE9;
    cout << "Choose an Option: ";
    int option;
    cin >> option;
    return option;
}

 void printarray(int* arr, int len)
 {
     for(int i = 0; i < len; i++)
     {
        cout << " |" << arr[i] << "| ";
     }
    cout << endl;
 }
void insAtStart()
{
    int id;
    CASE1;
    cin >> id;
}

/*
    cout << "1- Insert Node At Start" << endl;
    cout << "2- Insert Node At End" << endl;
    cout << "3- Insert Node At Index" << endl;
    cout << "4- Remove Node At Start" << endl;
    cout << "5- Remove Node At End" << endl;
    cout << "6- Remove Node At Index" << endl;
    cout << "7- Search Node" << endl;
    cout << "8- Print List" << endl;
    cout << "9- Exit" << endl;
    */