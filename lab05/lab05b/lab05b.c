/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 05b - Killing the Messenger*/

#include <stdio.h>
#define rMAX 101    /* Define rMAX para o tamanho total do RNA*/
#define oMAX 26     /* Define oMAX para o tamanho total do Oligonucleotido*/

int main() {
    
    /* Declara as variaveis e strings a serem utilizadas*/
    
    int r, o, i, j, iguais, silenciado = 0;
    char rna[rMAX], nuc[oMAX], temp;
   
    /* Le a entrada com os valores das variaveis*/ 
    
    scanf ("%d %d %s %s", &r, &o, rna, nuc);
    
    /* Inverte sequencia do oligonucleotideo*/
    
    for (i = 0; i < (o/2); i++){
        temp = nuc[i];
        nuc[i] = nuc[o-1-i];
        nuc[o-i-1] = temp;
    }
    
    /* Realiza uma busca no RNA a procura de uma base nitrogenada
     * correspondente à primeira base do oligonucleotideo.
      
     * A principio, admite-se que existe uma sequencia no RNA
     * correspondente à do oligonucleotideo.
     
     * Essa busca é interrompida caso tal sequencia seja encontrada. */
    
    for (i = 0; ((i <= (r - o)) && (silenciado == 0)); i++){
        iguais = 1;
        /* Set de condicoes para a correspondencia */
        if (((rna[i] == 'A') && (nuc[0] == 'U')) ||
            ((rna[i] == 'U') && (nuc[0] == 'A')) ||
            ((rna[i] == 'C') && (nuc[0] == 'G')) ||
            ((rna[i] == 'G') && (nuc[0] == 'C'))){
            /* j comeca em 1 pois o teste para a posicao 0 ja foi verificado. */
            for (j = 1; ((j < o) && (iguais == 1)); j++){
                if (((rna[i + j] == 'A') && (nuc[j] == 'U')) ||
                    ((rna[i + j] == 'U') && (nuc[j] == 'A')) ||
                    ((rna[i + j] == 'C') && (nuc[j] == 'G')) ||
                    ((rna[i + j] == 'G') && (nuc[j] == 'C'))){
                    /* Se a ultima base for tambem correspondente ao 
                     * a sequencia toda o eh e a busca eh interrompida */ 
                    if  (j == (o - 1))
                        silenciado = 1;
                }
                else
                    /* Caso alguma base nao corresponda, a analise
                     * anterior eh retomada */
                    iguais = 0;                
            }
        }
    }
    
    /* Sequencias de impressoes do resultado na tela*/
      
    if (silenciado)
        printf ("Silenciado em %d\n", i);
    else
        printf ("Nao silenciado\n");
    
    return 0;
}

/* OBS quanto ao valor de i usado na impressao: Nesse caso, i tem o valor
 * da posicao onde o silenciamento foi obtido pois apesar de ter o
 * encontrado numa posicao anterior do vetor, cuja
 * contagem comeca em 0 e a contagem das posicoes comecar em 1, essa
 * diferenca eh compensada pelo incremento final a i ao terminar sua
 * ultima iteracao no laco que seu valor rege. */
    