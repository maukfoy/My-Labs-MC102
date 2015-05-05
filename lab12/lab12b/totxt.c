#include <stdio.h>

int main() {

    FILE *bin, *txt;
    int x;
    char string1[100];
    char string2[100];

    scanf ("%s", string1);
    scanf ("%s", string2);

    bin = fopen(string1, "rb");
    remove(string2);
    txt = fopen(string2, "w");

    if ((txt != NULL) && (bin != NULL))
        while (fread(&x, sizeof(int), 1, bin))
            fprintf(txt, "%d\n", x);

    if (bin)
    fclose(bin);
    if (txt)
    fclose(txt);

return 0;
}
