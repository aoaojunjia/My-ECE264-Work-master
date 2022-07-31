/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif

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
    printf("fopen failed\n");
    return EXIT_FAILURE;
  }
	
	// count the number of integers in the file.
  int length = 0;
  int n;
  while(fscanf(fptr, "%d", &n) == 1)
  {
    length++;
  }
  fseek(fptr, 0, SEEK_SET);

	// allocate memory to store the numbers
  int * arr = malloc(sizeof(int) *  length);
	
	// check for malloc fail, if so, return EXIT_FAILURE
  if(arr == NULL)
  {
    printf("malloc failed\n");
    return EXIT_FAILURE;
  }
	
	// use fscanf to read the file for its contents.
  int i = 0;
  while(!feof(fptr))
  {
    fscanf(fptr, "%d", &arr[i]);
    i++;
  }

	// create head node, which corresponds to the head of the linked-list.
  Node * head = CreateNode(arr[0]);
  if(head == NULL)
  {
    printf("Create head node failed\n");
    return EXIT_FAILURE;
  }

	// You must now use the appropriate function to construct the remaining list.
  LinkedListCreate(&head, length, arr);

	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
  MergeSort(&head);

	// use the provided function to print the final list.
  LinkedListPrint(&head);

	// Tip: Check for memory errors.
  fclose(fptr);
  free(arr);
  Node * currNode = head->next;

  //freeing the linked list
  while(currNode != NULL)
  {
    Node * temp = currNode;
    currNode = currNode->next;
    free(temp);
  }
  free(head);

  return EXIT_SUCCESS;
}

#endif
