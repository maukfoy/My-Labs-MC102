/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 02b - Pedra - Papel - Tesoura - Lagarto - Spock  */

#include <stdio.h>

int main() {
    
    /*Declaracao das variaveis e inicializacao dos valores a serem utilizados*/
    
    int i, n, she_op, leo_op, she_pon = 0, leo_pon = 0, produto;

    /*Coleta de dados preliminares*/
    
    scanf ("%d", &n);
    
    /*Estrutura a ser repetida n vezes, sendo n a quantidade de partidas que 
ocorrerão*/
    
    for (i = 0; i < n; i++){                /*Inicio das partidas*/
        
        /*Obtebção de dados sobre a partida e definicao da variavel auxiliar*/
        
        scanf ("%d %d", &she_op, &leo_op);
        
        produto = she_op * leo_op;
        
        /*Teste para empate*/
        
        if (she_op == leo_op){    
            
            printf ("Empate\n");    
        }
        
        else{
            
            /*Teste de todas possíveis condições para Sheldon ganhar o jogo uma 
vez que nao houve empate e definicao de variaveis de pontuacao, caso Sheldon 
não ganhe, Leonard com certeza ganhara. Definido o ganhador, seu nome e 
impresso e sua pontuacao incrementada*/
            
            if (((she_op == 1) && ((leo_op == 4) || (leo_op == 3))) || 
                ((she_op == 2) && ((leo_op == 5) || (leo_op == 1))) || 
                ((she_op == 3) && ((leo_op == 2) || (leo_op == 4))) || 
                ((she_op == 4) && ((leo_op == 2) || (leo_op == 5))) || 
                ((she_op == 5) && ((leo_op == 1) || (leo_op == 3)))) { 
                
                printf ("Sheldon: ");
                she_pon++;
            
            }    
            
            else{
                
                printf ("Leonard: ");
                leo_pon++;
                
            }
            
            /*Impressao do texto a ser usado pelo ganhador de acordo com as 
opcoes pre-escolhidas por ele e por seu oponente*/
            
            if (produto == 2)
    
                printf ("Papel embrulha Pedra\n");
            
            else if (produto == 4)
                
                printf ("Pedra amassa Lagarto\n");
            
            else if (produto == 3)
                
                printf ("Pedra quebra Tesoura\n");
            
            else if (produto == 5)
                
                printf ("Spock vaporiza Pedra\n");
            
            else if (produto == 6)
                
                printf ("Tesoura corta Papel\n");
            
            else if (produto == 8)
                
                printf ("Lagarto come Papel\n");
            
            else if (produto == 10)
                
                printf ("Papel refuta Spock\n");
            
            else if (produto == 12)
                
                printf ("Tesoura decepa Lagarto\n");
            
            else if (produto == 15)
                
                printf ("Spock quebra Tesoura\n");
            
            else if (produto == 20)
                
                printf ("Lagarto envenena Spock\n");
                   
        }
        
    }
    
    /*Impressao da pontuacao final*/
    
    printf ("Sheldon %d x %d Leonard\n", she_pon, leo_pon);
    
    return 0;

}