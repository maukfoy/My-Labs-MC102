/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 10b - DON'T PANIC - Part I */

#include <stdio.h>
#define MAX 101

int encontra_breakpoint(int tam_perm, int inicio, int permutacao[]);
void multiplos_breakpoints(int tam_perm, int permutacao[], int *a, int *b);
void transp_prefixo(int tam_perm, int permutacao[], int a, int b);
void imprime_vetor(int tam_vet, int vetor[]);
void troca_valores(int *a, int *b);
int testa_ordenacao(int tam_perm, int permutacao[]);

int main() {
    
    int tam_perm;
    int i, a, b, peso;
    int permutacao[MAX];
    
    scanf ("%d", &tam_perm);
    permutacao[tam_perm + 1] = tam_perm + 1;
    
    for (i = 0; i < tam_perm; i++)
        scanf ("%d", &permutacao[i]);
    
    while (testa_ordenacao(tam_perm, permutacao) == 0){
        imprime_vetor(tam_perm, permutacao);
        a = encontra_breakpoint(tam_perm, 0, permutacao);
        b = encontra_breakpoint(tam_perm, a - 1, permutacao);
        multiplos_breakpoints(tam_perm, permutacao, &a, &b);
        printf ("%d %d\n", a, b);
        transp_prefixo(tam_perm, permutacao, a, b);
        peso += b - 1;
    }
        
    imprime_vetor(tam_perm, permutacao);
    printf ("Peso: %d\n", peso);
    
    return 0;
}

void multiplos_breakpoints(int tam_perm, int permutacao[], int *a, int *b){
    
    int i, j;
    
    for (i = 0; i < tam_perm; i++)
        for (j = i + 1; j < tam_perm; j++)
            if ((permutacao[j] - permutacao[i-1] == 1) 
                && (permutacao[0] - permutacao[j-1] == 1)){
                *a = i + 1;
                *b = j + 1;
                return;
            }
}

int encontra_breakpoint(int tam_perm, int inicio, int permutacao[]){
    
    int i, j;
    
    for (i = inicio; i < tam_perm; i++){
        if (permutacao[i+1] - permutacao[i] != 1)
            if (inicio != 0){
                for (j = i; j < tam_perm; j++)
                    if (permutacao[0] - permutacao[j] == 1 || 
                        permutacao[j+1] - permutacao[inicio - 1] == 1)
                        return j + 2;
                return i + 2;
            }
            else
                return i + 2;
    }
    return -1;
}

void transp_prefixo(int tam_perm, int permutacao[], int a, int b){
    
    int i, j;
    a--;
    b--;
    
    for (i = a-1; i >= 0; i--, b--)
        for (j = i; j < b-1; j++)
            troca_valores(&permutacao[j], &permutacao[j+1]);        
}

void imprime_vetor(int tam_vet, int vetor[]){
    
    int i;
    
    printf("(");
    for (i = 0; i < tam_vet; i++)
        (i + 1 == tam_vet) ? printf("%d)", vetor[i]) : printf("%d ", vetor[i]);
    printf("\n");
}

void troca_valores(int *a, int *b){
    
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux; 
}

int testa_ordenacao(int tam_perm, int permutacao[]){
    
    int i;
    
    for (i = 0; i < tam_perm-1; i++)
        if (permutacao[i+1] - permutacao[i] != 1)
            return 0;
    return 1; 
}

for (i = 1; i <= tam_perm; i++){
        b_breakpoint = acha_bp(tam_perm, permutacao, i);
        for (j = 1; j < b_breakpoint; j++){
            a_breakpoint = acha_bp(tam_perm, permutacao, j);
            if (a_breakpoint != b_breakpoint){
                removidos = bp_removidos(permutacao, a_breakpoint, b_breakpoint);
                if (removidos == 1){
                    *a = a_breakpoint;
                    *b = b_breakpoint;
                }
                else if (removidos == 2){
                    *a = a_breakpoint;
                    *b = b_breakpoint;
                    return;
                }
            }
        }
        if (removidos == 1) return;
    }