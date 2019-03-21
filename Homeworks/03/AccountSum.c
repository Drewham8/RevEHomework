#include <stdio.h>

struct account {
  float account_num;
  float money;
};

void average(void *array, int len)
{
  int average = 0;
  for(int i=0;i < (sizeof(array)/sizeof(struct account));i++){
    average += *(array[i]).money;
  }
  average /= (sizeof(array)/sizeof(struct account));
  printf("%f\n",average);
}

void median(void *array, int len){
  int median = 0;
  if(len % 2 == 1)
    median = len/2 - 1;
  else
    median = len/2;
  printf("%i\n", *((struct account*)(array + median*sizeof(struct account))).money);
}

void total(void *array, int len){
  int total = 0;
  for(int i = 0;i < (sizeof(array)/sizeof(struct account));i++){
    total += *((struct account*)(array + i*sizeof(struct account))).money;
  }
  printf("%f\n",total);
}

int main(int argc, char **argv)
{
  FILE *input_file = fopen("customer.input", "r"); //read only
  int array_size = 10;
  float x,y;
  int position = 0;
  void *data;

  data = malloc(array_size * sizeof(struct account));

  while( EOF!=fscanf(input_file,"%i %f", &x, &y) ){
    *((struct account*)(data + position*sizeof(struct account))).account_num = x;
    *((struct account*)(data + position*sizeof(struct account))).money = y;
    struct account *tmp;
    if(position + 1 >= array_size){
      tmp = realloc(array_size, 2*array_size*sizeof(struct account));
      if (tmp){
        data = tmp;
        array_size *= 2;
        printf(array_size + "\n");
      }
      else{
        printf("panic!!!!!!!\n");
        exit(1);
      }
    }
    fclose(input_file);
    average(&data, array_size);
    sort(&data, array_size);
    median(&data, array_size);
    total(&data, array_size);
  }
}

