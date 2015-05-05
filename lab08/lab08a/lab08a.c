/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 08a - Amigos dos amigos */

#include <stdio.h>
#define MAX 100

int main() {
    
    int i, a_usuario, am_amigo, flag_sug = 0;
    int n_usuarios, usuario;
    int sugestao[MAX], amigos[MAX][MAX];
    
    scanf ("%d %d", &n_usuarios, &usuario);
    
    for (i = 0; i < n_usuarios; i++){
        sugestao[i] = 0;
        for (a_usuario = 0; a_usuario < n_usuarios; a_usuario++)
            scanf("%d", &amigos[i][a_usuario]);
    }
        
    for (a_usuario = 0; a_usuario < n_usuarios; a_usuario++)
        if ((amigos[usuario][a_usuario]) && (a_usuario != usuario))
            for (am_amigo = 0; am_amigo < n_usuarios; am_amigo++)
                if (amigos[a_usuario][am_amigo] && !amigos[usuario][am_amigo]){
                    flag_sug = 1;
                    sugestao[am_amigo] = 1;
                }
                
    if (flag_sug){
        printf ("Sugestao de amigos:");
        for (i = 0; i < n_usuarios; i++)
            if (sugestao[i])
                printf(" %d", i);
    }
    else
        printf("Sem sugestao de novos amigos");
    
    printf("\n");
    
    return 0;
}