#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vertice.h"
#include "lista_enc.h"

struct vertices {
	int id;
	char *name;
	lista_enc_t *arestas;

	/* Informacoes para componentes conexos */
	float dist;
	vertice_t* pai;

};

struct arestas {
	float peso;
	vertice_t *fonte;
	vertice_t *dest;

	/* status para expotacao em arquivo */
	status_aresta_t status;
};


vertice_t *cria_vertice(char *name)
{
	vertice_t *p = NULL;

	p = malloc(sizeof(vertice_t));

	if (p == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}
	int tamanho;
	tamanho = strlen(name);
	p->name = malloc(tamanho + 1);
	if(p->name == NULL){
        perror("Erro na alocacao p->name: ");
        exit(1);
    }

    strncpy(p->name, name, tamanho + 1);
	p->arestas = cria_lista_enc();
	//------------------
	p->dist = -1;
	p->pai = NULL;

	return p;
}

char *vertice_get_name(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_get_name: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->name;
}

arestas_t *cria_aresta(vertice_t *fonte, vertice_t *destino, float peso)
{
	arestas_t *p;

	p = (arestas_t*)malloc(sizeof(arestas_t));

	if (p == NULL) {
		perror("cria_aresta:");
		exit(EXIT_FAILURE);
	}

	p->peso = peso;
	p->fonte = fonte;
	p->dest = destino;

	return p;
}

void adiciona_aresta(vertice_t *vertice, arestas_t *aresta)
{
	no_t *no;

	if (vertice == NULL || aresta == NULL)	{
		fprintf(stderr, "adiciona_aresta: dados invalidos\n");
		exit(EXIT_FAILURE);
	}

	no = cria_no(aresta);
	add_cauda(vertice->arestas, no);

}

lista_enc_t *vertice_get_arestas(vertice_t *vertice)
{
	if (vertice == NULL){
		fprintf(stderr, "vertice_get_arestas: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	return vertice->arestas;
}

float aresta_get_peso (arestas_t *aresta) {
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_peso: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	return aresta->peso;
}

vertice_t *aresta_get_adjacente(arestas_t *aresta)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_adjacente: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	return aresta->dest;
}

arestas_t *procurar_adjacente(vertice_t *vertice, vertice_t *adjacente)
{
	no_t *no;
	arestas_t *aresta;

	if (vertice == NULL){
		fprintf(stderr, "procurar_adjacente: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	no = obter_cabeca(vertice->arestas);

	while (no){

		aresta = obter_dado(no);

		if (aresta->dest == adjacente || aresta->fonte == adjacente)
			return aresta;

		no = obtem_proximo(no);
	}

	return NULL;
}

status_aresta_t aresta_get_status (arestas_t *aresta)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_status: aresta invalida\n");
		exit(EXIT_FAILURE);
	}

	return aresta->status;
}

void aresta_set_status(arestas_t *aresta, status_aresta_t status)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_set_status: aresta invalida\n");
		exit(EXIT_FAILURE);
	}

	aresta->status = status;
}

/*------------------------------------------*/
void vertice_set_dist(vertice_t *vertice, float dist) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->dist = dist;
}

float vertice_get_dist(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->dist;
}

void vertice_set_pai(vertice_t *vertice, vertice_t *pai) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_pai: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->pai = pai;
}


vertice_t * vertice_get_pai(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->pai;
}




//void vertice_set_dist(vertice_t *vertice, int dist) {
//
//	if (vertice == NULL){
//			fprintf(stderr, "vertice_set_dist: vertice invalido\n");
//			exit(EXIT_FAILURE);
//	}
//
//	vertice->dist =  dist;
//}
//
//int vertice_get_dist(vertice_t *vertice){
//
//	if (vertice == NULL){
//			fprintf(stderr, "vertice_get_dist: vertice invalido\n");
//			exit(EXIT_FAILURE);
//	}
//
//	return vertice->dist;
//}
//
//int vertices_comprimento(vertice_t *fonte, vertice_t *destino)
//{
//	arestas_t *aresta;
//
//	if (fonte == NULL || destino == NULL){
//		fprintf(stderr, "vertices_comprimento: vertices invalidos\n");
//		exit(EXIT_FAILURE);
//	}
//
//	aresta = procurar_adjacente(fonte, destino);
//
//	if (aresta == NULL) {
//		fprintf(stderr, "vertices_comprimento: vertices nao adjacentes\n");
//		exit(EXIT_FAILURE);
//	}
//
//	return aresta->peso;
//}
//
//void vertice_set_antec_caminho(vertice_t *vertice, vertice_t *antecessor){
//
//	if (vertice == NULL || antecessor == NULL){
//		fprintf(stderr, "vertice_set_antec_caminho: vertices invalidos\n");
//		exit(EXIT_FAILURE);
//	}
//
//	vertice->antecessor_caminho = antecessor;
//}
//
//vertice_t *vertice_get_antec_caminho(vertice_t *vertice) {
//	if (vertice == NULL){
//		fprintf(stderr, "vertice_get_antec_aminho: vertice invalidos\n");
//		exit(EXIT_FAILURE);
//	}
//
//	return vertice->antecessor_caminho;
//}
