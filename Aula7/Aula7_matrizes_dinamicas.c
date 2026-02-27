#include <stdio.h>
#include <stdlib.h>

float** matriz_cria(int linhas, int colunas);
void matriz_deleta(float** matriz, int linhas);
float** matriz_duplica(float** matriz, int linhas, int colunas);
float** matriz_soma(float** matriz_a, int linhas_a, int colunas_a, float** matriz_b, int linhas_b, int colunas_b);
float** matriz_subtrai(float** matriz_a, int linhas_a, int colunas_a, float** matriz_b, int linhas_b, int colunas_b);
float** matriz_transposta(float** matriz, int linhas, int colunas);
void matriz_imprime(float** matriz, int linhas, int colunas);
void matriz_inicializa(float** matriz, int linhas, int colunas);

float** matriz_multiplica(float** matriz_a, int linhas_a, int colunas_a, float** matriz_b, int linhas_b, int colunas_b);




int main(void){

    int linhas=3, colunas=2;
    float** mat = matriz_cria(linhas, colunas);
    
    matriz_imprime(mat, linhas, colunas);

    matriz_deleta(mat, linhas);
    
    return 1;
}


float** matriz_cria(int linhas, int colunas){
    
    // Cria a matriz
    float** mat = (float**)malloc(linhas*sizeof(float*));
    
    if(!mat){
        printf("Não temos memória suficiente para alocar nossa matriz...\n");
        exit(1);
    }
    
    for(int i=0; i < linhas; i++){
        mat[i] = (float*)malloc(colunas*sizeof(float));

        if(!mat[i]){
            printf("Não temos memória suficiente para alocar nossas linhas...\n");
            exit(1);
        }
    }

    printf("## INICIALIZANDO A MATRZI ##\n");
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++){
            printf("valor [%d][%d]: ", i+1, j+1);
            scanf("%f%*c", &mat[i][j]);
        }
    
    return mat;
}

void matriz_imprime(float** matriz, int linhas, int colunas){
    
    // Imprime a matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
        printf("%7.2f", matriz[i][j]);
        printf("\n");
    }
}


void matriz_deleta(float** matriz, int linhas){

    for(int i = 0; i < linhas; i++)
        free(matriz[i]);
    
    free(matriz);

}