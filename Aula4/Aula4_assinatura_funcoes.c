#include <stdio.h>

float fat(int n);
float arranjo(int n, int k);
float combinacao(int n, int k);

int main(void){

    int n = 0, k = 0;

    // Modificação
    // printf("Digite um numero para calcular o fatorial: ");
    // scanf(" %d", &n);
    // printf("%d! = %d\n", n, fat(n));

    printf("Caso voceh queira saber quantos grupos podes formar para transportar pessoas em um ohnibus.\n");
    printf("Digite o nuhmero de pessoas: ");
    scanf(" %d%*c", &n);
    printf("Digite o nuhmero de cadeiras: ");
    scanf(" %d%*c", &k);
    printf("Podemos arranjah-los de %.0f formas.\n", combinacao(n, k));

    return 0;
}

float fat(int n){
    float fatorial = 1;
    int contador = n;

    while(contador>1){
        fatorial*=((float)contador);
        contador--;
    }

    return fatorial;
}

float arranjo(int n, int k){
    return fat(n)/fat(n-k);
}

float combinacao(int n, int k){
    return arranjo(n,k)/fat(k);
}