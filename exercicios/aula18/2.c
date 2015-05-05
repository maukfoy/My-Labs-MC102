#include <stdio.h>

void print_binario(unsigned long int n){
    short int resto = n%2;
    unsigned long int div = n/2;
    if (div)
        print_binario(div);
    printf("%d", resto);
}

void print_binario(unsigned long int n){
    if (n/2)
        print_binario(n/2);
    printf("%lu", n%2);
}

int main(){
    unsigned long int n;

    scanf("%lu", &n);
    print_binario(n);
    printf("\n");

    return 0;
}
