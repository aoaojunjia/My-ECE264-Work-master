/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/
  Node * node = malloc(sizeof(Node));
  if(node == NULL)
  {
    printf("malloc failed\n");
    return NULL;
  }

  node -> next = NULL;
  node -> value = val;

  return node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
  //open the file
  FILE * fptr = fopen(name, "r");
  if(fptr == NULL)
  {
    printf("fopen failed\n");
    return;
  }

  //get length
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
    return;
  }
	
	// use fscanf to read the file for its contents.
  int i = 0;
  while(!feof(fptr))
  {
    fscanf(fptr, "%d", &arr[i]);
    i++;
  } 

  *head = CreateNode(arr[0]);
  if(*head == NULL) //this may cause a problem since CreateNode returns the node's next as NULL
  {
    printf("create head node failed\n");
    return;
  }

  Node * currNode = *head;

  for(i = 1; i < length; i++)
  {
    currNode->next = CreateNode(arr[i]);
    if(currNode->next == NULL)
    {
      printf("List create failed\n");
      return;
    }
    currNode=currNode->next;
  }

  fclose(fptr);
  free(arr);
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/
  Node * currNode = headRef; //current node being checked
  Node * prevNode = headRef; //node directly previous to currNode
  Node * iter; //interating pointer through the linked list to find duplicates
  int flag = 0; //true if currNode has already been incremented

  while(currNode != NULL)
  {
    iter = headRef;
    if(flag != 1)
    {
      currNode = currNode->next;
    }
    flag = 0;

    //loop upto currNode
    while(iter != currNode)
    {
      while(currNode != NULL && (iter->value) == (currNode->value)) //check if the values are equal
      {
        //delete currNode
        prevNode->next = currNode->next;
	Node * temp = currNode;
	currNode = currNode->next;
	free(temp);
	flag = 1;
      }
      iter = iter->next;
    }
    if(flag != 1)
    {
      prevNode = prevNode->next;
    }
  }
  //print list
  LinkedListPrint(headRef);
}
#endif
