/* Tarzan */

#include <stdio.h>
#include <math.h>
#define MAX 2000

int main(){
    
    int i, j, x_dist, y_dist, flag_tree = 0;
    double n_tree, lin_dist, max_dist, min_dist;
    int coord[MAX][2];
    
    scanf ("%lf %lf", &n_tree, &max_dist);
    
    for (i = 0; i < n_tree; i++)
        scanf ("%d %d", &coord[i][1], &coord[i][2]);
    
    /* Calcula distancia entre as arvores, para se alguma estiver pelo menos 
     * D + 1 distante de qualquer outra */
    for (i = 0; i < n_tree && flag_tree == 0; i++){
        min_dist = max_dist + 1;
        for (j = 0; j < n_tree && flag_tree == 0; j++){
            if (i != j){
                lin_dist = sqrt(pow((coord[i][1]-coord[j][1]), 2)
                              + pow((coord[i][2]-coord[j][2]), 2));
                if (lin_dist < min_dist)
                    min_dist = lin_dist;
                /*printf("lin_dist = %d  min_dist = %d\n", lin_dist, min_dist);*/
            }
        }
        if (min_dist > max_dist)
                flag_tree = 1;
    }
    /* Ternario FTW */
    (flag_tree == 1) ? (printf("N")) : (printf("S"));
    
    return 0;
}