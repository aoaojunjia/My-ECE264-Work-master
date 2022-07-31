// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
  int dim  = x->dimension;

	// Create a new node
  ListNode * new = malloc(sizeof(ListNode));
  if(new == NULL)
  {
    printf("malloc failed\n");
    return NULL;
  }

  new->next = NULL;

  new->treenode = malloc(sizeof(TreeNode));

  new->treenode->dimension = dim;

  new->treenode->data = malloc(sizeof(int) * dim);

	// new -> treenode.left should be x
	// new -> treenode.right should be y

  new->treenode->left = x;
  new->treenode->right = y;

  /*int inter = 0;
  int val1, val2;

  do
  {
    val1 = x->treenode->data[iter];
    val2 = y->treenode->data[iter];

    if(val1 < val2)
    {
      new->treenode.left = x;
      new->treenode.right = y;
    }
    else if(val2 < val1)
    {
      new->treenode.left = y;
      new->treenode.right = x;
    }

    iter++;
  }while(val1 == val2);*/


	// x -> treenode.data should be less than y -> treenode.data (refer to README)
	
	// Use a loop to average the data from the two parameters (x and y).
	/*
	EXAMPLE
	Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	and so on
	*/ 
  int iter;
  for(iter = 0; iter < dim; iter++)
  {
    new->treenode->data[iter] = (x->data[iter] + y->data[iter]) / 2;
  }

	// Return the new node
  return new;
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
  	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance

  //int dim = sizeof(x->data) / sizeof(x->data[0]); //length of array; dimension
  int dim = x->dimension;
  int distance = 0;
  int i;

  for(i = 0; i < dim; i++)
  {
    distance += (y->data[i] - x->data[i]) * (y->data[i] - x->data[i]);
  }

  //distance += (y->data - x->data) * (y->data - x->data);

  return distance;
}
#endif


#ifdef TEST_FUSE
ListNode * removeNode(ListNode * head, ListNode * node)
{
  ListNode * curr = head;
  ListNode * nxt = head;

  if(curr == NULL) //if doesn't exist
  {
    return curr;
  }

  if(curr == node) //if first node
  {
    curr = curr->next;
    return curr;
  }

  nxt = curr->next;
  while(nxt != NULL && nxt != node)
  {
    curr = curr->next;
    nxt = nxt->next;
  }

  if(nxt != NULL)
  {
    curr->next = nxt->next;
    //dont free the removed node yet; needs to be printed in MakeCluster
  }

  return head;
}

ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{

	// Create a new ListNode element using findCentroid function.
  ListNode * new = FindCentroid(fuse1->treenode, fuse2->treenode);

	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
  
	// add the new ListNode to the list.
  new->next = head;

  head = new;
  
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
  head = removeNode(head, fuse1);
  head = removeNode(head, fuse2);

	// you may want to return head from this function (depending on your implementation)
  return head;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// Same as previous HW

	// check for malloc error
  ListNode * node = malloc(sizeof(ListNode));
  if(node == NULL)
  {
    printf("malloc failed\n");
    return NULL;
  }
  
  //initialize the next to NULL
  node->next = NULL;

  node->treenode = malloc(sizeof(TreeNode));

	// initialize dim
  node->treenode->dimension = dim;

	// both left and right childern will be NULL
  node->treenode->left = NULL;
  node->treenode->right = NULL;

	// allocate memory for data
  node->treenode->data = malloc(sizeof(int) * dim);
  if(node->treenode->data == NULL)
  {
    printf("TreeNode data malloc failed\n");
    return NULL;
  }

  int i;
  for(i = 0; i < dim; i++)
  {
    node->treenode->data[i] = arr[i];
  }

	// return a ListNode
  return node;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// Same as previous HW
	// create temp node using CreateNode
	// read from file into an array, pass array to CreateNode
	// assign temp to that node
  
  int * arr = malloc(sizeof(int) * dim); //creates array to store coordinates of each datapoint

  int i;
  for(i = 0; i < dim; i++)
  {
    fscanf(fptr, "%d", &arr[i]);
  }

  *head = CreateNode(n, dim, arr);

	// use a loop to create nodes for the remaining elements of the list.

  //"arr" is temporary. It just stores the current data point and that arr then gets passed to CreateNode. Inside the loop, you read the file and update the arr. Then continue looping
  //already read the n and dim from the file; fptr at data now
  ListNode * curr = *head;
  int j;
  for(i = 1; i < n; i++)
  {
    for(j = 0; j < dim; j++)
    {
      fscanf(fptr, "%d", &arr[j]);
    }
    curr->next = CreateNode(n, dim, arr);
    curr = curr->next;
  }

  free(arr);
}
#endif

#ifdef TEST_CLUSTER
/*void freeTree(TreeNode * tn)
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
}*/

void MakeCluster(ListNode** head)
{
	// Walk through the linked list.
  
	// find pair of nodes with minimum distance.
	// find pair of ListNodes with least distance between them.
	// call print Function

	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2). 
	Look at README, and expected output for more details.
	*/
  ListNode * i = *head;
  ListNode * j = *head;
  ListNode * start = *head;
  ListNode * node1 = NULL; //first ListNode with smallest distance
  ListNode * node2 = NULL; //second ListNode with smallest distance
  int currDist = 0;
  int smallestDist = 0;
  int firstCheck = 1; //if first distance check, then this is 1. After first check, then goes to 0;

  int val1, val2;
  int iter = 0;
  ListNode * smaller = NULL;
  ListNode * larger = NULL;

  while(start->next != NULL)
  {
    //reset all variables
    i = start;
    smaller = NULL;
    larger = NULL;
    firstCheck = 1;
    smallestDist = 0;
    currDist = 0;

    while(i->next != NULL)
    {
      j = i->next;
      while(j != NULL)
      {
        currDist = FindDist(i->treenode, j->treenode);

        if(firstCheck == 1)
        {
          smallestDist = currDist;
          node1 = i;
          node2 = j;

	  firstCheck = 0;
        }

        if(currDist <= smallestDist)
        {
          smallestDist = currDist;
	  node1 = i;
	  node2 = j;
        }

        j = j->next;
      }

      i = i->next;
    }
  
    //At this point, node1 and node2 should point to the pair of ListNodes with the smallest distance, stored in smallestDist.

    //Now check for which ListNode is smaller and larger, based on the treeNode->data[i]
    //int dim = sizeof(node1->treenode->data) / sizeof(node1->treenode->data[0]); //length of array; dimension

    iter = 0;

    do
    {
      val1 = node1->treenode->data[iter];
      val2 = node2->treenode->data[iter];

      if(val1 < val2)
      {
        smaller = node1;
        larger = node2;
      }
      else if(val2 < val1)
      {
        smaller = node2;
        larger = node1;
      }

      iter++;
    }while(val1 == val2);

    //At this point, 'smaller' and 'larger' point to the smaller and larger node respectively. These two nodes can now be fused.

         // fuse the two nodes into one node.
    *head = Fuse(*head, smaller, larger);
    start = *head;

         // call print function
    PrintAns(*head, smaller, larger);

    //smaller->treenode = NULL;
    //larger->treenode = NULL;

    //freeTree(smaller->treenode);
    //free(smaller);
    //freeTree(larger->treenode);
    //free(larger);
  }
	// repeat till one node is remaining.
}
#endif


