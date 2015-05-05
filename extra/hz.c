/* Programa que facilita a producao de textos de HZ291
 * 
 * Autor: Rafael Barreto
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_PARAGRAFOS 100
#define MAX_P_LETRAS   1000

#define MAX_TITULOS    20
#define MAX_T_LETRAS   50

FILE *INPUT, *OUTPUT;

int input_titulos (char titulos[][MAX_T_LETRAS]){

    INPUT = fopen("titulos_HZ", "r");

    int n_titulos = 0, j = 0;

    while(!feof(INPUT)){

        while(!feof(INPUT))
            if ((titulos[n_titulos][j++] = fgetc(INPUT)) == '#'){

                titulos[n_titulos][j-1] = '\0';             

                n_titulos++;
                j = 0;
                break;
            }
    }

    fclose(INPUT);

    return n_titulos;
}

int input_paragrafos (char paragrafos[][MAX_P_LETRAS]){

    INPUT = fopen("paragrafos_HZ", "r");

    int n_paragrafos = 0, j = 0;

    while(!feof(INPUT)){

        while(!feof(INPUT))
            if ((paragrafos[n_paragrafos][j++] = fgetc(INPUT)) == '#'){

                paragrafos[n_paragrafos][j-1] = '\0';               

                n_paragrafos++;
                j = 0;
                break;
            }
    }


    fclose(INPUT);

    return n_paragrafos;
}

void output_texto (char titulos[][MAX_T_LETRAS], char paragrafos[][MAX_P_LETRAS], int n_titulos, int
n_paragrafos){

    int i, p, paragrafos_usados[MAX_PARAGRAFOS] = {0};

    OUTPUT = fopen("texto_HZ", "w");

    srand(time(NULL));

    fputs(titulos[rand() % n_titulos], OUTPUT);
    fputc('\n', OUTPUT);
    fputc('\n', OUTPUT);


    for (i = 0; i < 7; i++){

        fputc(' ', OUTPUT);

        do{
            srand(time(NULL));

            p = rand() % n_paragrafos;

        }while (paragrafos_usados[p] != 0);

        fputs(paragrafos[p], OUTPUT);

        paragrafos_usados[p] = 1;

    }

    fclose(OUTPUT);
}


int main(){

    int i, n_paragrafos, n_titulos, paragrafos_usados[MAX_PARAGRAFOS] = {0};

    char paragrafos[MAX_PARAGRAFOS][MAX_P_LETRAS];
    char titulos[MAX_TITULOS][MAX_T_LETRAS];

    system("wget \"https://github.com/rafaelb4rreto/MC102/raw/master/titulos_HZ\"");
    system("wget \"https://github.com/rafaelb4rreto/MC102/raw/master/paragrafos_HZ\"");

    n_titulos    = input_titulos(titulos);
    n_paragrafos = input_paragrafos(paragrafos);

    output_texto (titulos, paragrafos, n_titulos, n_paragrafos);

    return 0;

}