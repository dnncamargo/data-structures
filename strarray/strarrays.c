#include<stdio.h>
#include<stdlib.h>
#include"arrays.h"

/* Arquivo para implementação de funções */

/* Função para inverter arrays */
int invert(char* array, int length) {
    if(array != NULL && length > 0) {
        char temp;
        int i;
        for( i = 0; i < length/2; i++) {
            temp = array[i];
            array[i] = array[length-1-i];
            array[length-1-i] = temp;
        }
        return 1;
    } else {
        return 0;
    }
}

/* Função para transformar caracteres minúsculos em maiúsculos */
char* caps(char* strin_a) {
    if(strin_a != NULL) {
        int i;
        int length = strlen(strin_a);
        for( i = 0; i < length; i++) {
            if(strin_a[i] >= 97 && strin_a[i] <= 122){
                strin_a[i] = strin_a[i] - 32;
            }
        }
        return strin_a;
    } else {
        return NULL;
    }
}

/* Função para concatenar strings */
char* concat(char* strin_a, char* strin_b) {
    int i, j;

    /* Contando o tamanho da string */
    int length0 = strlen(strin_a);
    int length1 = strlen(strin_b);

    //while(strin_a[++length0] != '\0');
    //while(strin_b[++length1] != '\0');

    /* Alocação de memória */
    char* strout = (char*) malloc(sizeof(char)*(length0 + length1));

    if(strout == NULL) {
        return NULL;
    }

    i = 0;
    j = 0;
    for(i = 0; i < length0; i++){
        strout[i] = strin_a[i];
    }
    for(i, j; i < (length0 + length1); i++, j++){
        strout[i] = strin_b[j];
    }
    strout[i] = '\0';

    if(strout != NULL){
        return strout;
    } else {
        return NULL;
    }
}

/* Função para remover um character especifico de uma string */
char* remchar(char* strin_a, char c) {
    if(strin_a != NULL){
        int length = strlen(strin_a);
        int i;

        for (i = length-1; i >= 0; i--) {
            if(strin_a[i] == c) {
                for (i; i < length; i++) {
                    strin_a[i] = strin_a[i+1];
                }
                length--;
                strin_a[length] = '\0';
            }
        }
        return strin_a;
    } else {
        return NULL;
    }
}

/* Função para remover espaços de uma string */
char* trim(char* strin_a) {
    return remchar(strin_a, ' ');
}

/* Função para retornar o tamanho de uma string */
int strlen(char* strin_a) {
    if(strin_a != NULL) {
        int i; for(i=0; strin_a[i]!='\0'; ++i); return i;
    } else {
        return -1;
    }
}
