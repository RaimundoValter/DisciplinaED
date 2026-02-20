#include <stdlib.h>
#include <stdio.h>
#define N 10

int main(){

    int n = N;
    printf("Diga qual o tamanho do vetor: ");
    scanf("%d%*c", &n);

    int* vetor = (int*)malloc(n*sizeof(int));

    if(!vetor)
        {
            printf("Não temos memória suficiente para alocar...\n");
            exit(1);
        }

    for(int i = 0; i < n; i++)
        vetor[i]=i*i+1;

    printf("## Imprimindo o vetor: ##\n");

    for(int i = 0; i < n; i++) 
        printf("%i ", vetor[i]);

    free(vetor);

    return 1;
}