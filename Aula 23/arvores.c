#include <stdio.h>

typedef struct no{
    int info;
    struct no* sae;
    struct no* sad;
} No;

No* arv_cria_vazia();
No* arv_cria(int info, No* sae, No* sad);
void arv_imprime(No* arvore);
No* arv_deleta(No* arvore);

int main(){
    No* arvore = arv_cria_vazia();

    arvore = arv_cria(
        4,
        arv_cria(
            2,
            arv_cria(
                1,
                NULL,
                NULL),
            arv_cria(
                3,
            NULL,
            NULL)
        ),
        arv_cria(
            6,
            arv_cria(
                5,
                NULL,
                NULL
            ), 
            arv_cria(
                7,
                NULL,
                NULL
            )
        )
    );

    // Imprime uma árvore com uma função recursiva.
    arv_imprime(arvore);

    // Deleta uma árvore com uma função recursiva.
    arvore = arv_deleta(arvore);

    return 0;
}

No* arv_cria_vazia(){
    return NULL;
}

No* arv_cria(int info, No* sae, No* sad){
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->info = info;
    novo_no->sae = sae;
    novo_no->sad = sad;
    return novo_no;
}

void arv_imprime(No* arvore){
    if(arvore != NULL){
        arv_imprime(arvore->sae);
        printf("%d\n", arvore->info);
        arv_imprime(arvore->sad);
    }
}

No* arv_deleta(No* arvore){
    if(arvore != NULL){
        arv_deleta(arvore->sae);
        arv_deleta(arvore->sad);
        free(arvore);
    }
    return NULL;
}