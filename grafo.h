#ifndef GRAFO_GRAFO_H_
#define GRAFO_GRAFO_H_

#include "vertice.h"

typedef struct grafos grafo_t;

/* Cria um novo grafo com id */
grafo_t *cria_grafo(int id);

/* Adiciona um vertice ao grafo */
vertice_t* grafo_adicionar_vertice(grafo_t *grafo, char *name);

/* Cria arestas:
 * grafo: grafo que pertence a aresta
 * vertice: ponteiro do vertice que se deseja adicionar arestas
 * n: numero total dos proximos parametros
 * proximos parametros: par ordenado composto por: <vert. destino> , <peso da aresta>
 * Ex: adicionar uma aresta para o vertice 2 e 3 com respectivos pesos 9 e 15
 * adiciona_adjacentes(grafo, vertice, 4, 2, 9, 3, 15);  */
void adiciona_adjacentes(grafo_t *grafo, vertice_t *vertice_1, vertice_t *vertice_2, float peso);

/* Procura um vertice no grafo com id numerico */
vertice_t* procura_vertice(grafo_t *grafo, char *name);

/* Exporta o grafo utilizando a linguagem dot */
void exportar_grafo_dot(const char *filename, grafo_t *grafo);

/* Libera memoria utilizada pelo grafo */
void libera_grafo (grafo_t *grafo);

/* Menor camingo entre todos os nos:
 * retorna um pilha do caminho entre fonte e destino  */
//pilha_t* Dijkstra(grafo_t *grafo, vertice_t *fonte, vertice_t *destino);

/* Procura um vertice com menor a menor distancia
 * Ver: struct vertices */
no_t *busca_menos_distante(lista_enc_t *Q);

/* Retorna TRUE se vertice_procurado estiver no conjunto Q*/
int busca_vertice(lista_enc_t *lista, vertice_t *vertice_procurado);

lista_enc_t* componentes_conexos(grafo_t *grafo);

void print_vertice (grafo_t *grafo);

void Dijkstra(grafo_t *grafo, vertice_t *fonte);
void imprimir_caminho(grafo_t *grafo, lista_enc_t *lista_ambulancias, char *destino);
#endif /* GRAFO_GRAFO_H_ */
