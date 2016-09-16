#include <iostream>
#include <stdlib.h>


int main(int argc, char ** argv)
{
  int * tab, n = argc - 1;
  tab = new int[n];

  for( int i = 0; i < n; i++)
    tab[i] = atoi(argv[i+1]);
 
  int i = 0, j = 0, k = 0, l=0;
  int somme_temp = tab[0], somme= tab[0];
  for(i = 0; i < n; i++)
    {
      somme_temp = 0;
      for( j = i; j < n; j++)
	{
	  somme_temp += tab[j];
	  if( somme_temp > somme )
	    {
	      somme = somme_temp;
	      k = i;
	      l = j;
	    }
	}
    }
  
  std::cout << "Position : " << k << ' ' << l << " Somme : " << somme << std::endl;
  
  delete [] tab;
  return 0;
}
