#include <iostream>
#include <stdlib.h>
using namespace std;

void Pgss(int*, int*, int);

int main(int argc, char ** argv)
{
	int * tab, n = argc - 1;
	tab = new int[n];

	for( int i = 0; i < n; i++)
		tab[i] = atoi(argv[i+1]);

	int somme, max, maxd, maxg, k, l;
	int cor1[3];
	int cor2[3];
		
	Pgss(cor1, tab, n/2);
	Pgss(cor2, tab + (n/2), n - n/2);

	//Calcul Pgss à gauche
	somme = 0;
	maxd = tab[n/2 - 1];
	k = n/2 - 1;
	for(int i = (n/2) - 1; i >= 0; i--)
	{
		somme += tab[i];
		if(somme > maxd)
		{
			maxd = somme;
			k = i;
		}
	}

	//Calcul Pgss à droite
	somme = 0;
	maxg = tab[n/2 - 1];
	l = n/2 - 1;
	for(int i = n/2 - 1; i < n; i++)
	{
		somme += tab[i];
		if(somme > maxg)
		{
			maxg = somme;
			l = i;
		}
	}
	
	max = maxd + maxg - tab[n/2-1];
	
	if(cor1[0] > cor2[0] && cor1[0] > max)
	{
		max = cor1[0];
		k = cor1[1];
		l = cor1[2];
	}
	
	else if(cor2[0] > cor1[0] && cor2[0] > max)
	{
		max = cor2[0];
		k = cor2[1];
		l = cor2[2];
	}
	cout << "Position : " << k << ' ' << l << " Somme : " << max << std::endl;
	delete [] tab;
	return 0;
}





void Pgss(int* res, int * tab, int n)
{
	int i, j, k, l, somme_temp=tab[0], somme_max=tab[0];
	for(i = 0; i < n; i++)
	{
		somme_temp = 0;
		for(j = i; j < n; j++)
		{
			somme_temp += tab[j];
			if( somme_temp > somme_max )
			{
				somme_max = somme_temp;
				k = i;
				l = j;
			}
		}
	}
	res[0] = somme_max;
	res[1] = k;
	res[2] = l;
	return;
}









