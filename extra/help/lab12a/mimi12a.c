/***********************************************************
 * Autor: Miguel Henrique Nicodemus de Souza Pinto
 * RA: 156777
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101

struct vetor_string {
    char conteudo[501];
};    

typedef struct vetor_string vetor_string;

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]); 

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

void gera_csv_reduzido(char fnamein[], char fnameout[]) 
{
    FILE *arq_in;
    FILE *arq_out;
    char varre;       
    int numero_de_impressoes;
    int i = 0, j = 0, k= 0;
    int contador_virgulas = 0;
    int *vetor_entradas;
    int numero_de_linhas = 0;
    vetor_string *conteudo_dos_campos;

    /* Abre os arquivos de entrada e saida */
    arq_in = fopen(fnamein, "r");
    arq_out = fopen(fnameout, "w");
    
    /* Le o numero de colunas desejadas para a impressao */
    scanf("%d", &numero_de_impressoes);
    
    /* Esse bloco recebe o numero de virgulas da primeira linha, e depois usando
     * esse numero, calcula o numero de campos existentes no texto de entrada */
     while (varre != '\n')
     { 
        fscanf(arq_in ,"%c", &varre);
        if (varre == ',')
        {
            contador_virgulas++;
        }
     }
     
    rewind(arq_in);
    
    while (!feof(arq_in))
     { 
        fscanf(arq_in ,"%c", &varre);
        if (varre == '\n')
        {
            numero_de_linhas++;
        }
     }
     numero_de_linhas--;
     rewind(arq_in);
    
    /* Devemos fazer nesse caso 2 alocacoes de memoria para armazenar dados:
     * 1) Um vetor para guardar as entradas, já que a impressao sera feita
     * linha por linha
     * 2) Um vetor para armazenar o conteudo do campo nas diferentes linhas */
    vetor_entradas = malloc(numero_de_impressoes * sizeof (int));
    conteudo_dos_campos = malloc(contador_virgulas * sizeof(vetor_string));
     
    
    /* Armazena as entradas */
    for (i = 0; i < numero_de_impressoes; i++)
    {
        scanf("%d", &vetor_entradas[i]);
    }
    
        
     for (k = 0; k < numero_de_linhas; k++)   
     {   
        /* Armazena o conteudo de cada campo */
        for (i = 0; i <= contador_virgulas; i++)
        {    
            
            j = 0;
            do
            {
                fscanf(arq_in, "%c", &varre);
                conteudo_dos_campos[i].conteudo[j] = varre;
                j++;
            } while (varre != ',' && varre != '\n');
            
            conteudo_dos_campos[i].conteudo[j-1] = '\0';
        }            
        /* Escreve no arquivo de saida o conteudo de cada campo armazenado no 
         * bloco anterior */
        for (i = 0; i < numero_de_impressoes; i++)
        {
            fprintf(arq_out, "%s", conteudo_dos_campos[vetor_entradas[i] - 1].conteudo);
            if (i < numero_de_impressoes-1)
                fprintf(arq_out, ","); 
        }
        fprintf(arq_out, "\n");
        
    }
    fclose(arq_in);
    fclose(arq_out);
}
