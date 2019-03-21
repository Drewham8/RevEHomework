#include <stdio.h>



int main(int argc, char **argv)
{
  FILE *input_file = fopen("customer.input", "r"); //read only
  int x;
  float y;
  while( EOF!=fscanf(input_file,"%i%f", &x, &y) ){
      printf("%i %f\n",x,y);
  }
  fclose(input_file);
}
