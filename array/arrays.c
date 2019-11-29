#include<stdio.h>
#include<stdlib.h>
#include"arrays.h"

float* createarray(int length) {
    int i;
    float* array  = (float*) malloc(sizeof(float)*length);
    if(array != NULL) {
        printf("Array created: %d bytes\n", sizeof(float)*length);
        return array;
    } else {
        printf("An error occured\n");
        return NULL;
    }
}

float** creatematrix(int length_i, int length_j) {
    int i;
    float** array  = (float**) malloc(sizeof(float*)*length_j);
    for(i = 0; i < length_j; i++){
        array[i] = (float*) malloc(sizeof(float)*length_i);
    }
    if(array != NULL) {
        printf("Array created: %d bytes\n", sizeof(float)*length_i*length_j);
        return array;
    } else {
        printf("An error occured\n");
        return NULL;
    }
}

float* assignarray(float* array, int length) {
    if(array != NULL && length > 0) {
        printf("Will set %d cells in array.\n", length);
        int i;
        for(i = 0; i < length; i++) {
            printf("[%d]: ", i);
            scanf("%f", &array[i]);
        }
        printf("Values assigned successfully\n");
        return &array[0];
    } else {
        return NULL;
    }
}

float* assignmatrix(float** array, int length_i, int length_j) {
    if(array != NULL && (length_i > 0 && length_j > 0)) {
        printf("Will set %d cells in array: %d Rows, %d Columns\n", length_i*length_j, length_i, length_j);
        int i, j;

        for(i = 0; i < length_j; i++) {
            for (j = 0; j < length_i; j++){
                printf("[%d][%d]: ", i, j);
                scanf("%f", &array[i][j]);
            }
        }
        printf("Values assigned successfully\n");
        return &array[0][0];
    } else {
        return NULL;
    }
}

/* Funcao para imprimir array */
void printarray(float* array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("[ %0.2f ] ", array[i]);
    }
}

/* Funcao para retornar a media */
float average(float* array, int length) {
    if(length > 0 && array != NULL) {
        int i;
        float sum = 0;
        for(i = 0; i < length; i++) {
            sum += array[i];
        }
        sum /= (float) length; // Operacao entre inteiros e ponto flutuante (possivel perda de precisao)
        return sum;
    } else {
        return -1;
    }
}

/* Funcao para realizar uma operacao aritmetica entre o array e uma constante */
float* oparith(float* array, int length, char op, float n) {
    if(length > 0 && array != NULL) {
        int i;
        switch (op) {
            case '+':
                for(i = 0; i < length; i++) {
                    array[i] += n;
                }
                break;
            case '-':
                for(i = 0; i < length; i++) {
                    array[i] -= n;
                }
                break;
            case '*':
                for(i = 0; i < length; i++) {
                    array[i] *= n;
                }
                break;
            case '/':
                for(i = 0; i < length; i++) {
                    array[i] /= n;
                }
                break;
            default:
                return array;
        }
        return array;
    } else {
        return NULL;
    }
}
