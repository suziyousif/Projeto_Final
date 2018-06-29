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

    int i = 1;

    printf("\t   Bem Vindo a Central de Emergencia\n\n");
    printf("Para solicitar uma ambulancia, digite 1\nCaso queira sair da central, digite 2\n->");
    scanf("%d", &i);
    getchar();
    if(i == 1){
        grafo_t *g;
        g = ler_arquivo("mapa.txt");
        //exportar_grafo_dot("teste.dot", g);
        char destino[TAM_BUFFER];
        printf("\nDigite o local de sua emergencia e mandaremos a ambulancia mais proxima ate voce\n\t\t");
        fflush(stdin);
        scanf("%[^\n]", destino);
        printf("\n");

        lista_enc_t *lista_amb;
        lista_amb = ler_arquivo_ambulancias("garagem_ambulancias.txt");
        imprimir_caminho(g, lista_amb, destino);
        libera_grafo(g);
        libera_local_ambulancias(lista_amb);
    }
	return EXIT_SUCCESS;
}
