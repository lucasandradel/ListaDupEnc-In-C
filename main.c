#include "lista_dup.h"


int main(int argc, char *argv[]){
    tipo_noh_dup *minha_lista_dup;
    minha_lista_dup = NULL;

    insereInicioListDup(&minha_lista_dup, 10);
    insereInicioListDup(&minha_lista_dup, 9);
    insereInicioListDup(&minha_lista_dup, 90);
    insereInicioListDup(&minha_lista_dup, 91);
    


    printf("\nValores do inicio inseridos: \n ");
    imprimeListDup(minha_lista_dup);

    insereFimListDup(&minha_lista_dup, 199);
    insereFimListDup(&minha_lista_dup, 11);
    insereFimListDup(&minha_lista_dup, 100);
    

    printf("Lista após inserção no final\n ");
    imprimeListDup(minha_lista_dup);

    
    printf ("lista após remoção do elemento: %d \n", RemovePosListDup(&minha_lista_dup, 2));
    imprimeListDup(minha_lista_dup);

    inserePosListDup(&minha_lista_dup, 1000, 0);
    printf ("lista após inserção da posição 0:\n  ");
    imprimeListDup(minha_lista_dup);

    
    printf("Lista após remoção do elemento inicial: %d\n  ", removeInicioListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento final: %d\n  ", removeFimListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento inicial: %d\n  ", removeInicioListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento final: %d\n  ", removeFimListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento inicial: %d\n  ", removeInicioListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento inicial: %d\n  ", removeInicioListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);

    printf("Lista após remoção do elemento final: %d\n  ", removeFimListDup(&minha_lista_dup));
    imprimeListDup(minha_lista_dup);
    
    

    return EXIT_SUCCESS;
}

