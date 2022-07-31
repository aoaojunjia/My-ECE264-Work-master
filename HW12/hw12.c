/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
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
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");

}
#endif


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
  Node * node = malloc(sizeof(Node));
	// check memory allocation fails
  if(node == NULL)
  {
    printf("Malloc failed\n");
    return NULL;
  }
	// create a Node* with the value as 'value'(input argument).
  node->value = value;
  node->next = NULL;

  return node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
  int i;
  Node * currNode = *head;
	// check if length is not negative
  if(length > 0)
  {
	// create linked list of length as 'length'
    for(i = 1; i < length; i++)
    {
      currNode->next = CreateNode(i);
      if(currNode->next == NULL)
      {
        printf("CreateNode failed\n");
        return;
      }
      currNode = currNode->next;
    }
    currNode->next = *head; //makes the last node's next the head, forming a circular linked list!
  }
	// do not return anything
}
#endif



#ifdef TEST_JOSEPHUS
//function to print circular linked list
void printLinkedList(Node * head)
{
  Node * currNode = head;
  
  if((currNode->next) != currNode)
  {
    printf("%d,", currNode->value);
    currNode = currNode->next;
  }
  
  while((currNode->next) != head)
  {
    printf("%d,", currNode->value);
    currNode = currNode->next;
  }
  
  printf("%d", currNode->value);
  printf("\n");
}

int listLength(Node * head)
{
  int length = 0;

  Node * currNode = head;

  do
  {
    length++;
    currNode = currNode->next;
  }while(currNode != head);

  //printf("%d\n", length);

  return length;
}

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
  //int indexStart = 0;
  //int lcv; //loop control variable for going upto k
  //int count = 0;
  int i;
  Node * currNode = *head;

  /*if(currNode == NULL)
  {
    printf("List empty\n");
    return NULL;
  }*/
  
  Node * prevNode = *head;

  while(currNode->next != currNode)
  {
    for(i = 0; i < k; i++)
    {
      prevNode = currNode;
      currNode = currNode->next;
    }

    //move the head pointer because it is currently pointing to a node that is going to be removed
    if(currNode == *head)
    {
     *head = currNode->next;
    }

    prevNode->next = currNode->next;
    Node * temp = currNode;
    currNode = prevNode->next;
    //printf("%d\n", temp->value);
    free(temp);
    //count++;

    if(listLength(*head) % elemDivisible == 0)
    {
      //printf("***%d\n", listLength(*head));
      printLinkedList(*head);
    }

    /***Code below for when NOT using circular linked list (doesn't work)***/
    /*if(count == elemDivisible)
    {
      LinkedListPrint(head);
    }*/

    /*for(lcv = 0; lcv < k; lcv++)
    {
      if(prevNode != currNode)
      {
        prevNode = prevNode->next;
	*if(prevNode == NULL)
	{
	  prevNode = head;
	}*
      }

      currNode = currNode->next;
      if(currNode == NULL)
      {
        currNode = head;
      }
      if(prevNode == NULL)
      {
        prevNode = head;
      }
    }*/

    //prevNode->next = currNode->next;

    //free the node that needs to be deleted
    /*Node * temp = currNode;
    currNode = currNode->next;
    if(currNode == NULL)
    {
      currNode = head;
    }
    prevNode = prevNode->next;
    free(temp);*/

    /*currNode = currNode->next;
    index++;
    if((currNode->next) == NULL)
    {
      currNode = head;
      index++;
    }*/
  }

}

#endif
