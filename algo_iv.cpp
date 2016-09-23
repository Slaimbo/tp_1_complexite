#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char ** argv)
{
  int * tab, n = argc - 1;
  tab = new int[n];

  for( int i = 0; i < n; i++)
    tab[i] = atoi(argv[i+1]);
 
  int i = 0, k = 0, l = 0;
  int somme_max = tab[0], somme = 0;
  for(int j = 0; j < n; j++)
    {
	somme += tab[j];
	
	if( somme > somme_max )
	{
	      somme_max = somme;
	      k = i;
	      l = j;
	}
	
	if(somme < 0)
	{
		somme = 0;
		i = j + 1;
	}
    }
  
  cout << "Position : " << k << ' ' << l << " Somme : " << somme_max << endl;
  
  delete [] tab;
  return 0;
}
