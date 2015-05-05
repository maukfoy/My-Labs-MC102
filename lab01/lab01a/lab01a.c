/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 01a - Cálculo de media das notas de avaliacoes */

#include <stdio.h>
#include <math.h>

int main() {
    double p, p1, p2, p3, l;

    /* Fazendo leitura dos dados */
    scanf("%lf %lf %lf %lf", &p1, &p2, &p3, &l);
    
    /* Calculando valor da media ponderada das provas */
    p = (3 * p1 + 3 * p2 + 4 * p3)/10;

    /* Imprimindo resposta */
    printf("Media aritmetica: %.1f\n", (p + l)/2);
    printf("Media harmonica: %.1f\n", (2 * p * l)/(p + l));
    printf("Media geometrica: %.1f\n", sqrt(p * l));

    return 0;
} 
