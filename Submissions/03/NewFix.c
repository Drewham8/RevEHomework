#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct account {
  float account_num;
  float money;
};

void sort(struct account *data, int len) 
{ 
  struct account tmp;
  int small = 0;
  int start = 0;
  for (int i = 1; i < len; i++) 
    { 
      for(int j = start + 1;j < len; j++)
        { 
          if(data[j].money < data[small].money)
            {
              small = j;
            }
        }
      tmp = data[small];
      data[small] = data[start];
      data[start] = tmp;
      start++;
    } 
}

double round_num(double *before){
  *before = *before * 100;
  double after;
  if( (int)(*before) % 1 < .5 )
    after = (int)*before;
  else
    after = (int)(*before + .5);
  after = after / (double)100;
  return after;
}

void total(struct account *data, int len){
  double round;
  double total = 0;
  for(int i = 0;i < len;i++){
    round = (data[i].money);
    total += round_num(&round);
  }
  printf("Total:\n%f\n",total);
}

void median(struct account *data, int len){
  int median = 0;
  if(len % 2 == 1)
    median = len/2 - 1;
  else
    median = (double)(len/2 + len/2 + 1)/2.0;
  double tmp = data[median].money;
  printf("Median:\n%f\n", round_num(&tmp));
}

void average(struct account *data, int len)
{
  double average = 0;
  for(int i = 0;i < len;i++){
    average += data[i].money;
  }
  average /= len;
  printf("Average:\n%f\n",average);
}

int main(int argc, char **argv)
{
  FILE *input_file = fopen("customer.input", "r"); //read only
  int array_size = 10;
  float x,y;
  int position = 0;
  struct account *data;
  int elements = 0;
  printf("The following are my array resizing:\n");
  data = malloc(array_size * sizeof(struct account));

  while( EOF!=fscanf(input_file,"%f %f", &x, &y) ){
    data[position].account_num = x;
    data[position].money = y;
    elements++;
    struct account *tmp;
    if(position + 1 >= array_size){
      tmp = realloc(data, 2*array_size*sizeof(struct account));
      if (tmp){
        data = tmp;
        array_size *= 2;
        printf("%i biggify!!!!!\n",array_size);
      }
      else{
        printf("panic!!!!!!!\n");
        exit(1);
      }
    }
    position++;
  }
  total(data,elements);
  sort(data,elements);
  median(data,elements);
  average(data,elements);
  fclose(input_file);
}

