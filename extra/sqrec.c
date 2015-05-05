/* Recursao  */

#include <stdio.h>
#include <time.h>

unsigned long int quadrado(a){
    
    if (a == 1)
        return 1;
    else
        return (a + a - 1) + quadrado(a-1);
}

int main() {
    
    unsigned long int a; 
   
    scanf("%lu", &a);
    printf("%lu\n", quadrado(a));

    return 0;
}
