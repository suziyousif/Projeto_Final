/*
 ============================================================================
 Name        : mapa.c
 Author      : Heloiza Martins e Suzi Yousif
 Version     :
 Copyright   : Instituto Federal de Santa Catarina
 Description : Shortest Path
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"
#include "mapa.h"
#include "lista_enc.h"
#include "no.h"

#define TAM_BUFFER 128
#define FALSE 0
#define TRUE 1

struct local_ambulancias{
    char *local;
};

grafo_t *ler_arquivo (char *nome_arquivo){

    int ret;
    char buffer_string[TAM_BUFFER];
    char bairro_1 [TAM_BUFFER];
    char bairro_2 [TAM_BUFFER];
    float peso;

    vertice_t *vertice_1;
    vertice_t *vertice_2;

    grafo_t *grafo = NULL;

    //abrir o arquivo
	FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL){
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }
    grafo = cria_grafo(0);

    if (grafo == NULL){
			perror("Erro grafo");
			exit(EXIT_FAILURE);
    }

	while (fgets(buffer_string,128,fp)!= NULL){
        ret = sscanf(buffer_string,"%46[^;]; %46[^;]; %f\n", bairro_1, bairro_2, &peso);

            if (ret != 3){
                perror("sscanf:");
                exit(1);
            }
            vertice_1 = procura_vertice(grafo, bairro_1);
            vertice_2 = procura_vertice(grafo, bairro_2);

            if (vertice_1 == NULL) {
                vertice_1 = grafo_adicionar_vertice(grafo, bairro_1);
            }
            if (vertice_2 == NULL){
                vertice_2 = grafo_adicionar_vertice(grafo, bairro_2);
            }
            adiciona_adjacentes(grafo, vertice_1, vertice_2, peso);
            #ifdef DEBUG
            printf("v1: %s, v2: %s\n", vertice_get_name(vertice_1), vertice_get_name(vertice_2));
            printf("%f\n", aresta_get_peso(procurar_adjacente(vertice_1, vertice_2)));
            #endif // DEBUG
	}
    fclose(fp);
    return grafo;
}

// funçao para ver a quantidade de bairros no arquivo (caso necessario)
/*int n_bairros (char **vetor, int tamanho){
    int i, j;
    int qtd_cidades = tamanho;
    for (i = 0; i < tamanho; i++){
        for(j = i+1; j < tamanho; j++){
            if (strcmp(vetor[i], vetor[j]) == 0 && strcmp(vetor[j], "buscado") != 0){
                #ifdef Debug
                printf("> %s <> %s <> %d\n", vetor[i], vetor[j], qtd_cidades);
                #endif // Debug
                strcpy(vetor[j], "buscado");
                qtd_cidades--;
            }
        }
    }
    return qtd_cidades;
}*/

local_ambulancias_t *cria_local(char *name)
{
	local_ambulancias_t *ambulancia = NULL;

	ambulancia = malloc(sizeof(local_ambulancias_t));

	if (ambulancia == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}
	int tamanho;
	tamanho = strlen(name);
	ambulancia->local = malloc(tamanho + 1);
	if(ambulancia->local == NULL){
        perror("Erro na alocacao ambulancia->local: ");
        exit(1);
    }

    strncpy(ambulancia->local, name, tamanho + 1);

	return ambulancia;
}

lista_enc_t * ler_arquivo_ambulancias (char *nome_arquivo){

    char buffer_string [TAM_BUFFER];
    char ambulancia_aux[TAM_BUFFER];
    no_t *no;
    int ret= 0;
    lista_enc_t *lista_ambulancias = cria_lista_enc();
    local_ambulancias_t *ambulancia = NULL;
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL){
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }
     while(fgets(buffer_string,TAM_BUFFER,fp) != NULL){
        ret = sscanf(buffer_string,"%46[^;];\n", ambulancia_aux);
        if (ret != 1){
            perror("sscanf:");
            exit(1);
        }
        ambulancia= cria_local(ambulancia_aux);
        no=cria_no(ambulancia);
        add_cauda(lista_ambulancias, no);
     }
     fclose(fp);
     #ifdef DEBUG
     no = obter_cabeca(lista_ambulancias);
     while(no){
         printf("%s\n", get_local(obter_dado(no)));
         no = obtem_proximo(no);
     }
     #endif // DEBUG
     return lista_ambulancias;
}
char * get_local (local_ambulancias_t *ambulancia){
    return ambulancia->local;
}

void set_local (local_ambulancias_t *ambulancia, char *nome){
    ambulancia->local = nome;
}

void libera_local_ambulancias(lista_enc_t *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr, "Erro! libera_lista_ambulancia!");
        exit(EXIT_FAILURE);
    }
    no_t *meu_no=obter_cabeca(lista);
    while (meu_no!=NULL)
    {
        local_ambulancias_t *amb=obter_dado(meu_no);
        free(amb->local);
        free(amb);
        no_t *proximo=obtem_proximo(meu_no);
        free(meu_no);
        meu_no=proximo;
    }
    free(lista);
}

