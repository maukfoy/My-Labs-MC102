/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 02a - INSS e IRPF  */

#include <stdio.h>

int main() {
    
    /*Declaracao de variaveis*/
    
    int d, caso;
    double s, inss, base, irpf, temp;
    
    /*Leitura dos dados*/
    
    scanf ("%lf %d", &s, &d);
    
    /*Calculo da taxa do INSS*/
    
    irpf = 0;
    
    if (s <= 1317.07) {
        
        inss = (0.08 * s);
        
    } else if (s <= 2195.12) {
        
        inss = (0.09 * s);
        
    } else if (s <=4390.24) {
        
        inss = (0.11 * s);
        
    } else{
        
        inss = 482.93;
   
    }
    
    /*Calculo do valor base de calculo do Imposto de Renda (IRPF)*/
   
    base = (s - inss - (179.71 * d));
    
    /*Calculo do IRPF - Separação dos casos por faixa salarial*/
    
    if (base >= 4463.82){
        
        caso = 5;
        
    } else if (base >= 3572.44){
        
        caso = 4;
        
    } else if (base >= 2679.30){
        
        caso = 3;
        
    } else if (base >= 1787.78){
        
        caso = 2;
        
    } else{
        
        caso = 1;
        
    }
    
    
    temp = base;
    
    /*Calculo efetivo do valor da contribuicao (IRPF)*/
    
    switch (caso){
        
        case 5:
            
            irpf = (irpf + ((temp - 4463.81)*0.275));
            temp = (temp - (temp - 4463.81));
            
            
        case 4:
            
            irpf = (irpf + ((temp - 3572.44)*0.225));
            temp = (temp - (temp - 3572.44));
            
            
        case 3:
            
            irpf = (irpf + ((temp - 2679.30)*0.15));
            temp = (temp - (temp - 2679.30));
            
            
        case 2:
            
            irpf = (irpf + ((temp - 1787.78)*0.075));
            
        case 1:
            
            /*Impressao dos dados requeridos na tela*/
            
            printf("INSS: R$ %.2f\n", inss);
            printf("Base: R$ %.2f\n", base);
            printf("IRPF: R$ %.2f\n", irpf);
      
    }
    
    /* Fim do programa*/
    
    return 0;
}














