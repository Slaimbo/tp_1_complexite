#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char ** argv)
{
 	int * tab, n = argc - 1;
 	tab = new int[n];

 	for( int i = 0; i < n; i++)
   	tab[i] = atoi(argv[i+1]);
 
 	int k = 0, l = 0;
 	int sommemax = tab[0], somme;

 	for (int i = 1; i < n; i++)
	{
		if(tab[i] > 0)
		{
			/*calcule la plus grande sous sequence qui se termine par i*/			
			somme = 0;
			for ( int j = i; j >= 0; j--)
			{
				somme += tab[j];
				if(somme > sommemax)
				{				
					sommemax = somme;
					k = j;
					l = i;
				}
			}
		}
	}
	cout << "Position : " << k << ' ' << l << " Somme : " << sommemax << endl;
	delete [] tab;
	return 0;
}
