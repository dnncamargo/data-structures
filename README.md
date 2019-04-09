# data-structures

Primeiro Trabalho (A1)

Data de entrega: 15/04/2019.

Forma de entrega: O código fonte do trabalho deverá se encaminhado por e-mail e o aluno deverá apresentar o trabalho para o professor em sala.

Trabalho em dupla ou individual

Forma de Avaliação: O trabalho vale 10,0, sendo 20% do total da nota da A1.

Especificação do Trabalho:

Aplicações de heap max-min e min-max são implementas com o objetivo de acessar o elemento que possui a maior e a menor prioridade. 
Esta estrutura Implementa estrutura de vetores e podem ser vistas como árvores binárias completas.

Operações:
•	Criar a estrutura da lista de prioridade (heap);
•	Consulta do elemento de maior ou de menor prioridade;
•	Inserção de um elemento;
•	Remoção do elemento de maior ou de menor prioridade.

Propriedades:
•	O elemento raiz deve ocupar a posição 1 do vetor.
•	O vetor utilizado para armazenar n elementos tem a posição inicial zero.
•	Em um heap max-min o elemento de maior prioridade ocupa sempre a posição 1 do vetor.
•	Em um heap min-max o elemento de menor prioridade ocupa sempre a posição 1 do vetor.
•	Cada elemento do vetor corresponde a um nó da árvore binária e encontra-se em um nível.
•	Em um heap max-min os níveis ímpares são chamados níveis máximos e os pares níveis mínimos.
•	Em um heap min-max os níveis ímpares são chamados níveis mínimos e os pares níveis máximos.
•	Em um heap max-min, se o nível de um nó i é máximo (ímpar) a sua chave é superior à chave do seu pai e inferior à chave do seu avô.
•	Em um heap min-max, se o nível de um nó i é mínimo (ímpar) a sua chave é inferior à chave do seu pai e superior à chave do seu avô.
•	Em um heap max-min e em um heap min-max a chave de um nó i é:
◦	Superior às chaves de seus descendentes, quando i está situado em um nível máximo
◦	Inferior às chaves de seus descendentes quando i é situado em um nível mínimo.

Implemente as versões do heap-max-min e heap-min-max na linguagem C, organizando o código em um tipo abstrato de dados(TAD). Estes TAD deverão fornecer no mínimo as 4 operações descritas acima.
