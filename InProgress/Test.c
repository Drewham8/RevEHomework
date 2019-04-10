#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("%d",(int)**(argv + 1));

}
