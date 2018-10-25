#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");
  
  printf("size of int: %d\n", sizeof(int));
  printf("size of int*: %d\n", sizeof(int*));
  printf("size of long: %d\n", sizeof(long));
  printf("size of double*: %d\n", sizeof(double*));
  printf("size of char**: %d\n", sizeof(char**));
  
  return 0;
}