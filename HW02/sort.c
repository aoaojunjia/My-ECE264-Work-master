// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  // call checkOrder to see whether this function correctly sorts the
  // elements
  
  int i;
  int j;
  int currMin; //smallest value in current pass
  int temp; //temporary variable to store during swap
  int minJ; //index location of smallest value in current pass

  for(i = 0; i < size; i++)
  {
    currMin = arr[i];
		minJ = i;
    for(j = i; j < size; j++)
    {
      if(arr[j] < currMin)
      {
        currMin = arr[j];
        minJ = j;
      }
    }

    temp = arr[i];
    arr[i] = currMin;
    arr[minJ] = temp;
  } 

  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
