// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements

  int i;
  int numElementsLeft = n; //the number of elements left in the array
  int currIndex = 0; //the current index that has been counted until
  int numSteps = 1; //the number of steps that have been taken forward in the array
  int flag = 0; //flag for if the next value is a '-1'
  //int forLimit; //the upper bound for the 'for' loop
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  /*
  if(n > k)
  {
    forLimit = n;
  }
  else if(k >= n)
  {
    forLimit = k;
  }
  */

  while(numElementsLeft > 1)
  {
    for(i = 0; i < k; i++)
    {
      flag = 0;
      if(currIndex >= n)
      {
        //i = i % n;
        currIndex = currIndex % n;
      }
      if(arr[currIndex] == -1)
      {
        //i++;
        do
        {
          currIndex++;
          if(currIndex >=n)
          { 
            currIndex = currIndex % n;
          }
        } while(currIndex < n && arr[currIndex] == -1);

        if(currIndex >= n)
        {
          currIndex = currIndex % n;
          //flag = 1;
        }
      }
      if(numSteps == k)
      {
        printf("%d\n", currIndex);
        arr[currIndex] = -1;
        numSteps = 0;
        numElementsLeft--;
      }
      currIndex++;
      if(flag == 0)
      {
        numSteps++;
      }
    }
  }

  // print the last one

  for(i = 0; i < n; i++)
  {
    if(arr[i] != -1)
    {
      printf("%d\n", i);
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
