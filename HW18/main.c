// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
void freeTree(TreeNode * tn)
{
  if(tn->left != NULL)
  {
    freeTree(tn->left);
  }
  if(tn->right != NULL)
  {
    freeTree(tn->right);
  }
  free(tn->data);
  free(tn);
}

int main(int argc, char * * argv)
{
	// check for input error
  if(argc != 2)
  {
    printf("not enough arguments\n");
    return EXIT_FAILURE;
  }

	// open the file
	// input file is in argv[1]
  FILE * fptr = fopen(argv[1], "r");
  if(fptr == NULL)
  {
    printf("fopen failed\n");
    return EXIT_FAILURE;
  }

	// n is the # of elements
  int n;
  fscanf(fptr, "%d", &n);

	// dim is the second element in the file
  int dim;
  fscanf(fptr, "%d", &dim);

  //head of list
  ListNode * head = NULL;

	// the rest of the data in the file are the datapoints.
	// call LinkedListCreate
  LinkedListCreate(&head, n, dim, fptr);

	// call FindMin
  FindMin(head);

  fclose(fptr);

  //free list and tree
  ListNode * currLN = head->next;
  while(currLN != NULL)
  {
    freeTree(currLN->treenode);

    ListNode * temp = currLN;
    currLN = currLN->next;
    free(temp);
  }

  freeTree(head->treenode);
  free(head);

  return EXIT_SUCCESS;
}
#endif
