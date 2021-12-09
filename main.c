#include <stdio.h>
#include <stdlib.h>
//#define BUFSIZE 8192

int main( int argc, char **argv )
{
    int x;
    //FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;
    //fgets( x, BUFSIZE, in );

    scanf("%d",&x);

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
    for (int j=0;j<x;j++)
    {
        for (int k=0;k<x;k++)
        {
            scanf("%lf",&tab[j][k]);
        }
        scanf("%lf",&wynik[j]);
    }
    // ZAMIANA -----------------------------------------

  int pom=x-1;
  double przezco;
  for (int i = 0; i < x-1; i++ ) //powtórzenie zerowania dla kolejnych kolumn
  {
    for (int j=0;j<pom;j++) //zerowanie kolejnych wierszy
    {
      przezco=tab[pom][i]/tab[j][i];
      
      for (int k=0;k<x;k++) // mnożenie wiersza przez wyznaczoną stałą
        {
          tab[j][k]=tab[j][k]*przezco-tab[pom][k]; //POMNOŻYĆ WYNIK!!!
        }

      


    }
  }

    for (int j=0;j<x;j++)
    {
        for (int k=0;k<x;k++)
        {
            printf("%lf ",tab[j][k]);
        }
        printf("%lf \n",wynik[j]);
    }
    return 0;
}
