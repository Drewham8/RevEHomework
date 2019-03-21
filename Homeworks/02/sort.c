#include <stdio.h>
#include <stdlib.h>

/* Sort the list without using loops or multi-line if statements.
 * Just good old goto.
 */
int main(int argc, char **argv)
{
  int array[100];
  int i;
    
  srandom(time(NULL));

  i=0;
 start:
  array[i] = random();
  i++;
  if (i<100) goto start;

 heapify:
        ;
        int end = sizeof(array)/sizeof(*array) - 1;
        int endofsift = end - 1;
        int start = (end - 1) / 2;
 
 siftAdmin:
        if (start >= 0)        
          goto siftSection;
        else
          goto end;
 finished:
        start--;
        goto siftAdmin;
 siftSection:
        ;
        int root = start;
        if (!((2 * root + 1) <= endofsift))
          goto finished;
 siftLoop:
        ;
          int child = 2 * root + 1;
   
          if (child + 1 <= end && array[child] < array[child + 1])
            child = child + 1;
          
          if (array[root] < array[child])
            goto ifstatement;
          else
            goto finished;
          
 ifstatement:
          ;
          int tmp = array[root];
          array[root] = array[child];
          array[child] = tmp;
          root = child;
         goto siftSection;
 end:
         ;
         int loop = 0;
 printloop:
         
         printf("%d \n",array[loop]);
         loop++;
         if(loop < sizeof(array)/sizeof(*array) - 1)
           goto printloop;
}
