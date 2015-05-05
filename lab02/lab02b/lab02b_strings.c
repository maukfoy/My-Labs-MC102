/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 02b - Pedra - Papel - Tesoura - Lagarto - Spock  */

#include <stdio.h>
#include <string.h>

int main() {
    
    /*Declaracao das variaveis e strings a serem utilizadas*/
    
    int i, n, she_op, leo_op, she_pon, leo_pon, produto, flag_res;

    char ganhador[8], perdedor[8], verbo[10], item_she[8], 
item_leo[8];

    /*Inicializacao das variaveis de contagem dos pontos e coleta de dados 
preliminares*/

    she_pon = 0;
    
    leo_pon = 0;
    
    scanf ("%d", &n);
    
    for (i = 0; i < n; i++){                /*Inicio das partidas*/
        
        /*Obtebção de dados sobre a partida e definicao da variavel auxiliar 
"produto"*/
        
        scanf ("%d %d", &she_op, &leo_op);
        
        produto = she_op * leo_op;
        
        /*Teste para empate*/
        
        if (she_op == leo_op){    
            
            printf ("Empate\n");    
        }
        
        else{
            
            /*Teste de todas possíveis condições para Sheldon ganhar o jogo e 
definicao de variaveis de pontuacao e strings de ganhador e perdedor*/
            
            if (((she_op == 1) && ((leo_op == 4) || (leo_op == 3))) || 
                ((she_op == 2) && ((leo_op == 5) || (leo_op == 1))) || 
                ((she_op == 3) && ((leo_op == 2) || (leo_op == 4))) || 
                ((she_op == 4) && ((leo_op == 2) || (leo_op == 5))) || 
                ((she_op == 5) && ((leo_op == 1) || (leo_op == 3)))) { 
                
                strcpy (ganhador,"Sheldon");
                strcpy (perdedor,"Leonard");
                she_pon = she_pon + 1;
                flag_res = 1;
            
            }    
            
            else{
                
                strcpy (ganhador,"Leonard");
                strcpy (perdedor,"Sheldon");
                leo_pon = leo_pon +1;
                flag_res = 0;
                
            }
            
            /*Atribuicao de nomes as opcoes dos jogadores*/
            
            switch (she_op){
                
                case 1:
                    
                    strcpy(item_she,"Pedra");
                    break;
                    
                case 2:
                    
                    strcpy(item_she,"Papel");
                    break;
                    
                case 3:
                    
                    strcpy(item_she,"Tesoura");
                    break;
                    
                case 4:
                    
                    strcpy(item_she,"Lagarto");
                    break;
                    
                case 5:
                    
                    strcpy(item_she,"Spock");
                    break;
                    
            }
            
            switch (leo_op){
                
                case 1:
                    
                    strcpy(item_leo,"Pedra");
                    break;
                    
                case 2:
                    
                    strcpy(item_leo,"Papel");
                    break;
                    
                case 3:
                    
                    strcpy(item_leo,"Tesoura");
                    break;
                    
                case 4:
                    
                    strcpy(item_leo,"Lagarto");
                    break;
                    
                case 5:
                    
                    strcpy(item_leo,"Spock");
                    break;
                    
            }
            
            /*Escolha do verbo a ser usado de acordo com as opcoes 
pre-escolhidas pelos jogadores*/
            
            if (produto == 2)
    
                strcpy (verbo,"embrulha");
            
            else if (produto == 4)
                
                strcpy (verbo,"amassa");
            
            else if ((produto == 3) || (produto == 15))
                
                strcpy (verbo,"quebra");
            
            else if (produto == 5)
                
                strcpy (verbo,"vaporiza");
            
            else if (produto == 6)
                
                strcpy (verbo,"corta");
            
            else if (produto == 8)
                
                strcpy (verbo,"come");
            
            else if (produto == 10)
                
                strcpy (verbo,"refuta");
            
            else if (produto == 12)
                
                strcpy (verbo,"decepa");
            
            else if (produto == 20)
                
                strcpy (verbo,"envenena");
           
            /*Impressao do resultado do jogo*/
            
            if (flag_res == 1)            
            
                printf ("%s: %s %s %s\n", ganhador, item_she, verbo, 
                        item_leo);
            
            else
                
                printf ("%s: %s %s %s\n", ganhador, item_leo, verbo, 
                        item_she);
            
        }
        
    }
    
    /*Impressao da pontuacao final*/
    
    printf ("Sheldon %d x %d Leonard\n", she_pon, leo_pon);
    
    return 0;

}