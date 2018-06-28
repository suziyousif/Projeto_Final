#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "grafo.h"
#define TAM_BUFFER 128
#include <string.h>

void ler_arquivo (char *nome_arquivo){

    int ret;
    char buffer_string[TAM_BUFFER];
    char *bairros_aux [TAM_BUFFER];
    int k;

    for (k = 0; k < TAM_BUFFER; k++)
        bairros_aux[k] = malloc(sizeof(char)* TAM_BUFFER);

    char bairro_1 [TAM_BUFFER];
    char bairro_2 [TAM_BUFFER];
    float peso;
    int qtd_bairros;
    int size = 0;
    grafo_t *grafo;
    int i=0;
    int j =1;
    //abrir o arquivo
	FILE *fp = fopen(nome_arquivo, "r");
		if (fp == NULL){
			perror("Erro em main: fopen");
			exit(EXIT_FAILURE);
		}
    while(fgets(buffer_string,128,fp)!= NULL){
        ret = sscanf(buffer_string,"%46[^;]; %46[^;]; %f\n", bairros_aux[i], bairros_aux[j], &peso);
        if (ret != 3){
                perror("sscanf:");
                exit(1);
        }
        i = i + 2;
        j = j + 2;
        size++;
    }
    size = (size * 2) -1;

    #ifdef DEBUG
    printf("size: %d\n", size);
    for (i=0; i<32; i++)
       printf("%s\n",bairros_aux[i]);
    #endif // DEBUG

    qtd_bairros = n_bairros(bairros_aux, size);
    grafo = cria_grafo(qtd_bairros);

    rewind(fp);
    //pegar a linha
	while (fgets(buffer_string,128,fp)!= NULL){
        ret = sscanf(buffer_string,"%46[^;]; %46[^;]; %f\n", bairro_1, bairro_2, &peso);
            if (ret != 3){
                perror("sscanf:");
                exit(1);
            }


	}
    fclose(fp);
}

int n_bairros (char **vetor, int tamanho){
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
}
