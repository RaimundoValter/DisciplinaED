#include <stdio.h>

void imprime(float a);

int main(){

for(int i = 0 ; i < 20; i++)
    imprime((float)i);
}

void imprime(float a){
    static int n = 1;
    printf("%.1f ", a);
    
    if(n % 5 == 0) printf("\n");
    n++;
}