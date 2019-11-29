#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLEN (3)

typedef struct btree {
    int nkeys;    /* número de chaves incluídas */
    int keys[MAXLEN]; /* vetor de chaves (elementos) */
    int isleaf;     /* se o nó atual é uma folha */
    struct btree *btchildren[MAXLEN+1];  /* vetor de ponteiros para os nós filhos */
} Btree;

Btree * createbtree () {

    Btree * b;
    b = malloc(sizeof(*b));
    assert(b);

    b-> isleaf = 1;
    b-> nkeys = 0;
    return b;
}

void destroybtree (Btree * b) {
    int i;

    if(b-> isleaf != 0) {
        for(i = 0; i < b-> nkeys + 1; i++) {
            destroybtree(b-> btchildren[i]);
        }
    }
    free(b);
}

/* retorna o menor índice i em um vetor ordenado */
int getposition(int n, const int *a, int key) {
    int low;
    int high;
    int mid;

    low = -1;
    high = n;

    while(low + 1 < high) {
        mid = (low + high)/2;
        if(a[mid] == key) {
            return mid;
        } else if(a[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int searchbtree(Btree * b, int key) {
    int position;

    /* verificar se a árvore está vazia */
    if(b-> nkeys == 0) {
        return 0;
    }

    /* procura a menor posição que poderá encaixar a chave */
    position = getposition(b-> nkeys, b-> keys, key);

    if(position < b-> nkeys && b-> keys[position] == key) {
        return 1;
    } else {
        return(!b-> isleaf && searchbtree(b-> btchildren[position], key));
    }
}

/* Insere uma chave dentro da árvore */
/* Retorna o nó irmão se o nodo se dividir */
Btree * insertinto(Btree * b, int key, int * median) {
    int pos;
    int mid;
    Btree * btright;

    pos = getposition(b-> nkeys, b-> keys, key);

    if(pos < b-> nkeys && b-> keys[pos] == key) {
        return NULL;
    }

    if(b-> isleaf) {

        /* Todos se movem */
        printf("Todos se movem\n");
        memmove(&b-> keys[pos+1], &b-> keys[pos], sizeof(*(b-> keys)) * (b-> nkeys - pos));
        b-> keys[pos] = key;
        b-> nkeys++;

    } else {

        /* insere no nó filho */
        printf("insere no nó filho\n");
        btright = insertinto(b-> btchildren[pos], key, &mid);
        
        if(btright) {

            /* Todos se movem */
            printf("Todos se movem\n");
            memmove(&b-> keys[pos+1], &b-> keys[pos], sizeof(*(b-> keys)) * (b-> nkeys - pos));
            /* nova chave entra na posição pos+1*/
            printf("nova chave entra na posição pos+1\n");
            memmove(&b-> btchildren[pos+2], &b-> btchildren[pos+1], sizeof(*(b-> keys)) * (b-> nkeys - pos));

            b-> keys[pos] = mid;
            b-> btchildren[pos+1] = btright;
            b-> nkeys++;
        }
    }

    /* dividindo */
    printf("dividindo\n");
    if(b-> nkeys >= MAXLEN) {
        mid = b-> nkeys/2;

        *median = b-> keys[mid];

        /* novo nodo para keys > median */
        /* picture is:
         *
         *      3 5 7
         *      A B C D
         *
         * becomes
         *          (5)
         *      3        7
         *      A B      C D
         */
        btright = malloc(sizeof(*btright));

        btright-> nkeys = b-> nkeys - mid - 1;
        btright-> isleaf = b-> isleaf;

        memmove(btright-> keys, &b-> keys[mid+1], sizeof(*(b-> keys)) * btright-> nkeys);
        if(!b-> isleaf) {
            memmove(btright-> btchildren, &b-> btchildren[mid+1], sizeof(*(b-> btchildren)) * (btright-> nkeys + 1));
        }

        b-> nkeys = mid;

        return btright;
    } else {
        return 0;
    }
}

void insertbtree(Btree * b, int key) {
    Btree * btleft;   /* novo ramo esquerdo */
    Btree * btright;   /* novo ramo direito */
    int * median;

    btright = insertinto(b, key, median);

    if(btright) {

        btleft = malloc(sizeof(*btleft));
        assert(btleft);

        /* copia root para bleft */
        printf("copia root para bleft\n");
        memmove(btleft, b, sizeof(*b));

        /* faz root apontar para btleft and btright */
        printf("faz root apontar para btleft and btright\n");
        b-> nkeys = 1;
        b-> isleaf = 0;
        b-> keys[0] = *median;
        b-> btchildren[0] = btleft;
        b-> btchildren[1] = btright;
    }
}

void printbtree(Btree * b) {
    if (b != NULL) {
        int i;
        for (i = 0; i < b-> nkeys; i++){
            printf("%d\n", b-> keys[i]);
        }
    }
}

int main () {
    Btree * b = createbtree();
    insertbtree(b, 32);
    insertbtree(b, 64);
    insertbtree(b, 128);
    insertbtree(b, 256);
    printbtree(b);
    return 0;
}