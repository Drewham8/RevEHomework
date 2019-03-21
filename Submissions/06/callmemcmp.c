#include <stdio.h>
#include <inttypes.h>
#include <string.h>

int64_t my_memcmp(void *p1, void *p2, uint64_t n);

int main(int argc, char **argv)
{
    char *str1 = "Hello World!";
    char *str2 = "Hello World!\n";


    printf("%" PRId64 "\n", my_memcmp(str1, str2, strlen(str1)));
    printf("%" PRId64 "\n", my_memcmp(str1, str2, strlen(str2)));
}
