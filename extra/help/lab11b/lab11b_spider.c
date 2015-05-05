/*NOME: Lucas Tarsitani Reis
 * RA: 156414
 * Lab11b - BibTeX */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Article {
    char autor[501];
    char titulo[501];
    char revista[101];
    char ano[51];
    char volume[51];
    char numero[51];
    char paginas[51];
};
typedef struct Article article;

void inicializa(article vet[], int n){
    int i;
    for(i = 0; i < n; i++){
        vet[i].autor[0] = '\0';
        vet[i].titulo[0] = '\0';
        vet[i].revista[0] = '\0';
        vet[i].ano[0] = '\0';
        vet[i].volume[0] = '\0';
        vet[i].numero[0] = '\0';
        vet[i].paginas[0] = '\0';
    }
}

void insertion(article vet[], int indice){
    int j;
    article aux = vet[indice];
    for (j = indice - 1;(j >= 0) && (strcmp(vet[j].titulo, aux.titulo) > 0);
j--)
        vet[j + 1] = vet[j];
    
    vet[j + 1] = aux;
}

void ordenaLexi(article vet[], int n){
    int i;
    for (i = 1; i < n; i++)
        insertion(vet, i);
}

void imprime(article vet[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%s, %s, %s", vet[i].titulo, vet[i].autor, vet[i].revista);
        if(vet[i].volume[0] != '\0')
            printf(", %s", vet[i].volume);
        if(vet[i].numero[0] != '\0')
            printf(", %s", vet[i].numero);
        if(vet[i].paginas[0] != '\0')
            printf(", %s", vet[i].paginas);
        if(vet[i].ano[0] != '\0')
            printf(", %s", vet[i].ano);
        printf(".\n\n");
    }
    
}

int main(){
    int n, i;
    char label[451], campo[8];
    article *artigo;
    
    scanf("%*[%] %d", &n);
    
    artigo = malloc(n * sizeof(article));
    
    inicializa(artigo, n);
    
    for(i = 0; i < n; i++){
        scanf("%*[\n@article{] %[^,]s", label);
        do{
            scanf("%s", campo);
            if(strcmp(campo, "author") == 0){
                scanf("%*[author = {] %[^}]s %*[,]", artigo[i].autor);
            }else if(strcmp(campo, "title") == 0){
                scanf("%*[title = {] %[^}]s %*[,]", artigo[i].titulo);
            }else if(strcmp(campo, "journal") == 0){
                scanf("%*[journal = {] %[^}]s %*[,]", artigo[i].revista);
            }else if(strcmp(campo, "year") == 0)
                scanf("%*[year = {] %[^}]s %*[,]", artigo[i].ano);
            else if(strcmp(campo, "volume") == 0){
                scanf("%*[volume = {] %[^}]s %*[,]", artigo[i].volume);
            }else if(strcmp(campo, "number") == 0){
                scanf("%*[number = {] %[^}]s %*[,]", artigo[i].numero);
            }else if(strcmp(campo, "pages") == 0){
                scanf("%*[pages = {] %[^}]s %*[,]", artigo[i].paginas);}
        }while(strcmp(campo, "}"));
    }
    
    ordenaLexi(artigo, n);
    imprime(artigo, n);
    
    free(artigo);
    
    return 0;
}