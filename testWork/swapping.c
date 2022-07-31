#include<stdio.h>
#include<stdlib.h>

void swap1(int a, int b)
{
  int c = a;
  a=b;
  b=c;
}

void swap2(int * a, int * b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

int main(int argc, char * * argv)
{
  int s = 264;
  int t = 7012;
  swap1(s,t);
  printf("s = %d, t = %d\n", s, t);

  s = 264;
  t=7012;

  swap2(&s, &t);
  printf("s = %d, t = %d\n", s, t);
  return EXIT_SUCCESS;
}
