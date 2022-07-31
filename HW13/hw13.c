/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

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


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
  Node * node = malloc(sizeof(Node));
  if(node == NULL)
  {
    printf("Malloc failed\n");
    return NULL;
  }

	// Initialize "next", and "value" appropriately 
  node -> next = NULL;
  node -> value = val;
	
	//return the newNode
  return node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// Tip: use CreateNode(arr[index])
  int i;

  Node * currNode = *source;

  for(i = 1; i < len; i++)
  {
    currNode->next = CreateNode(arr[i]);
    if(currNode->next == NULL)
    {
      printf("List create failed\n");
      return;
    }
    currNode=currNode->next;
  }
}
#endif


#ifdef TEST_SPLIT

/*int listLength(Node * head)
{
  int length = 0;

  Node * currNode = head;

  while(currNode != NULL)
  {
    length++;
    currNode = currNode->next;
  }
  return length;
}*/

// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2) 
{ 
	// Find the mid point of the list.
	
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4

		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5
  int midPoint;

  int length = 0;
  Node * curr = source;
  while(curr != NULL)
  {
    length++;
    curr = curr->next;
  }

  if(length % 2 == 0)
  {
    midPoint = length / 2;
  }
  else
  {
    midPoint = (length / 2) + 1;
  }

    	// Tip: head1 will point to the source node.
  *head1 = source;
	// Tip: head2 will point to the mid-point of the list.
  Node * currNode = source;
  int i;
  for(i = 1; i < midPoint; i++)
  {
    currNode = currNode->next;
  }
  *head2 = currNode->next;
	// Tip: Ensure you break the link between the sub-lists.
  currNode->next = NULL;
  //printf("***	Head1: %d,	Head2: %d\n", *head1->value, *head2->value);
} 
#endif


#ifdef TEST_DIV
int listLength(Node * head)
{
  int length = 0;

  Node * currNode = head;

  while(currNode != NULL)
  {
    length++;
    currNode = currNode->next;
  }
  return length;
}

// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void Divide(Node** source) 
{ 
	// Declare a node, to hold the current head of source list.
  Node * currSourceHead = *source;	
	// Declare nodes, to hold the two the heads of the two sub-lists.
  Node * listHead1;

  Node * listHead2;
  
	// Check for the base case -- length 0 or 1
		// if so, return;
  if(listLength(currSourceHead) == 0 || listLength(currSourceHead) == 1)
  {
    free(currSourceHead);
    return;
  }
	  
	// Use SpiltList(...) to partition the list into sub lists.
  SplitList(currSourceHead, &listHead1, &listHead2); 

	// Use LinkedListPrint(...); to print the upper sub-list.
  LinkedListPrint(&listHead1);
	// Use LinkedListPrint(...); to print the lower sub-list
		// DO NOT USE YOUR OWN PRINT FUNCTION.
  LinkedListPrint(&listHead2);
	
	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 // till only one or no elements are left in the sub-lists.
  Divide(&listHead1);
  Divide(&listHead2);
} 
#endif

