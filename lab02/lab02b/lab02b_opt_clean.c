/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 02b - Pedra - Papel - Tesoura - Lagarto - Spock  */
#include <stdio.h>
int main() {    
    int i, n, she_op, leo_op, she_pon, leo_pon, produto;
    she_pon = 0;
    leo_pon = 0;
    scanf ("%d", &n);
    for (i = 0; i < n; i++){        
        scanf ("%d %d", &she_op, &leo_op);        
        produto = she_op * leo_op;       
        if (she_op == leo_op)            
            printf ("Empate\n");
        else{            
            if (((she_op == 1) && ((leo_op == 4) || (leo_op == 3))) || 
                ((she_op == 2) && ((leo_op == 5) || (leo_op == 1))) || 
                ((she_op == 3) && ((leo_op == 2) || (leo_op == 4))) || 
                ((she_op == 4) && ((leo_op == 2) || (leo_op == 5))) || 
                ((she_op == 5) && ((leo_op == 1) || (leo_op == 3)))) { 
                printf ("Sheldon: ");
                she_pon = she_pon + 1;   
            }else{
                printf ("Leonard: ");
                leo_pon = leo_pon +1;
            }if (produto == 2)
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
                printf ("Lagarto envenena Spock\n");}}
    printf ("Sheldon %d x %d Leonard\n", she_pon, leo_pon);    
    return 0;}