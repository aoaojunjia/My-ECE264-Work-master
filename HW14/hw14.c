/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// same as previous homeworks

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
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// Refer HW13 and HW12
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
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

void SplitList(Node* source, Node** head1, Node** head2)
{
	// Refer HW13
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

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower) 
{
  Node * newSource; //will be the new source of this sub merged-list

	// Check for the base cases. (When either sub-list is NULL)
  if(lower == NULL)
  {
    return upper; 
  }
  if(upper == NULL)
  {
    return lower;
  }
	// Pick the larger between upper and lower, and recur appropriately.
  //Node * currUpper = upper; //the i iterator for the upper list
  //Node * currLower = lower; //the j iterator for the lower list

  if((lower->value) <= (upper->value))
  {
    newSource = lower;
    newSource->next = Merge(lower->next, upper);
  }
  else
  {
    newSource = upper;
    newSource->next = Merge(lower, upper->next);
  }
	// return the merged array
  return newSource;
} 
#endif

#ifdef TEST_SORT

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

// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source) 
{ 
	// Declare a node, to hold the current head of the source list.
  Node * currHead = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
  Node * listHead1;
  Node * listHead2;
  
	// Check for the base case -- length 0 or 1
		// if so, return;
  if(listLength(currHead) == 0 || listLength(currHead) == 1)
  {
    //free(currHead);
    return;
  }
	  
	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
  SplitList(currHead, &listHead1, &listHead2);
	  
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
  MergeSort(&listHead1);
  MergeSort(&listHead2);
	 
	// Merge the two sorted lists together, using the Merge()
  *source = Merge(listHead1, listHead2);
} 
#endif

