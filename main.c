#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "grafo.h"
#include "mapa.h"

int main(void) {

	grafo_t *g;

	/* Cria um grafo com seis vértices */

	ler_arquivo("mapa.txt");
	//exportar_grafo_dot("teste.txt", g);
	/*vertice_t *vertice;
	vertice_t *vertice2;
	arestas_t *aresta;
	vertice = procura_vertice (g, "Jurere");
	vertice2 = procura_vertice (g, "Ponta das Canas");
	 printf("v2 = %s\n", vertice_get_name(vertice2));
	printf("v1 = %s\n", vertice_get_name(vertice));
    aresta = procurar_adjacente(vertice2, vertice);

    printf("%f\n", aresta_get_peso(aresta));

    aresta = procurar_adjacente(vertice, vertice2);

    printf("%f\n", aresta_get_peso(aresta));*/

    print_vertice(g);

	return EXIT_SUCCESS;
}

