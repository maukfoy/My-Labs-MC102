
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Artigo {
    char label[451];
    char author[501];
    char title[501];
    char journal[101];
    char year[51];
    char volume[51];
    char number[51];
    char pages[51];
};
typedef struct Artigo Artigo;

void le_artigo(Artigo artigo);

int main() {
    int n, i;
    char c;
    Artigo *artigos;
    c = getchar();
    scanf(" %d", &n);
    artigos = malloc(n * sizeof(Artigo));
    /* "zera" o vetor */
    for(i = 0; i < n; i++) {
        artigos[i].author[0] = '\0';
        artigos[i].journal[0] = '\0';
        artigos[i].label[0] = '\0';
        artigos[i].number[0] = '\0';
        artigos[i].pages[0] = '\0';
        artigos[i].title[0] = '\0';
        artigos[i].volume[0] = '\0';
        artigos[i].year[0] = '\0';
    }
    for(i = 0; i < n; i++) {
        le_artigo(artigos[i]);
    }

    /* Onde farei a ordenacao */
    /* Printando so pra ve msm como que tah */
    for(i = 0; i < n; i++) {
        printf("%s\n", artigos[i].author);
        printf("%s\n", artigos[i].journal);
        printf("%s\n", artigos[i].label);
        printf("%s\n", artigos[i].number);
        printf("%s\n", artigos[i].pages);
        printf("%s\n", artigos[i].title);
        printf("%s\n", artigos[i].volume);
        printf("%s\n", artigos[i].year);
    }
    /* Desalocando memoria */
    free(artigos);
    return 0;
}

void le_artigo(Artigo artigo) {
    int i = 0;
    char c, caracter_inicial, c2;
    char campo[10];
    /* Elimina caracteres antes do label */
        while (c != '{') {
            c = getchar();
        }
        scanf("%s", artigo.label);
        artigo.label[(strlen(artigo.label)-1)] = '\0';
         /* Comeca a ler os campos */
         /*Esse scanf faz com que o carcater inicial pegue ' ' ou '}'*/
         scanf("%c", &caracter_inicial);
         while(caracter_inicial != '}') {
            /* Pega o primeiro espaco */
            getchar();
            /* Le o campo(title, author) e no fim c2 fica com */
            while(c2 != ' ') {
                scanf("%c", &c2);
                campo[i] = c2;
                i++;
            }
            campo[i] = '\0';
            /*pega o '='*/
            c2 = getchar();
            /* pega o ' ' */
            c2 = getchar();
            /* pega a '{' */
            c2 = getchar();
            /* Depois preciso eliminar a virgula e a } */
            /* Verifica para qual campo deve ser adicionado o valor */
            if( strcmp(campo, "author") == 0) {
                scanf("%s", artigo.author);
                artigo.author[(strlen(artigo.author)-2)] = '\0';
            }
            else if( strcmp(campo, "title") == 0 ) {
                scanf("%s", artigo.title);
                artigo.title[(strlen(artigo.title)-2)] = '\0';
            }
                else if( strcmp(campo, "journal") == 0) {
                    scanf("%s", artigo.journal);
                    artigo.journal[(strlen(artigo.journal)-2)] = '\0';
                }
                    else if( strcmp(campo, "year") == 0) {
                        scanf("%s", artigo.year);
                        artigo.year[(strlen(artigo.year)-2)] = '\0';
                    }
                        else if( strcmp(campo, "volume") == 0) {
                            scanf("%s", artigo.volume);
                            artigo.volume[(strlen(artigo.volume)-2)] = '\0';
                        }
                            else if( strcmp(campo, "number") == 0) {
                                scanf("%s", artigo.number);
                            }
                                else if( strcmp(campo, "pages") == 0) {
                                    scanf("%s", artigo.pages);
                                    artigo.pages[(strlen(artigo.pages)-2)] = '\0';
                                }
             scanf("%c", caracter_inicial);
         }
}
