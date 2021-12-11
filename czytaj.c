#include <stdio.h>

void czytaj(FILE *in, double **tab, double *wynik, int x){

  for (int j=0;j<x;j++)
    {
        for (int k=0;k<x;k++)
        {
            fscanf(in, "%lf ",&tab[j][k]);

        }
        fscanf(in, "%lf\n",&wynik[j]);
    }
}