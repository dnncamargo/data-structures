#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char src[] = "1234567890";
    char dest[] = "abcdefgh";

    memmove(dest+2, src, 5);
    printf("%s\n", dest);
}