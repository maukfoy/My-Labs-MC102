#include <stdio.h>

void print_binario(unsigned long int n){
    
    if (n/3)
        print_binario(n/3);
    printf("%lu ", n%3);
}

int main(){

    int i, n, r, pow = 1;
    
    scanf("%d", &n);
    scanf("%d", &r);
    
    for (i = 1; i <= r; i++)
        pow *= n;
    
    for (i = 0; i < pow; i++){
        print_binario(i);
        printf("\n");
    }
    
    
    
    return 0;
    
}