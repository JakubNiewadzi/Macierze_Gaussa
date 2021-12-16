#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define BUFSIZE 8192

#include "wypisz.h"
#include "zamiana.h"
#include "czytaj.h"
#include "sprosob.h"

int main( int argc, char **argv )
{
    int  x;
    int error=0;
    
    FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;
    if(fscanf(in, "%d\n", &x)!=1){
      fprintf(stderr, "Ups! Podano błędny format danych!");
      return 1;
    }



    double **tab;
    double *wynik;
    double *zmienne;
    int *zmienione;
    zmienne = malloc( x * sizeof( double ) );
    wynik = malloc( x * sizeof( double  ) );
    tab = malloc( x * sizeof( double * ) );
    zmienione = malloc( x * sizeof( int  ) );

    for (int i = 0; i < x; i++ )
    {
      zmienione[i]=i;
    }
  
    for (int i = 0; i < x; i++ )
    {
        tab[i] = malloc( x * sizeof( double ) );
    }
    czytaj(in, tab, wynik, x, &error);
    if(error==1){
      return 1;
    }
    // ZAMIANA -----------------------------------------

   wypisz(tab, wynik, x);
  

  int pom=x-1;
  double przezco;
  for (int i = 0; i < x-1; i++ )
  {
    zamien(tab, wynik, i, x, zmienione);
    for (int j=0;j<x-1-i;j++) //zerowanie kolejnych wierszy
    {
      double przezco=tab[j][i]/tab[pom-i][i];
      for (int k=i;k<x;k++) // mnożenie wiersza przez wyznaczoną stałą
        {
          tab[j][k]-=(tab[pom-i][k]*przezco);        
          
           //POMNOŻYĆ WYNIK!!!
        }
      wynik[j]-=przezco*wynik[pom-i];
  
    }
    
  }
  

  for (int i = 0; i < x; i++ )
  {
    for (int j=0;j<i;j++)
    {
      wynik[i]-=zmienne[j]*tab[i][x-1-j];
    }
    zmienne[i]=wynik[i]/tab[i][x-i-1];
  }

  if(spr(x, tab)!=0){
    fprintf(stderr, "Ups! Podana macież jest osobliwa i nie mogę rozwiącać równania.");
    return 1;
  }

  printf("Wyniki:\n");
  for (int i = 0; i < x; i++ )
  {
    printf("x%d: %lf\n",zmienione[i]+1, zmienne[i]);
  }
    return 0;
}
