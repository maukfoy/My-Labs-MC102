#include <stdio.h>

int main() {
    int i, x;
    
    for (i = 0; i < 1600000000; i++)
        x += (x == i);
    
    printf ("%s",(x == i) ? ("igual\n") : ("diferente\n"));
    
    return 0;
}
