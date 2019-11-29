#include <stdio.h>
#include <stdlib.h>
#define MAXLENSIG 32

int main(int argc, char *argv[]) {
    if(argc == 2){
        float vbase10 = atof(argv[1]);
        int vbase2[MAXLEN];
        int i;

        for (i = 0; vbase10 > 0; i++) {
            vbase2[i] = vbase10 % 2;
            vbase10 /= 2;
        }
        for (i = i-1;i >= 0; i--) {
            printf("%d",vbase2[i]);
        }
    }
}
