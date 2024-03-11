#ifndef __LISTA_DUP_H__
#define __LISTA_DUP_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no_dup
{
    int valor;
    struct est_no_dup *ant, *prox;
};

typedef struct est_no_dup tipo_noh_dup;

tipo_noh_dup *aloca_noh(int);
void insereInicioListDup (tipo_noh_dup**, int);
void insereFimListDup( tipo_noh_dup**, int);
void inserePosListDup(tipo_noh_dup **, int, int);
int removeInicioListDup(tipo_noh_dup**);
int removeFimListDup(tipo_noh_dup**);
int RemovePosListDup(tipo_noh_dup **, int);
void imprimeListDup(tipo_noh_dup*);



#endif