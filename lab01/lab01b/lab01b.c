/* Nome: Mauricio Lorenzetti Bezerra
 * RA: 156754
 * Laboratorio 01b - Notas do vestibular */

#include <stdio.h>

int main() {
    int a, nmo;
    double pcg, pin, ppo, pma, pch, pcn, ncg, mcg, dpcg;
    double npcg, npin, nppo, npma, npch, npcn, nf;
    double nin, min, dpin, npo, mpo, dppo, nma, mma, dpma, nch, mch, dpch, 
ncn, mcn, dpcn;

    scanf("%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf", &a, &nmo, &pcg, &pin, 
&ppo, &pma, &pch, &pcn, &ncg, &mcg, &dpcg);
    
    npcg = (((ncg - mcg) * 100)/dpcg)+500;
    
    printf("Primeira Fase: %.1f\n", npcg);
    
    if (npcg >= 550){
        
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
        &nin, &min, &dpin, &npo, &mpo, &dppo, &nma, &mma, &dpma, &nch, &mch, 
        &dpch, &ncn, &mcn, &dpcn);
        
        npin = (((nin - min) * 100)/dpin)+500;
        
        nppo = (((npo - mpo) * 100)/dppo)+500;
        
        npma = (((nma - mma) * 100)/dpma)+500;
        
        npch = (((nch - mch) * 100)/dpch)+500;
        
        npcn = (((ncn - mcn) * 100)/dpcn)+500;
        
        nf = (npcg*pcg +  npin*pin + npma*pma + nppo*ppo + npch*pch + 
npcn*pcn)/(pcg + pin + ppo + pma + pch + pcn);

        printf("Segunda Fase: %.1f\n", nf);

        switch (a){
            
            case 1:
                if ((npma < nmo) || (npcn < nmo))
                    printf("Grupo 2\n");
                else
                    printf("Grupo 1\n");
                break;
            case 2:
                if ((nppo < nmo) || (npch < nmo))
                    printf("Grupo 2\n");
                else
                    printf("Grupo 1\n");
                break;
            case 3:
                if (npcn < nmo)
                    printf("Grupo 2\n");
                else
                    printf("Grupo 1\n");
                break;
        }
        
    }
    return 0;
}