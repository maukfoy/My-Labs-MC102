/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 04a - Deep Web */

#include <stdio.h>

int main () {
    
    /*Declaracao das variaveis a serem utilizadas e os vetores que armazenarao 
os valores da senha e do fator de multiplicacao*/
    
    int n, i, a, soma = 0, novoDig, senha[15], mult[15];
    
    /*Aquisicao dos dados relativos a quantidade de digitos obtidos da senha e 
aos digitos em si. Nesse trecho o programa tambem exibe na tela os valores 
inseridos como parte da senha ja*/
    
    scanf ("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf ("%d", &senha[i]);
        printf("%d", senha[i]);
    }
    
    /*Estabelece o ultimo valor da senha para um valor invalido (20) e itera a 
rotina de contas e multiplicacoes ate que a senha esteja completa, ou seja, ate 
que o ultimo valor seja valido (diferente de 20)*/
    
    senha[14] = 20;    
    while (senha[14] == 20){
        
        /*Calcula os valores atraves da multiplicacao do valor de uma posicao 
pela posicao em si e pela quantidade de digitos conhecidos ate o momento*/
        for (a = 0; a < n; a++){
            mult[a] = ((n) * (a + 1) * (senha[a]));
        }
        
        /*Soma os valores calculados anteriormente e obtem-se o resto da 
divisao da soma por 11, que sera o novo digito. Se o resto for 10, o novo 
digito sera 0.*/
        soma = 0;
        for (a = 0; a < n; a++){
            soma = (soma + mult[a]);
        }
        
        novoDig = (soma % 11);
        
        if (novoDig == 10)
            novoDig = 0;
        
        /*Armazena no vetor "senha" o valor referente a senha encontrada e 
imprime na tela o valor desse digito*/
        
        senha[n] = novoDig;
        printf("%d", senha[n]);
        n++;
    }
    
    /*Imprime na tela uma linha nova no final do arquivo, requisitada pelo 
SuSy*/
    
    printf("\n");
    return 0;
}