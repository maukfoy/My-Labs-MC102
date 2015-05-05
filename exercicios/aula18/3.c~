#define MAX 10000
#include <stdio.h>

int conta_ocorrencias(char c, char string[], int pos){
    if (string[pos] == '\0')
        return 0;
    return (string[pos] == c) + conta_ocorrencias(c, string, pos + 1);
}

int main(){
    char c, string[MAX];
    
    /* OBS: '*' usado no final da string eh usado para ler textos */
    scanf("%c %[^*]s", &c, string);
    printf("%d\n", conta_ocorrencias(c, string, 0));
    
    return 0;
}
