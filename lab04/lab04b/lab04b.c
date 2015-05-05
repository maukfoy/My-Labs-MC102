/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 04b - Semanada */

#include <stdio.h>
#define MAX 100

int main() {
    
    int i, d, r, impressos = 0, maior = 0, marcador = 0, 
entrada[MAX];
    
    scanf ("%d %d", &d, &r);
    for (i = 0; i < d; i++){
        scanf ("%d", &entrada[i]);
    }
    
    printf ("Maior valor: ");
    
    do{
    for (i = marcador; i > d ; i++){
            if (entrada[i] > maior){
                maior = entrada[i];
                marcador = i;
            }
        }
        impressos++;
        printf ("%d", maior);
        marcador++;
        maior = 0;
        r--;
        
    }while (r >= 0);
    printf("\n")

    return 0;
}