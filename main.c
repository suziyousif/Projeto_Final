/*
 ============================================================================
 Name        : main.c
 Author      : Heloiza Martins Schaberle e Suzi Yousif
 Version     :
 Copyright   : Instituto Federal de Santa Catarina
 Description : Shortest Path
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "mapa.h"

#define TAM_BUFFER 128

int main(void) {

	grafo_t *g;
	g = ler_arquivo("mapa.txt");
    exportar_grafo_dot("teste.txt", g);
	vertice_t *vertice;
	//vertice_t *vertice2;
	//arestas_t *aresta;
	vertice = procura_vertice (g, "Ponta das Canas");
	//vertice2 = procura_vertice (g, "Ponta das Canas");
	// printf("v2 = %s\n", vertice_get_name(vertice2));
	//printf("v1 = %s\n", vertice_get_name(vertice));
   // aresta = procurar_adjacente(vertice2, vertice);

    //printf("%f\n", aresta_get_peso(aresta));


  //  Dijkstra(g, vertice);

    //print_vertice(g);
    lista_enc_t *lista_amb;
    lista_amb = ler_arquivo_ambulancias("garagem_ambulancias.txt");
    Dijkstra(g, vertice);
    libera_grafo(g);
    libera_local_ambulancias(lista_amb);

	return EXIT_SUCCESS;
}
