#include <stdio.h>
#include <stdlib.h>

#define MAX 5;

int isfull(int, int);
int isempty(int, int);
int size(int, int);

int main() {

    int in, out; // index

    in = 0; //MIN
    out = 0;
    printf("%d\n", size(in, out));

    in = 0; //MIN
    out = 1;
    printf("%d\n", size(in, out));

    in = 0; //MIN
    out = 3;
    printf("%d\n", size(in, out));

    in = 0; //MIN
    out = 4; //MAX
    printf("%d\n", size(in, out));

    in = 1;
    out = 4; //MAX
    printf("%d\n", size(in, out));

    in = 4; //MAX
    out = 4; //MAX
    printf("%d\n", size(in, out));

    in = 4; //MAX
    out = 0; //MIN
    printf("%d\n", size(in, out));

    in = 2; //MAX
    out = 0; //MIN
    printf("%d\n", size(in, out));
}

int isempty(int in, int out) {

}

int isfull(int in, int out) {

}

int size (int in, int out) {
    if(out >= in) return (out-in+1);
    else return (MAX + (out-in)+1);
}