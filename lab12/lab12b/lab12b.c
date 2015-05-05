/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 12b - Whiteworse */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho maximo do nome do titular */
#define MAXNOME 21
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de contas */
#define MAXCONTAS 20
/* Numero maximo de transacoes */
#define MAXTRANS 40
/* Valor da taxa de deposito em conta com saldo negativo */
#define TAXA 5.00

/* Conta
 * ag = numero da agencia
 * cc = numero da conta corrente
 * titular = Nome do titular da conta
 * saldo = Saldo da conta
 */
struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

/* Transacao
 * tipo - 'D' para Depositos e 'S' para Saques
 * ag - Numero da agencia
 * cc - Numero da conta corrente
 * valor - Valor da operacao
 */
struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

/* Faz uma busca e retorna o indice da conta procurada ou retorna -1 se ela nao existe */
int indiceConta(int agencia, int conta, int nContas, Conta contas[]);

int main(int argc, char **argv) {

    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];

    /* Nome dos ponteiros para arquivos */
    FILE *fContas, *fTrans;
    FILE *fSaida;

    /* Variaveis auxiliares */
    int i, iConta;
    int nContas, nTrans;

    /* Vetores de registros Conta e Transacao */
    Conta *contas;
    Transacao *transacoes;

    /* Obtendo o nome dos arquivos */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);

    /* Abrindo os arquivos binarios de entrada e saida */
    fContas = fopen(nomeArqConta, "rb");
    fTrans = fopen(nomeArqTrans, "rb");
    remove(nomeArqSaida);
    fSaida = fopen(nomeArqSaida, "wb");

    /* Lendo a quantidade de contas e transacoes a serem feitas */
    fread(&nContas, sizeof(int), 1, fContas);
    fread(&nTrans, sizeof(int), 1, fTrans);

    /* Alocando memoria para armazenar as contas e transacoes */
    contas = malloc(nContas * sizeof(Conta));
    transacoes = malloc(nTrans * sizeof(Transacao));

    /* Lendo os dados das contas e transacoes dos arquivos binarios */
    fread(&contas[0], sizeof(Conta), nContas, fContas);
    fread(&transacoes[0], sizeof(Transacao), nTrans, fTrans);

    /* Calculando o saldo das contas apos aplicadas as transacoes validas e imprimindo-as */
    for (i = 0; i < nTrans; i++){
        /* Verifica se a conta existe */
        iConta = indiceConta(transacoes[i].ag, transacoes[i].cc, nContas, contas);
        /* Realiza as operacoes de deposito */
        if (transacoes[i].tipo == 'D' && iConta != -1){
            contas[iConta].saldo += transacoes[i].valor;
            /* Imprime a transacao realizada */
            printf("T%d: %c %d %d %.2f\n", i, transacoes[i].tipo,
                    transacoes[i].ag, transacoes[i].cc, transacoes[i].valor);
        }
        /* Realiza as operacoes de saque */
        else if (transacoes[i].tipo == 'S' && iConta != -1 && contas[iConta].saldo > 0){
            if (contas[iConta].saldo - transacoes[i].valor >= -100.0){
                contas[iConta].saldo -= transacoes[i].valor;
                /* Aplica a taxa de abertura de credito se necessario */
                if (contas[iConta].saldo < 0)
                    contas[iConta].saldo -= 5;
                /* Imprime a transacao realizada */
                printf("T%d: %c %d %d %.2f\n", i, transacoes[i].tipo,
                        transacoes[i].ag, transacoes[i].cc, transacoes[i].valor);
            }
        }
    }

    /* Escrevendo num arquivo binario as contas apos modificadas */
    fwrite(&nContas, sizeof(int), 1, fSaida);
    fwrite(&contas[0], sizeof(Conta), nContas, fSaida);

    /* Libera para uso os arquivos abertos pelo programa e da memoria alocada */
    free(contas);
    free(transacoes);
    fclose(fContas);
    fclose(fTrans);
    fclose(fSaida);

    return 0;
}

/* Faz uma busca e retorna o indice da conta procurada ou retorna -1 se ela nao existe */
int indiceConta(int agencia, int conta, int nContas, Conta contas[]){

    int i;

    /* Caso a conta seja achada, esse laco eh interrompido */
    for (i = 0; i < nContas; i++)
        if (agencia == contas[i].ag)
            if (conta == contas[i].cc)
                return i;
    return -1;
}
