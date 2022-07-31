/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"



/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc < 4 then return EXIT_FAILURE
  if(argc < 4)
  {
    return EXIT_FAILURE;
  }

	// argv[1] - length of linked list
  int length = strtol(argv[1], NULL, 10);
	// argv[2] - value of k as mentioned in josephus algorithm
  int k = strtol(argv[2], NULL, 10);
	// argv[3] - value of elemDivisible
  int elemDivisible = strtol(argv[3], NULL, 10);
	// create head node
  Node * head = CreateNode(0);
  //head->next = NULL;
  if(head == NULL) //createNode function returns NULL
  {
    return EXIT_FAILURE;
  }
	// create Linked list with length as argv[1]
  LinkedListCreate(&head, length);
	// run josephus
  Josephus(&head, k, elemDivisible);
	// free the head node

  //never-true if statement so that LinkedListPrint isn't uncalled
  if(0 == 1)
  {
    LinkedListPrint(head);
  }

  free(head);

  return EXIT_SUCCESS;
}

#endif
