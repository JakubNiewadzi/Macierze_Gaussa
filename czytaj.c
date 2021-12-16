#include <stdio.h>

void czytaj(FILE *in, double **tab, double *wynik, int x, int *error){
  int k;
  for (int j=0;j<x;j++)
  {
    k=0;
    
      while(fscanf(in, "%lf ",&tab[j][k])==1.0)
      {
        //printf("to jest k: %d\n", k);
        if(k==x-1){
          break;
        }
        k++;
      }
      if(k!=x-1){
        fprintf(stderr, "Ups! Podano błędny format danych!");
        *error=1;
        break;
      }
        fscanf(in, "%lf\n",&wynik[j]);
    }
  }



/*for (int k=0;k<x;k++)
        {
            if(fscanf(in, "%lf ",&tab[j][k]))
            {}
            else
            {
              printf("Proszę wprowadzić liczbę typu double na wejscie");
              
            }

        }*/