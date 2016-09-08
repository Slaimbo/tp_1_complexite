#include <iostream>
#include <stdlib.h>


int main(int argc, char ** argv)
{
  int * tab, n = argc - 1;
  tab = new int[n];

  for( int i = 0; i < n; i++)
    tab[i] = atoi(argv[i+1]);
 
  int i = 0, j = 0, k = 0, imax = 0;
  int jmax = 0, somme_max = tab[0], somme;
  for(i = 0; i < n; i++)
    {
      for(j = i; j < n; j++)
	{
	  somme = 0;
	  for(k = i; k <= j; k++)
	    somme += tab[k];
	  if( somme >= somme_max )
	    {
	      somme_max = somme;
	      imax = i;
	      jmax = j;
	    }
	}
    }
  
  std::cout << "Position : " << imax << ' ' << jmax << " Somme : " << somme_max << std::endl;
  
  delete [] tab;
  return 0;
}
