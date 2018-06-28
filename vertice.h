#ifndef GRAFO_VERTICE_H_
#define GRAFO_VERTICE_H_

#include "../lista_enc/lista_enc.h"


typedef struct vertices vertice_t;
typedef struct arestas arestas_t;

/* Tipo enum o status das arestas: utilizado para exportação do DOT */
typedef enum status_aresta { VAZIO, EXPORTADA } status_aresta_t;


vertice_t *cria_vertice(char *name);
arestas_t *cria_aresta(vertice_t *fonte, vertice_t *destino, float peso);


char* vertice_get_name(vertice_t *vertice);

/* Adiciona uma aresta a um grafo */
void adiciona_aresta(vertice_t *vertice, arestas_t *aresta);

/* Obtem a lista encadeada das arestas */
lista_enc_t *vertice_get_arestas(vertice_t *vertice);

/* Retorna o peso de um aresta */
float aresta_get_peso (arestas_t *aresta);

/* Obtem o destinho de uma aresta */
vertice_t *aresta_get_adjacente(arestas_t *aresta);

/* Retorna uma aresta caso seja fonte ou destino */
arestas_t *procurar_adjacente(vertice_t *vertice, vertice_t *adjacente);

/* Configura status de uma aresta */
void aresta_set_status(arestas_t *aresta, status_aresta_t status);

/* Obtem o status de uma aresta */
status_aresta_t aresta_get_status (arestas_t *aresta);


/* Configura membro id_grupo da struct vertice
 * Ver: struct vertices */
void vertice_set_grupo(vertice_t *vertice, int grupo);

/* Configura membro pai da struct vertice
 * Ver: struct vertices */
void vertice_set_pai(vertice_t *vertice, vertice_t *pai);


/* Obtem membro id_grupo da struct vertice
 * Ver: struct vertices */
int vertice_get_grupo(vertice_t *vertice);


vertice_t * vertice_get_pai(vertice_t *vertice);

#endif /* GRAFO_VERTICE_H_ */
