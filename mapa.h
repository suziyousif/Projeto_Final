#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "grafo.h"

typedef struct local_ambulancias local_ambulancias_t;

grafo_t *ler_arquivo (char *nome_arquivo);
local_ambulancias_t *cria_local(char *name);
lista_enc_t * ler_arquivo_ambulancias (char *nome_arquivo);
void set_local (local_ambulancias_t *ambulancia, char *nome);
char * get_local (local_ambulancias_t *ambulancia);
void libera_local_ambulancias(lista_enc_t *lista);
//int n_bairros (char **vetor, int tamanho);
#endif // MAPA_H_INCLUDED
