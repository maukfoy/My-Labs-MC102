/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 15a - Mineracao de Bitcoin */

#include <stdio.h>
/* Numero de digitos do codigo de verificacao */
#define NDIG 9
/* Numero de espacos para posicionar operadores entre os digitos */
#define NOPE 8
/* Numero de operadores possiveis entre os digitos (+, - e concatenacao)*/ 
#define OPER 3

/* Funcao que testa se a disposicao de operadores fornecida tem como
 * resultado o numero de seguranca, possui retorno de efeito booleano */
int testaCodigo(int codigo[], int operadores[], int numSeg){
    
    /* Inicializacao das variaveis:
     * 'soma' em 0;
     * 'aux' armazenando o proximo termo da operacao;
     * 'sinal' tem 3 possibilidades:
     * +1 = soma
     * -1 = subtracao
     *  0 = concatenacao do proximo digito 
     * eh inicializado em '+1' pois o primeiro numero eh sempre positivo */
    int i, aux = codigo[0], sinal = 1, soma = 0;
    
    for (i = 0; i < NOPE; i++){
        if (operadores[i] == 0)
    /* Realiza a concatenacao dos digitos */
            aux = (10 * aux) + codigo[i+1];
        else {
    /* Realiza a operacao indicada e prepara para a proxima */
            soma += (sinal * aux);
            aux = codigo[i+1];
            sinal = operadores[i];
        }
    }
    /* Realiza a ultima operacao nos digitos do codigo */
    soma += (sinal * aux);
    
    /* Retorna '1' se as operacoes resultaram no numero de seguranca
     * e '0' caso contrario */
    if (soma == numSeg)
        return 1;
    return 0;
}

/* Funcao que gera todos possiveis arranjos de operadores para verificacao,
 * Retorna '1' o arranjo gerado for valido '0' se nenhum deles for */
int geraArranjo(int operadores[], int codigo[], int numSeg, int indice){
    
    int i;
    
    if (indice == NOPE){
    /* Testa os operadores sempre que um arranjo for encontrado */
        return testaCodigo(codigo, operadores, numSeg);
    }
    else {
    /* Encontra os arranjos possiveis recursivamente */
        for (i = -1; i <= 1; i++){
            operadores[indice] = i;
    /* Retorna '1' assim que UM arranjo for valido para verificacao */
            if (geraArranjo(operadores, codigo, numSeg, indice + 1))
                return 1;
        }
    }
    /* Retorna '0' se nao foi possivel encontrar um arranjo valido */
    return 0;
}

/* Le os codigo de verificacao e numero de seguranca fornecidos */
void leDados(int *numSeg, int codigo[]){
    
    int i;
    char temp[NDIG];
    
    /* Le e converte o codigo de verificacao num vetor de inteiros, cada 
     * posicao contendo um digito do codigo */
    for (i = 0; i < NDIG; i++){
        scanf("%c", &temp[i]);
        codigo[i] = temp[i] - '0';
    }
    /* Le o numero de seguranca */
    scanf("%d", numSeg);
    
}

int main() {
    
    /* Declaracao das variaveis e vetores utilizados */
    int codigo[NDIG], operadores[NOPE], numSeg;
    
    /* Le os dados da entrada */
    leDados(&numSeg, codigo);
    
    /* Testa os valores e imprime se a transferencia foi aceita ou abortada */
    if (geraArranjo(operadores, codigo, numSeg, 0))
        printf("Transferencia aceita\n");
    else
        printf("Transferencia abortada\n");
    
    return 0;
}
