#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char ** argv)
{
  srand(time(NULL));
  FILE *F;
  F =fopen("tab.sample", "a");
  int i = atoi(argv[1]), j = 0, temp, step = atoi(argv[3]), n = atoi(argv[2]);
  
  while( i < n )
    {
      j = 0;
      if( i % 1000 == 0)
	printf("%d\n",i);
      while( j < i)
	{
	  temp = (rand()%50 - rand()%50);
	  fprintf(F, "%d ",temp);
	  j++;
	}
      fprintf(F, "\n");
      i += step;
    }
  


  fclose(F);



  return 0;
}
