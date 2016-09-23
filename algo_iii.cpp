#include <iostream>
#include <stdlib.h>
using namespace std;



void seq_fusion(int *, int, int, int *);
void fusion(int* tab, int i, int j, int* sauv1, int* sauv2, int* sauv);

int main(int argc, char ** argv)
{
	int * tab, n = argc - 1;
	tab = new int[n];

	for( int i = 0; i < n; i++)
		tab[i] = atoi(argv[i+1]);

	int res[3];
	seq_fusion(tab, 0, n-1, res);

	cout << "Position : " << res[1] << ' ' << res[2] << " Somme : " << res[0] << endl;
	delete [] tab;

	return 0;
}





void seq_fusion(int * tab, int i, int j, int * sauv)
{
	if( i == j)
	{
		sauv[0] = tab[i];
		sauv[1] = i;
		sauv[2] = j;
		return;
	}

	int sauv1[3], sauv2[3];

	seq_fusion(tab, i, (i+j)/2, sauv1);
	seq_fusion(tab, (i+j)/2 + 1, j, sauv2);
	fusion(tab, i, j, sauv1, sauv2, sauv);
}

void fusion(int* tab, int i, int j, int* sauv1, int* sauv2, int* sauv)
{
	int somme, max, maxd, maxg, k, l;

	//Calcul Pgss à gauche
	somme = tab[ (i+j)/2 ];
	maxg  = tab[ (i+j)/2 ];
	k     = (i+j)/2;
	for(int p = k-1; p >= i; p--)
	{
		somme += tab[p];
		if(somme > maxg)
		{
			maxg = somme;
			k = p;
		}
	}

	//Calcul Pgss à droite
	somme = tab[ (i+j)/2 ];
	maxd = tab[ (i+j)/2];
	l = (i+j)/2;
	for(int p = (i+j)/2 + 1; p <= j; p++)
	{
		somme += tab[p];
		if(somme > maxd)
		{
			maxd = somme;
			l = p;
		}
	}
	
	max = maxd + maxg - tab[ (i+j)/2 ];
	
	if(sauv1[0] > sauv2[0] && sauv1[0] > max)
	{
		sauv[0] = sauv1[0];
		sauv[1] = sauv1[1];
		sauv[2] = sauv1[2];
	}
	
	else if(sauv2[0] > sauv1[0] && sauv2[0] > max)
	{
		sauv[0] = sauv2[0];
		sauv[1] = sauv2[1];
		sauv[2] = sauv2[2];
	}
	else
	{
		sauv[0] = max;
		sauv[1] = k;
		sauv[2] = l;
	}
}









