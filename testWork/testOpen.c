#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * * argv)
{

  if(argc != 2)
  {
    printf("ERROR\n");
    return EXIT_FAILURE;
  }

  FILE * fp = fopen(argv[1], "r");
  if(fp == NULL)
  {
    printf("another error");
    return EXIT_FAILURE;
  }
  else
  {
    printf("success\n");
  }

  char c = scanf(fp);
  printf("%c    %d\n", c, c);
  c = scanf(fp);
  printf("%c    %d\n", c, c);

  return EXIT_SUCCESS;
}

