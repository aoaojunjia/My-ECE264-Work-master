// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST_DIV

void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks

	// starting from i = 1 -> size-1 copying into upper deck and lower decks
		// For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		// Update the size of the upper and lower decks after copying each element.
			// For example: upper_deck[i].size = i+1;
  int i; //lcv

  for(i = 0; i < orig_deck.size - 1; i++)
  {
    strncpy(upper_deck[i].cards, orig_deck.cards, i + 1);
    upper_deck[i].size = i + 1;
  }

		// Similarly perform the string copy, and size update operation on the lower deck.
			//For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
		    // For example: lower_deck[i].size = orig_deck.size -i - 1;
  for(i = 0; i < orig_deck.size - 1; i++)
  {
    strncpy(lower_deck[i].cards, orig_deck.cards + i + 1, orig_deck.size - (i + 1));
    lower_deck[i].size = orig_deck.size - (i + 1);
  }
}
#endif

#ifdef TEST_INTER
void interleaveHelper(CardDeck upperDeck, CardDeck lowerDeck, CardDeck currOrder, int currInd, int upperInd, int lowerInd)
{
  if(upperInd < upperDeck.size)
  {
    currOrder.cards[currInd] = upperDeck.cards[upperInd];
    currOrder.size = currInd + 1;
    interleaveHelper(upperDeck, lowerDeck, currOrder, currInd + 1, upperInd + 1, lowerInd);
  }

  if(lowerInd < lowerDeck.size)
  {
    currOrder.cards[currInd] = lowerDeck.cards[lowerInd];
    currOrder.size = currInd + 1;
    interleaveHelper(upperDeck, lowerDeck, currOrder, currInd + 1, upperInd, lowerInd + 1);
  }

  //recursive end condition
  if(upperInd == upperDeck.size && lowerInd == lowerDeck.size)
  {
    return;
  }

  /*if(upperInd == upperDeck.size)
  {
    memcpy(currOrder.cards + currInd, lowerDeck.cards + lowerInd, lowerDeck.size - lowerInd);
  }
 
  if(lowerInd == lowerDeck.size)
  {
    memcpy(currOrder.cards + currInd, upperDeck.cards + upperInd, upperDeck.size - upperInd);
  }*/
  
  if(currOrder.size == upperDeck.size + lowerDeck.size)
  {
    print_deck(currOrder);
  }
}

void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
    // Follow instructions in the README, to understand the working of the recursive function.
    // Use print_deck(…) to print each resulting order.
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.

  CardDeck currOrder;
  
  interleaveHelper(upper_deck, lower_deck, currOrder, 0, 0, 0);
}


#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
{
    // declare a variable to hold the number of pairs
        // we can say that we have only size-1 possibility of pairs
  int numPairs = orig_deck.size - 1;

    // if number of pairs == 0; return;
  if(numPairs == 0)
  {
    return;
  }

	// instantiate pointers to hold both upper and lower decks (after division)
	   // For example: CardDeck * upper_deck = NULL;
  CardDeck * upper_deck = NULL;
  CardDeck * lower_deck = NULL;

	// allocate memory based on number of pairs
	   //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
  upper_deck = malloc(sizeof(CardDeck) * numPairs);
  lower_deck = malloc(sizeof(CardDeck) * numPairs);

	// call divideDeck to fill upper_deck and lower_deck
  divide(orig_deck, upper_deck, lower_deck);

	//run a loop through all the pairs
		// for each pair of upper and lower deck call interleave()
		// For example: interleave(upper_deck[i],lower_deck[i])
  int i;
  for(i = 0; i < numPairs; i++)
  {
    interleave(upper_deck[i], lower_deck[i]);
  }

    // free memory allocated to upper and lower deck.
  free(upper_deck);
  free(lower_deck);
}
#endif
