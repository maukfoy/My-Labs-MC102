/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 03b - Fringe */

#include <stdio.h>

int main () {
       
    /* Declaracao das variaveis a serem utilizadas, sendo todas do tipo int*/
    
    int m, s, atual, anterior, cont_a = 0, cont_b = 0, fase = 0, flag = 0, mols;
    
    /* Entrada dos dados de controle (numero de mols e fator S) e primeiro 
valor de leitura dos sensores*/
    
    scanf ("%d %d", &m, &s);
    scanf ("%d", &atual);
    
    /* Descarte da primeira fase lida por nao ser esta com certeza completa */
    
    anterior = atual;
    while (anterior == atual){
        scanf("%d", &atual);
    }
    
    /* Inicio da leitura efetiva dos dados a partir do inicio da primeira fase 
detectado apos o inicio da leitura dos dados dos sensores */
    
    anterior = atual;    
    while (atual != -1){ /* Condicao para final da leitura dos sensores */
        while (anterior == atual){ /* Contagem do tamanho das fases */
            switch (flag){  
                case 0:
                    cont_a++;
                    break;
                case 1:
                    cont_b++;
            }
            scanf("%d", &atual);
        }
        
        /* Complemento de flag, usada para indicar em 
         que fase a leitura esta acontecendo (igual a inicial ou contraria */
        
        flag = ((flag + 1) % 2);
        anterior = atual;
        
        /* Contagem de fases, caso elas tenham o mesmo tamanho, em outro caso 
um dos contadores (o mais "antigo") e zerado e a contagem reiniciada */
        
        if ((cont_a == cont_b) && (atual != -1)){
            if (fase == 0){
                fase = 2;
            }
            else{
                fase++;
            }
            switch (flag){
                case 0:
                    cont_a = 0;
                    break;
                case 1:
                    cont_b = 0;
                    break;
            }
        }
        else if ((cont_a != cont_b) && (atual != -1)){
            fase = 0;
            switch (flag){
                case 0:
                    cont_a = 0;
                    break;
                case 1:
                    cont_b = 0;
                    break;
            }
        }
    }
    
    /* Determinacao da quantidade de mols que podera ser transportada por fase 
e finalizacao do programa, mostrando o valor caso o portal tenha sido aberto 
ou dizendo que o portal nao abriu caso isso tenha ocorrido */
           
    if (fase >= s){
        if (cont_a > cont_b){
            mols = m * cont_a;
        }
        else{
            mols = m * cont_b;
        }
        printf ("%d mols\n", mols);
    }
    else
        printf ("Portal nao abriu\n");    
    return 0;   
}