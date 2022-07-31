//
// Update this file as indicated.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "shuffle.h"

#ifdef TEST_MAIN
int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  int i;
	
	// Check for missing inputs
  if(argc < 2)
  {
    printf("Not enough arguments\n");
    return EXIT_FAILURE;
  }
	// Create a structure variable (corresponding to the original deck)
        // Ensure you initialize the srtuct variable "size" with MAX_SIZE (declared in utility.h)
        // initialize cards to 0 since it will be populated using memcpy(..)
  CardDeck origDeck;
  origDeck.size = MAX_SIZE;
  for(i = 0; i < origDeck.size; i++)
  {
    origDeck.cards[i] = 0;
  }

    // Use memcpy(),
        //For example: memcpy(orig_deck.cards, deck, MAX_SIZE * sizeof(orig_deck.cards[0]));
  memcpy(origDeck.cards, deck, MAX_SIZE * sizeof(origDeck.cards[0]));

	// Read the number of cards from the terminal input
	   // For example orig_deck.size = strtol(argv[1], NULL, 10);
  origDeck.size = strtol(argv[1], NULL, 10);

  if(origDeck.size < 2 || origDeck.size > 13)
  {
    printf("Number of cards needs to be between 2 and 13, inclusive\n");
    return EXIT_FAILURE;
  }

	//call shuffle(orig_deck);
  shuffle(origDeck);

  return EXIT_SUCCESS;
}
#endif
