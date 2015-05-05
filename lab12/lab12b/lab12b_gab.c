/* Laboratorio 12b - Whiteworse
 * Autor: Filipe de Oliveira Costa
 * e-mail: filipe.costa@ic.unicamp.br
 */


#include <stdio.h>
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
/* FLAGS: 1 se uma transacao eh valida; 0 caso contrario */
#define VALIDA 1
#define INVALIDA 0

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

/* Leitura do arquivo binario de contas */
void lerArqContas(char nomearq[], Conta C[], int *nContas) {
    FILE *arq = fopen(nomearq, "rb");
    if (arq  == NULL) { 
        printf("Falha na criacao do arquivo.\n");
        return;
    }

    /* Lendo numero de contas */
    fread(nContas, sizeof(int), 1, arq);
    /* Lendo todas as contas */
    fread(&C[0], sizeof(Conta), *nContas, arq);
    
    fclose(arq);
}

/* Leitura do arquivo binario de transacoes */
void lerArqTrans(char nomearq[], Transacao T[], int *nTrans) {
    FILE *arq = fopen(nomearq, "rb") ;
    if (arq == NULL) { 
        printf("Falha na criacao do arquivo.\n");
        return;
    }
    
    /* Lendo numero de transacoes */
    fread(nTrans, sizeof(int), 1, arq);
    /* Lendo todas as transacoes */
    fread(&T[0], sizeof(Transacao), *nTrans, arq);
    
    fclose(arq);
}

/* Efetua deposito - retorna INVALIDA se a conta nao existe */
int efetuaDeposito(Conta *C, int n, int ag, int cc, double valor) {
    int i = 0;
    while (i < n && ((C[i].ag != ag) || (C[i].cc != cc))) {
        i++;    
    }
    
    /* Se o numero da agencia/conta nao existem */
    if (i == n)
        return INVALIDA;
    
    /* Atualiza valor do saldo */
    C[i].saldo += valor;
    return VALIDA;
}

/* Efetua saque - retorna INVALIDA se a conta nao existe 
 * ou se o saldo e insuficiente para saque
 */
int efetuaSaque(Conta C[], int n, int ag, int cc, double valor) {
    int i = 0;
    while (i < n && ((C[i].ag != ag) || (C[i].cc != cc))) {
        i++;    
    }
    
    /* Se o numero da agencia/conta nao existem */
    if (i == n)
        return INVALIDA;

    /* Se a conta possui saldo negativo */
    if (C[i].saldo <= 0)
        return INVALIDA;
        
    /* Se o saldo para debito eh valido */
    if ((C[i].saldo - valor) < (-100.00))
        return INVALIDA;

    /* Atualiza valor do saldo */
    C[i].saldo -= valor;
    /* Se a conta ficou negativa */
    if (C[i].saldo < 0) {
        /* Subtrair do saldo o valor da taxa */
        C[i].saldo -= TAXA;
    }
    
    return VALIDA;
}

/* Saida padrao */
void escreveTransacao(Transacao T, int nt, int i) {
    /* Escrevendo as transacoes realizadas na saida padrao */
    printf("T%d: ", i);
    printf("%c ", T.tipo);
    printf("%d ", T.ag);
    printf("%d ", T.cc);
    printf("%.2f\n", T.valor);
}

/* Saida em arquivo binario */
void escreveContas(Conta C[], int nc, char nomeArqSaida[]) {
    FILE *f = fopen(nomeArqSaida, "wb");
    /* Escrevendo as contas atualizadas no arquivo binario */
    fwrite(&nc, sizeof(int), 1, f);
    fwrite(&C[0], sizeof(Conta), nc, f);
    fclose(f);
}

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    int nContas = 0, nTrans = 0, i;
    int ehValida;
    Conta C[MAXCONTAS];
    Transacao T[MAXTRANS];
    
    /* Lendo nome dos arquivo binarios */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);   
    strcpy(nomeArqSaida, argv[3]);   

    /* Lendo arquivos binarios */
    lerArqContas(nomeArqConta, C, &nContas);
    lerArqTrans(nomeArqTrans, T, &nTrans);

    /* Tratando todas as transacoes */
    for (i = 0; i < nTrans; i++) {
        if (T[i].tipo == 'D') {
            /* Se a transacao eh um deposito */
            ehValida = efetuaDeposito(C, nContas, T[i].ag, T[i].cc, T[i].valor);
        } else {
            /* Se a transacao eh um saque */ 
            ehValida = efetuaSaque(C, nContas, T[i].ag, T[i].cc, T[i].valor);
        }
        
        /* Se a transacao eh valida */
        if (ehValida) {
            /* Saida padrao*/
            escreveTransacao(T[i], nTrans, i);
        }
    }
    
    /* Saida em arquivo binario */
    escreveContas(C, nContas, nomeArqSaida);
 
    return 0;
}