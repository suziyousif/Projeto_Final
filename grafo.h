#ifndef GRAFO_H_
#define GRAFO_H_


#define MAX_VERTICES 50

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia_nao_dir(grafo_t *g, int u, int v, int peso);

int rem_adjacencia(grafo_t *g, int u, int v);

/* Retorna se existe adjacencia entre os vertices u e v */
int adjacente(grafo_t *g, int u, int v);

void define_name (grafo_t *grafo, int id, char *name);

void exportar_grafo_dot(const char *filename, grafo_t *grafo);


#endif /* GRAFO_H_ */
