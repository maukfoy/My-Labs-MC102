/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 14a - Gerenciador de memoria */

#include <stdio.h>

void alocMemoria(int *Ds, int *Is){
    char caracter;
    
    scanf("%c", &caracter);
    
    if (caracter == 'D')
        *Ds += 1;
    if (caracter == 'I') 
        *Is += 1;
    if (caracter == '#')
        return;
    alocMemoria(Ds, Is);    
}

int main() {
    int Ds = 0, Is = 0;
    
    alocMemoria(&Ds, &Is);
    
    printf("D:%d I:%d", Ds, Is);
   
    if (Ds == 0 && Is == 1)
        printf("Alocacao total");
    
    else if (Is < (2*Ds-1))
        printf("Alocacao parcial");
    
    else if (Is > (2*Ds-1))
        printf("Alocacao invalida");
    
    return 0;
}
