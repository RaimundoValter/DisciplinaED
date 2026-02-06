#include <stdio.h>

void somaprod(int a, int b, int* p, int *q);

int main(){
    int a, b, soma, prod;

    printf("Digite um número: ");
    scanf("%d", &a);
    printf("Digite outro número: ");
    scanf("%d", &b);

    somaprod(a,b,&soma, &prod);
    printf("%d + %d = %d\n%d * %d = %d", a, b, soma, a, b, prod);

    return 0;
}

void somaprod(int a, int b, int* p, int *q){
    *p = a + b;
    *q = a * b;
}