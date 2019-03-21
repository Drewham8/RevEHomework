#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int array[100];
  int i;
  int lastindex = 99;
  int iteration = 1;
  long long temp;
  srandom(time(NULL));

  i=0;
 start:
  array[i] = random();
  i++;
  if (i<100) goto start;

  int small;
  int start = 0;

 manager:
  if(start == lastindex)
    goto end;
  iteration = start + 1;
  
 insertionloop:
  small = start;

  
  /* does all the iteration and work */
 loop:
   if(array[small] > array[iteration])
    small = iteration;
  iteration++;
  if(iteration <= lastindex)
    goto loop;
  /* now the small has been determined, swap with start pos */

  
  /* swaps the small with the start pos */
 swap:
  temp = array[start];
  array[start] = array[small];
  array[small] = temp;
  start++;
  goto manager;
  /* prints out array when finished */
 end:
  ;
  int loop = 0;
 print:
  printf("%ld \n",array[loop]);
  loop++;
  if(loop < sizeof(array)/sizeof(*array) - 1)
    goto print;
}
