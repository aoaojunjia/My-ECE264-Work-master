/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
  if(argc < 2)
  {
    printf("Not enough arguments\n");
    return EXIT_FAILURE;
  }

	// open file to read
  FILE * fptr = fopen(argv[1], "r");

	// check for fopen fail. If so, return EXIT_FAILURE
  if(fptr == NULL)
  {
    printf("Fopen failed\n");
    return EXIT_FAILURE;
  }
	
	// count the number of integers in the file.
  int length = 0;
  /*fseek(fptr, 0, SEEK_END);
  length = ftell(fptr); // sizeof(int);
  fseek(fptr, 0, SEEK_SET); //reset fptr to the beginning of the file
  */
  int n;
  while(fscanf(fptr, "%d", &n) == 1)
  {
    length++;
  }
  fseek(fptr, 0, SEEK_SET);

	// allocate memory to store the numbers
  int * arr = malloc(sizeof(int) * length);
	
	// check for malloc fail, if so, return EXIT_FAILURE
  if(arr == NULL)
  {
    printf("Malloc failed\n");
    return EXIT_FAILURE;
  }
	// use fscanf to read the file, and store its contents into an array.
  int i = 0;
  while(!feof(fptr))
  {
    fscanf(fptr, "%d", &arr[i]);
    i++;
  }
	// create head node to store the head of the linked list.
  Node * head = CreateNode(arr[0]);
  if(head == NULL)
  {
    printf("Create head node failed\n");
    return EXIT_FAILURE;
  }

	// call the appropriate function to create the rest of the linked list, with the values of the array.
  LinkedListCreate(&head, length, arr);

	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
  Divide(&head);

	// Tip: check for memory errors.
  fclose(fptr);

  //Node * currNode = head->next;

  //freeing the linked list
  /*while(currNode != NULL)
  {
    Node * temp = currNode;
    currNode = currNode->next;
    free(temp);
  }*/

  free(arr);
  //free(head);
  return EXIT_SUCCESS;
}

#endif
