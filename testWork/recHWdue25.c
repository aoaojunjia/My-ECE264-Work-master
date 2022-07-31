#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct
{
  int cnt1;
  int cnt2;
  int cnt3;
} Counters;

int func(int n , Counters * count)
{
  (count -> cnt1)++;
  if(n == 0)
  {
    return 0;
  }
  (count -> cnt2)++;
  int i;
  int sum = 0;
  for(i = 1; i <= n; i ++)
  {
    (count -> cnt3) += i;
    func(n - i, count);
    sum += i ;
  }
  return sum ;
}

int main(int argc, char * argv[])
{
  Counters count = // initialize attributes to zero
  { .cnt1 = 0,
    .cnt2 = 0,
    .cnt3 = 0
  };

  int result = func(4, &count);

  printf("result = %d\n", result); // A

  printf("Counters = %d, %d, %d\n",
    count.cnt1, // B
    count.cnt2, // C
    count.cnt3); // D
  return EXIT_SUCCESS;
}

