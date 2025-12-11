#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* sae;
    struct no* sad;
} No;

No* arv_cria_vazia();
No* arv_cria(int info, No* sae, No* sad);
void arv_imprime(No* arvore);
No* arv_deleta(No* arvore);
int arv_pertence(No* arvore, int info);
static max2(int a, int b);
int arv_altura(No* arvore);

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

    printf("## PROFUNIDADE EM ÁRVORES ##\n");
    printf("\n>> Essa árvore criada possui altura máxima de %d.\n", arv_altura(arvore));;
    
    // Imprime uma árvore com uma função recursiva.
    arv_imprime(arvore);

    // BUSCA EM ÁRVORES BINÁRIAS
    printf("\n##BUSCA##");
    printf("\nDigite um número: ");
    int numero_busca = -1;
    scanf("%d%*c",&numero_busca);
    printf("O elemento %d ", numero_busca);
    if(arv_pertence(arvore, numero_busca)){
        printf("está na árvore.");
    }
    else{
        printf("não está na árvore.");
    }

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

int arv_vazia(No* arvore){
    return arvore == NULL;
}

int arv_pertence(No* arvore, int info){
    if(arv_vazia(arvore))
        return 0;
    else
        return arvore->info == info ||
        arv_pertence(arvore->sae, info)||
        arv_pertence(arvore->sad, info);
}

static max2(int a, int b){
    return (a>b)?a:b;
}

int arv_altura(No* arvore){
    if(arv_vazia(arvore))
        return -1;
    else
        return 1 + max2(
            arv_altura(arvore->sae),
            arv_altura(arvore->sad));
}