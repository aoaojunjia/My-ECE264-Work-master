// Modify this file at said locations
#include "decode.h"
#include "list.h"
#include "utility.h"


/*
------------------------------------------------------------------------------
You Can Modify below, Do Not modify above this
------------------------------------------------------------------------------
*/

#ifdef TEST_READHEADER

TreeNode * readHeader(FILE * infptr)
{
	/* This function should have the following logic
	 * The first bit is a command bit and it is always 1.
	 * If a command is 1, then the next 8 bits(for this assignment) are the value stored
	 	 in a leaf node. Create a tree node to store this value. Add this tree node to the
		 beginning of the linked list (basically, LinkedList is acting like a stack here).
     This tree node is a single-node tree.  
	 * If a command is 0 and the list has two or more nodes, then take the first two nodes from
	 	 the list, create a tree node as the parent. Add this parent node to the linked list.
   * If a command is 0 and the list has only one node, then the complete tree has been built.
	 * After the tree is completely built, then read one more bit. If this is not the last
	 	 (rightmost) bit of the byte, discard the remaining bits in the byte.
	*/
  int done = 0;
  unsigned char whichBit = 0;
  unsigned char currByte = 0;
  unsigned char bit = 0;

  ListNode * head = NULL;

  while(done == 0)
  {
    //read the first bit from the file
    readBit(infptr, &bit, &whichBit, &currByte);
    if(bit == 1) //at a leaf node; next 8 bits have contain the character/letter
    {
      int bitcount;
      unsigned char value = 0;
      for(bitcount = 0; bitcount < 8; bitcount++) //now read the next 8 bits to get the character/letter
      {
        value <<= 1;
	readBit(infptr, &bit, &whichBit, &currByte);
	value |= bit;
      }
      TreeNode * newTN = TreeNode_create(value, 0); //creates a TreeNode for the newly read character/letter. Give arbritrary frequency (2nd argument)
      ListNode * newLN = ListNode_create(newTN); //creates a ListNode for the newTN; to be added to the linked list
      head = List_insert(head, newLN); //update head to include the newLN
    }
    else
    {
      if(head == NULL)
      {
        printf("head should point to a node\n");
	return NULL;
      }
      if(head->next == NULL) //no more data to read; the tree is complete
      {
        done = 1;
      }
      else
      {
        head = MergeListNode(head);
      }
    }
  } //read the entire header

  //no longer need the linked list; just need the tree of characters/letters
  TreeNode * root = head->tnptr;
  free(head);

  return root;
}

#endif


#ifdef TEST_DECODE

int decode(char * infile, char * outfile)
{
	// read the header from the input file  by calling readHeader function
	// the generated tree from the header generated should be printed in outfile
	// to print the tree into the file use Tree_print function given to you.
  // After reading the header till codebook, read the next 4 bytes from the header,
  // these 4 bytes represent number of characters in the file.
  // Print the number of characters obtained by using the PrintNumberChar function
	// Do not use your own print functions
	// free up the memory

  FILE * infptr = fopen(infile, "r");
  if(infptr == NULL)
  {
    printf("fopen read failed\n");
    return 0;
  }

  FILE * outfptr = fopen(outfile, "w");
  /*if(outfptr == NULL)
  {
    printf("fopen write failed\n");
    return 0;
  }*/

  TreeNode * root = readHeader(infptr); //will return the full tree of characters/letters
  Tree_print(root, outfptr);

  //done reading header. Now need to read the size/length of data; stored in next 4 bytes, which is the size of 1 int
  unsigned int length = 0;
  fread(&length, sizeof(unsigned int), 1, infptr); // int is 4 bytes so only need to read one

  PrintNumberChar(length, outfptr);

  //now read the remaining newline character; '\n'
  char newLine;
  fread(&newLine, sizeof(char), 1, infptr);
  if(newLine != '\n') //check if this was indeed the newline charcter indicating the begining of data
  {
    printf("header reading failed\n");
    return 0;
  }

  Tree_destroy(root);

  fclose(infptr);
  fclose(outfptr);

  return 1; //decode complete
}
#endif
