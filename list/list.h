#include<stdio.h>
#include<stdlib.h>

struct list; // Esta declaracao e dispensavel, ja que o struct ja esta no header

/* Voce tem que declarar a palavra-chave struct em todos os lugares em que e usada:

struct MyStruct ;

struct MyStruct
{
   // * code * //
} ;

void doSomething(struct MyStruct * p)
{
   struct MyStruct a ;
   // * code * //
}

Enquanto um typedef permitira escrever sem a palavra-chave struct.

struct MyStructTag ;

typedef struct MyStructTag
{
    // * code * //
} MyStruct ;

void doSomething(MyStruct * p)
{
   MyStruct a ;
   // * code * //
} */

typedef struct linkedlist {
    struct list *next; // ponteiro para o proximo. Note o uso da palavra struct e do *
    float val;
} list;

list createlist (void);

void eraselist (list);

list insertat(list, float, int);

list removeat(list, int);

list setcontent(list, int, float);

void showcontent(list, int);

void printall(list);

list concatlist(list, list);

list copylist(list);

int isempty(list);
