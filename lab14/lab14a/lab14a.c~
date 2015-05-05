/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 14a - Gerenciador de memoria */

#include <stdio.h>

/* Prototipo da funcao que avalia a validade da alocacao de memoria */
void alocMemoria(int *espacosLivres);

int main() {
    int espacosLivres = 1;
    
    /* Altera a quantidade de espacos livres apos alocar a memoria */
    alocMemoria(&espacosLivres);
    
    /* Imprime o resultado da alocacao solicitada */
    if (espacosLivres == 0)
        printf("Alocacao total\n");
    
    else if (espacosLivres > 0)
        printf("Alocacao parcial\n");
    
    else if (espacosLivres < 0)
        printf("Alocacao invalida\n");
    
    return 0;
}

/* Funcao que avalia se a alocacao eh invalida, total ou parcial */
void alocMemoria(int *espacosLivres){
    char tipoAloc;
    
    /* Obtem o tipo da proxima alocacao, dentre duas possiveis */
    scanf("%c", &tipoAloc);
    
    /* Indica alocacao invalida se nao houverem espacos livres alocaveis */
    if (*espacosLivres == 0 && (tipoAloc == 'I' || tipoAloc == 'D')){
        *espacosLivres = -1;
        return;
    }
    
    /* Altera a quantidade de espacos livres e chama a funcao recursivamente */
    switch (tipoAloc){
    /* Aloca o espaco inteiro, i.e. decrementa em um os espacos livres */
        case 'I':
            (*espacosLivres)--;
            alocMemoria(espacosLivres);
            break;
    /* Cria divide um espacos em tres e aloca um deles,
     * i.e. incrementa em um os espacos livres */
        case 'D':
            (*espacosLivres)++;
            alocMemoria(espacosLivres);
            break;
    }
    return;
}