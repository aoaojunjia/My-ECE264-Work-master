// Please modify this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"


#ifdef TEST_MAIN
/*void treeDestroy(TreeNode * tn)
{
  if(tn->left != NULL)
  {
    treeDestroy(tn->left);
  }
  if(tn->right != NULL)
  {
    treeDestroy(tn->right);
  }
  free(tn->data);
  free(tn);
}*/

int main(int argc, char * * argv)
{
	// check for input error
  if(argc != 2)
  {
    printf("not enough arguments\n");
    return EXIT_FAILURE;
  }

	// open the file
  FILE * fptr = fopen(argv[1], "r");
  if(fptr == NULL)
  {
    printf("fopen failed\n");
    return EXIT_FAILURE;
  }

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
	
	// call MakeCluster
  MakeCluster(&head);

  //treeDestroy(head->treenode);
  //free(head);
  fclose(fptr);

  return EXIT_SUCCESS;
}
#endif
