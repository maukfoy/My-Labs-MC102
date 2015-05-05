/* Exercicios Funcoes~*~* */

#include <stdio.h>

int mmc (int a, int b, int mdc);
int calcula_mdc (int a, int b);

int main() {
    int x, y, mdc;
    scanf ("%d %d", &x, &y);
    mdc = calcula_mdc(x,y);
    printf ("mmc: %d\nmdc: %d\n", mmc(x,y,mdc), mdc);
    return 0;
}

int mmc(int a, int b, int mdc){
    return a*b/mdc;
}

int calcula_mdc(int a, int b){
    return (b ? calcula_mdc(b,a%b) : a);
}