/* ********************************************************************* */
/* Disciplina: Linguagem de Programacao 3                                */
/* Professor:Andr�                                                       */
/* Objetivo de Programa: Interface da TAD Lista (Nome e Telefone)        */
/* T�pico da Disciplina: Estrutura de Dados do Tipo Lista                */
/* ********************************************************************* */

/* Estrutura de Dados que armazena a Lista*/
typedef struct lista Lista;

struct dados{
 int codigo;
 char nome[30];
 int idade;
 char telefone[9];
};

typedef struct dados Dados;

/* Fun��o que cria a Lista*/
Lista* cria (void);

/* Procedimento Inserir na Lista - fora de ordem */
void insere(Lista* l, Dados* d);

/* Procedimento Inserir na Lista - fora de ordem */
void insere_ordenado(Lista* l, Dados* d);

/* Fun��o que verifica se uma Lista est� vazia*/
int vazia (Lista* l);

/* Procedimento para busca um elemento na Lista*/
void busca (Lista* l, int cod);

/* Fun��o que retorna o tamanho da Lista */
int tamanho(Lista* l);

/*Fun��o que retira um elemento da Lista*/
int retira (Lista* l, int v);

/* Procedimento para liberar a �rea de mem�ria reservada para a Lista*/
void libera (Lista* l);

/* Imprimir os elementos da Lista */
void imprime(Lista* l);
