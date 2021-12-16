#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define BUFSIZE 8192

#include "wypisz.h"
#include "zamiana.h"
#include "czytaj.h"

int main( int argc, char **argv )
{
    int  x;
    FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;
    fscanf(in, "%d\n", &x);

    //scanf("%d",&x);

    double **tab;
    double *wynik;
    double *zmienne;
    zmienne = malloc( x * sizeof( double ) );
    wynik = malloc( x * sizeof( double  ) );
    tab = malloc( x * sizeof( double * ) );
  
    for (int i = 0; i < x; i++ )
    {
        tab[i] = malloc( x * sizeof( double ) );
    }
    czytaj(in, tab, wynik, x);

    // ZAMIANA -----------------------------------------

   wypisz(tab, wynik, x);
  

  int pom=x-1;
  double przezco;
  for (int i = 0; i < x-1; i++ )
  {
    zamien(tab, wynik, i, x);
    for (int j=0;j<x-1-i;j++) //zerowanie kolejnych wierszy
    {
      double przezco=tab[j][i]/tab[pom-i][i];
      for (int k=i;k<x;k++) // mnożenie wiersza przez wyznaczoną stałą
        {
          tab[j][k]-=(tab[pom-i][k]*przezco);        
          wypisz(tab, wynik, x); 
           //POMNOŻYĆ WYNIK!!!
        }
      wynik[j]-=przezco*wynik[pom-i];
  
    }
    wypisz(tab, wynik, x);
  }

  for (int i = 0; i < x; i++ )
  {
    for (int j=0;j<i;j++)
    {
      wynik[i]-=zmienne[j]*tab[i][x-1-j];
    }
    zmienne[i]=wynik[i]/tab[i][x-i-1];
  }
  
  printf("Wyniki:\n");
  for (int i = 0; i < x; i++ )
  {
    printf("%lf\n",zmienne[i]);
  }
    return 0;
}
