#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct filas fila_t;


fila_t * cria_fila (void);

void enqueue(void* dado, fila_t *fila);
void* dequeue(fila_t *fila);

/* Verifica se um endereco de valor dado pertence a fila */
int contem(fila_t* fila, void *dado);

int fila_vazia(fila_t *fila);
void libera_fila(fila_t* fila);

#endif // FILA_H_INCLUDED
