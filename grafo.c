#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "grafo.h"

#include <limits.h>

#define INFINITO INT_MAX
#define DEBUG


struct vertices {
	/* Identificador do vertice:
	 * pode ser utilizado na matriz de adjacencia 	 */
	int id;
	char *name;

	/* Informaçoes para Dijkstra */
	int distancia;
	vertice_t *predecessor;
};

struct arestas {
	/* Verdadeiro se exite adjacencia */
	int adj;

	/* Peso da aresta */
	float peso;
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;	/* Matriz de adjacencia */
};

/*
void libera_grafo (grafo_t *g){

    if (g == NULL)      {
		fprintf(stderr, "libera_grafo: grafo invalido\n");
		exit(EXIT_FAILURE);
	}
	int i;

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}*/

grafo_t *cria_grafo(int vertices){

	int i;
	aresta_t **matriz_adj;

	grafo_t *g = malloc(sizeof(grafo_t));
	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	g->n_vertices = vertices;

	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	memset(g->vertices, 0, vertices * sizeof(vertice_t));

	for (i=0; i < vertices; i++)
		g->vertices[i].id = i;

	matriz_adj = malloc(vertices * sizeof(aresta_t*));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	for ( i = 0; i < vertices; i++ ){
		matriz_adj[i] = malloc(vertices * sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
		/* Nenhuma adjacência */
		matriz_adj[i]->adj = 0;

	}

	g->matriz_adj = matriz_adj;

	return g;

}


void define_name (grafo_t *grafo, int id, char *name){

    if (grafo == NULL){
		fprintf(stderr, "define_name: grafo invalido\n");
		exit(EXIT_FAILURE);
	}

	if (id > grafo->n_vertices)	{
		fprintf(stderr,"define_name: grafo invalido");
		exit(EXIT_FAILURE);
	}
	int size;
	size = strlen(name);
	grafo->vertices[id].name = malloc(size+1);
	strncpy(grafo->vertices[id].name, name, size+1);
}


int cria_adjacencia_nao_dir(grafo_t *g, int u, int v, int peso){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;
	g->matriz_adj[v][u].adj = TRUE;
	g->matriz_adj[v][u].peso = peso;
	g->matriz_adj[u][v].peso = peso;

	return TRUE;
}

int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;
	g->matriz_adj[v][u].adj = FALSE;

	return TRUE;

}

int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices  || v > g->n_vertices )
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

/*
void exportar_grafo_dot(const char *filename, grafo_t *grafo){
	FILE* file;
    int i, j;

	if (filename == NULL || grafo == NULL){
		fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");
	if (file == NULL){
		perror("exportar_grafp_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	/* Exporta as strings dos vértices
	for (i=0; i < grafo->n_vertices; i++){
		 fprintf(file, "\t%d;\n", i);
	}

    for( i = 0; i < grafo->n_vertices; i++ )
        for(j = i; j < grafo->n_vertices; j++)	// Exporta adjacencia na diagonal superior
            if( (grafo->matriz_adj[i][j].adj) == TRUE)
                fprintf(file, "\t%d -- %d [label=%d];\n", i, j, grafo->matriz_adj[i][j].peso);    //[label="d0_1=1*27(4)"style=solid]

    fprintf(file, "}\n");
	fclose(file);
}*/
