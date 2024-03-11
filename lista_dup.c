#include "lista_dup.h"

tipo_noh_dup *aloca_noh(int vl){
    tipo_noh_dup * novo_no;
    novo_no = (tipo_noh_dup *) malloc (sizeof(tipo_noh_dup));
    novo_no -> valor = vl;
    novo_no -> prox = NULL;
    novo_no -> ant = NULL;
    return novo_no;
}

void insereInicioListDup (tipo_noh_dup** list, int vl ){
    tipo_noh_dup *novo_no;
    novo_no = aloca_noh (vl);

    if ((*list)!= NULL){
        novo_no -> prox = (*list);
        (*list) -> ant = novo_no;
        (*list) = novo_no;

    }else{
        (*list) = novo_no;
    }
}

void insereFimListDup( tipo_noh_dup**lst, int vl ){
    tipo_noh_dup * novo_no, *aux;
    novo_no = aloca_noh(vl);

    if ((*lst) != NULL){
        aux = (*lst);
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        novo_no -> ant = aux ;
        aux -> prox = novo_no ;
        
        
    }else{
        insereInicioListDup(lst, vl);
    }
}

void inserePosListDup(tipo_noh_dup **lst, int vl, int pos){
    tipo_noh_dup *aux, * novo_no;
    int contador = 0;
    novo_no = aloca_noh(vl);

    if ( pos != 0){
       aux = (*lst);

       while ((aux != NULL) && (contador < pos))
       {
        aux = aux -> prox;
        contador ++;
       }
       if ( pos > contador){
        printf ("[ERRO] POSIÇÃO INVÁLIDA\n\n");

       }else{
            if((aux != NULL) && ( contador == pos)){
                novo_no -> ant = aux -> ant;
                novo_no -> prox = aux;
                novo_no -> ant -> prox = novo_no;
                novo_no -> prox ->ant = novo_no;
            
            }else if ((aux == NULL) && (contador == pos)){
                insereFimListDup(lst, vl);
            }
        }

    }else{
        insereInicioListDup(lst, vl);
    }
}

int removeInicioListDup(tipo_noh_dup**lst){
    tipo_noh_dup *aux;
    int vl;

    if ((*lst) != NULL){

        vl = (*lst) -> valor;
        aux =  (*lst);
        (*lst) = (*lst) -> prox;
        if((*lst) -> prox != NULL){
            (*lst) -> ant = NULL;
        }
        free (aux);
        return vl;
        
    }else{
        printf("\n\nLista vazia\n\n");
        return -1;
    }
}   

int removeFimListDup(tipo_noh_dup**lst){
    tipo_noh_dup *aux;
    int vl;

    if ((*lst) != NULL){
        aux = (*lst);

        while ( aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        vl = aux -> valor;

        if(aux -> ant != NULL){ //verifica se não é o último no
            aux -> ant -> prox = NULL;
            aux -> ant = NULL;
        }

        //verifica se é o ultimo no
        if (((*lst) -> ant == NULL) && ((*lst)-> prox == NULL)){
            (*lst) = NULL;
        }
        free (aux);
        return vl;
        
    }else{
        printf ("Lista vazia, erro na remoção\n");
        return -1;
    }
}

int RemovePosListDup(tipo_noh_dup ** lst, int pos){
    tipo_noh_dup *aux;
    int contador = 0;
    int vl;


    if ((*lst) != NULL){
        aux = (*lst);

        if (pos != 0){
            while (aux != NULL && contador < pos)
            {
                aux = aux -> prox;
                contador ++;
            }

            if (pos > contador){

                printf ("[ERRO NA REMOÇÃO POSIÇÃO INVÁLIDA] \n\n");
                return -1;
            
            }else{
                if (aux != NULL && contador == pos){
                    vl = aux -> valor;
                    aux -> ant -> prox = aux -> prox;
                    aux -> prox-> ant = aux -> ant;
                    free ( aux);
                    return vl;

                }else if ( aux == NULL && contador == pos){
                    removeFimListDup(lst);
                }
            }    
        }

        else{
            removeInicioListDup(lst);
        }

    }else{
        printf (" [ERRO] LISTA VAZIA\n\n");
        return -1;
    }
}

void imprimeListDup(tipo_noh_dup*lst){
    printf("Lista dup: ");
    if (lst == NULL){
        printf ("lista vazia\n\n");
    }
    else{
        while (lst !=NULL){
            printf ("[%d] ", lst-> valor);
            lst = lst -> prox;
        }
        printf(" \n\n");
    }
    
    
}
