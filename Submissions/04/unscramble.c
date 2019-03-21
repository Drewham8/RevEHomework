#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// Sample code for Lab 04: Content Scrambling.  Feel free to use this as the basis for your solution.



// Some enumerations which you may find helpful.
typedef enum {ADD, SUB, XOR, WRITE} operation_t;
typedef enum {BYTE = 1, WORD = 2, DWORD = 4} oper_size_t;


void *mmap_file(char *filename, size_t *out_size) {
  /* 
   * Use mmap() to map a file into our memory space, rather than read the whole file into a buffer.
   * For large files this is a performance win, and it avoids dealing with explicitly reading and
   * writing the file.
   *
   * Returns a pointer to the mapped file and updates the size variable on success.  Returns NULL
   * on failure.
   * 
   * Note that writes to the file mapping will modify the on-disk file in place.  
   */
  int fd, success;
  struct stat sbuf;
  void *mapped;
  
  fd = open(filename, O_RDWR);
  if (fd < 0) {
    perror("Error opening file");
    return NULL;
  }
  // fstat() fetches statistics about a file.  In this case, we need the size so we can map the
  // whole thing.
  success = fstat(fd, &sbuf);
  if (success < 0) {
    perror("Error finding file size");
    return NULL;
  }
  *out_size = sbuf.st_size;
  mapped = mmap(0, *out_size, PROT_READ|PROT_WRITE,
		MAP_SHARED, fd, 0);
  if (mapped == MAP_FAILED) {
    perror("Error mmapping file");
    return NULL;
  }
  // Now that mmap has succeeded, we don't need to keep the fd open.
  close(fd);
  return mapped;  
}

void printBytes(void *bytes, int n) {
  for(int i = 0; i < n; i++){
    printf("%c",*((char *)(bytes + i)));
  }
  printf("\n");
}


int main(int argc, char **argv) {
  void *mapped;
  size_t map_size;
  FILE *script;
    
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <mediafile> <scriptfile>\n", argv[0]);
    exit(1);
  }
  mapped = mmap_file(argv[1], &map_size);
  if (! mapped) {
    exit(2);
  }
  script = fopen(argv[2], "r");

  if (! script) {
    perror("Error opening script file");
    exit(3);
  }
  
  //opening setup
    
  char x[6], y[6];
  unsigned int offst,sour;
  
  //what I have right now for the loop
  while( EOF!=fscanf(script,"%s %s %x %x", x, y, &offst, &sour) ){
    if(!strcmp(x,"SUB")){
      if(!strcmp(y, "DWORD")){
        *((unsigned int *)((char *)mapped + offst)) = *((unsigned int *)((char *)mapped + offst)) - ((unsigned int)sour);
      }
      else if(!strcmp(y, "WORD")){
        *((unsigned short *)((char *)mapped + offst)) = *((unsigned short *)((char *)mapped + offst)) - ((unsigned short)sour);
      }
      else{
        *((unsigned char *)((char *)mapped + offst)) = *((unsigned char *)((char *)mapped + offst)) - ((unsigned char)(sour));
      }
    }
    if(!strcmp(x,"WRITE")){
      if(!strcmp(y, "DWORD")){
        *((unsigned int *)((char *)mapped + offst)) = ((unsigned int)sour);
      }
      else if(!strcmp(y, "WORD")){
        *((unsigned short *)((char *)mapped + offst)) = ((unsigned short)sour);
      }
      else{
        *((unsigned char *)((char *)mapped + offst)) = ((unsigned char)(sour));
      }
    }
    if(!strcmp(x,"ADD")){
      if(!strcmp(y, "DWORD")){
        *((unsigned int *)((char *)mapped + offst)) = *((unsigned int *)((char *)mapped + offst)) + ((unsigned int)(sour));
      }
      else if(!strcmp(y, "WORD")){
        *((unsigned short *)((char *)mapped + offst)) = *((unsigned short *)((char *)mapped + offst)) + ((unsigned short)(sour));
      }
      else{
        *((unsigned char *)((char *)mapped + offst)) = *((unsigned char *)((char *)mapped + offst)) + ((unsigned char)(sour));    
      }
    }
    if(!strcmp(x,"XOR")){
      if(!strcmp(y, "DWORD")){
        *((unsigned int *)((char *)mapped + offst)) = *((unsigned int *)((char *)mapped + offst))^((unsigned int)(sour));
      }
      else if(!strcmp(y, "WORD")){
        *((unsigned short *)((char *)mapped + offst)) = *((unsigned short *)((char *)mapped + offst))^((unsigned short)(sour));
      }
      else{
        *((unsigned char *)((char *)mapped + offst)) = *((unsigned char *)((char *)mapped + offst))^((unsigned char)(sour));
      }
    }
    
  }
  
  // You'll probably want to do some work here.
  printBytes(mapped,map_size);
  
  fclose(script);
  munmap(mapped, map_size);
  
}


        
