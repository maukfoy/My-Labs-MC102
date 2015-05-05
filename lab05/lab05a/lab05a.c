/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 05a - Caca ao tesouro*/

#include <stdio.h>
#define MAX 100   /*Define MAX para o tamoanho total do vetor*/

int main() {
    
    /*Declaracao das variaveis a serem utilizadas no programa*/
    
    int i, n, flag = 0, aponta = 1, dicas[MAX];
    
    /*Aquisicao das variaves N, numero de dicas, 
     * e de todas as dicas, na ordem crescente de 1 a N*/
    
    scanf ("%d", &n);
    
    for (i = 0; i < n; i++)
        scanf ("%d", &dicas[i]);
    
    /*Loop que ocorrera N vezes ou ateh a flag 
     *que indica que o tesouro foi encontrado ser
     *alterada para um valor diferente de zero,
     * indicando que o tesouro existe e que esta
     * na posicao indicada por "aponta" naquele momento,
     * entao o loop eh interrompido e o resultado impresso
     * na tela*/
    
    for (i = 0; (i < n) && (flag == 0) ; i++){
        aponta = dicas[aponta-1];
        if (aponta == dicas[aponta-1])
            flag = 1;
    }
    
    /*Impressao dos resultados referentes a veracidade
     *das informacoes do mapa*/

    if (flag)
        printf("Tesouro existe em %d\n", aponta);
    else
        printf("Nao existe tesouro\n");
    
    return 0;
}