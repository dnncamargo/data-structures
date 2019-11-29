/* ********************************************************************* */
/* Professor:Andr�                                                       */
/* Objetivo de Programa: Implementa��o da TAD Lista (V1 - Encadeada)     */
/* T�pico da Disciplina: Estrutura de Dados do Tipo Lista                */
/* ********************************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* Estrutura para armazenar o N� da Lista*/
struct no {
 Dados info;
 struct no *prox;  // ponteiro para uma estrutura do tipo "N�"
};
typedef struct no No;

/* Estrutura de Dados para armazenar os dados da Lista*/
struct lista {
   int quantidade;
   No* prim; //Ponteiro para o primeiro "N�" da lista
};

/******************************************************************************/
/* Criar a estrutura padr�o da Lista                                          */
/******************************************************************************/
Lista* cria ()
{
   /* Alocar espa�o de mem�ria para a estrutura que armazena as informa��es gerais
   sobre a lista */
   Lista* l = (Lista*) malloc(sizeof(Lista));
   if (l== NULL)
   {
      printf("Faltou espa�o de memoria");
      exit(1);
   }

   l->quantidade = 0; // setar a quantidade de elementos da lista como zero
   l->prim = NULL; // Apontar in�cio para NULL
   return l; // retornar um ponteira para esta estrutura que foi criada
}

/******************************************************************************/
/* inser��o no in�cio: retorna a lista atualizada - sem ordem                 */
/******************************************************************************/
void insere (Lista* l, Dados* d)
{
   No* p = (No*) malloc(sizeof(No)); //alocar espa�o de mem�ria para o novo n�

   if (p == NULL)
   {
      printf("Faltou espa�o de memoria. N�o � possivel inserir um novo elemento");
   }
   else
   {
       /*Armazenar os dados da "pessoa", recebidos como par�metro de entrada, na
       vari�vel "d" dentro do n� "p" criado no comando anterior*/
       p->info.codigo = d->codigo;
       strcpy(p->info.nome,d->nome);
       p->info.idade = d->idade;
       strcpy(p->info.telefone,d->telefone);

       p->prox = l->prim;
       l->prim = p;

	   l->quantidade++; // incrementar o contador da quantidade de elementos da lista
   }
}

/******************************************************************************/
/* Inser��o ordenada na lista                                                          */
/******************************************************************************/
void insere_ordenado (Lista* l, Dados* d)
{
   No* p = (No*) malloc(sizeof(No)); //alocar espa�o de mem�ria para o novo n�

   if (p == NULL)
   {
      printf("Faltou espa�o de memoria. N�o � possivel inserir um novo elemento");
   }
   else
   {
       /*Armazenar os dados da "pessoa", recebidos como par�metro de entrada, na
       vari�vel "d" dentro do n� "p" criado no comando anterior*/
       p->info.codigo = d->codigo;
       strcpy(p->info.nome,d->nome);
       p->info.idade = d->idade;
       strcpy(p->info.telefone,d->telefone);
       p->prox = NULL;

       No* ant = NULL; // ponteiro auxiliar que aponta para o n� anterior ao que est� sendo an�lisado
       No* q = l->prim; // ponteiro para percorrer a lista - apontado inicialmente para o in�cio da lista

       // procura elemento na lista, guardando anterior
       while ((q != NULL) && (q->info.codigo < d->codigo)) {
          ant = q;
          q = q->prox;
       }

       if(ant == NULL){ //o elemento a ser inserior tem o menor c�digo, ou � o primeiro
                        // a ser inserido na lista - insere o elemento no in�cio
           p->prox = l->prim;
           l->prim = p;
       }
       else { // insere elemento no meio/fim da lista
              p->prox = ant->prox;
              ant->prox = p;
            }

       l->quantidade++; //incrementar a quantidade de elementos da lista
   }

}

/******************************************************************************/
/* Fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia                         */
/******************************************************************************/
int vazia (Lista* l)
{
   return (l->prim == NULL);
}


/******************************************************************************/
/* Fun��o imprime: imprime valores dos elementos                              */
/******************************************************************************/
void imprime (Lista* l)
{
   No* q;  /* vari�vel auxiliar para percorrer a lista */
   if(!vazia(l))
   {
       printf("\n\n***** Elementos da Lista ******\n\n");
       printf("===>Tamanho da Lista: %d\n\n",tamanho(l));
       for (q = l->prim; q != NULL; q = q->prox){
           printf("%d\n",q->info.codigo);
           printf("%s\n",q->info.nome);
           printf("%d\n",q->info.idade);
           printf("%s\n\n",q->info.telefone);
       }
       getchar();
   }
}

/******************************************************************************/
/* fun��o busca: busca um elemento na lista                                   */
/******************************************************************************/
void busca (Lista* l, int cod)
{
   No *q; // ponteiro auxiliar para percorrer a lista

   if (!vazia(l))
   {

      int achou = 0;
      printf("\n\n***** Dados o item consultado na Lista ******\n\n");
      q = l->prim;
      while ((!achou)&&(q!=NULL)){
          if (q->info.codigo == cod){ //buscar a pessoa com o "cod" na lista
             printf("%d\n",q->info.codigo);
             printf("%s\n",q->info.nome);
             printf("%d\n",q->info.idade);
             printf("%s\n",q->info.telefone);
             achou = 1;
             getchar();
          }
          else
               q = q->prox;
      }
      if (!achou)
         printf("Elemento nao encontrado");
   }
   else {
           printf("Lista Vazia");
        }
}

/******************************************************************************/
/* Fun��o tamanho: Retorna a quantidade de elementos da lista                 */
/******************************************************************************/
int tamanho(Lista* l){
 return l->quantidade;
}

/******************************************************************************/
/* Fun��o retira: retira elemento da lista                                    */
/******************************************************************************/
int retira (Lista* l, int v) {
   No* ant = NULL; // ponteiro para elemento anterior
   No* q = l->prim; // ponteiro para percorrer a lista
   // procura elemento na lista, guardando anterior
   while ((q != NULL) && (q->info.codigo != v)) {
      ant = q;
      q = q->prox;
   }

   //verifica se achou elemento
   if (q == NULL) // O Elemento n�o foi encontrado na lista
      return 0; //0 � insucesso na remo��o

   /* Retira elemento */

   if (ant == NULL) { /* retira elemento do inicio */
      /* reapontar o in�cio (prim) para o pr�ximo n� do elemento que ser� retirado */
      l->prim = q->prox;
   }
   else { /* retira elemento do meio/fim da lista */
      /* apontar o n� anterior do que ser� exclu�do para o posterior do que ser� exclu�do*/
      ant->prox = q->prox;
   }
   free(q); //liberar o espa�o de mem�ria do n� exclu�do da lista
   l->quantidade--; //decrementar a quantidade de elementos da lista.
   return 1; // 1 � sucesso na remo��o
}

/******************************************************************************/
/* Procedimento para Liberar o espa�o de mem�ria reservado para a lista       */
/******************************************************************************/
void libera (Lista* l)
{
   //t e q s�o ponteiros aulixares para percorrer a lista
   No* q = l->prim;
   // o while a server para liberar o espa�o de mem�ria n� a n�
   while (q != NULL) {
       No* t = q->prox;
      free(q);
      q = t;
   }
   free(l); //liberar o espa�o da estrutura do tipo Lista (criada na fun��o "cria")

}
