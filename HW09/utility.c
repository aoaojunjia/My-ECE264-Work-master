// do not modify this file
#include "utility.h"
#include <stdio.h>

void printDeck(CardDeck deck)
{
  int iter;
	for(iter = 0; iter < deck.size; iter++)
	{
		printf("%c",  deck.cards[iter]);
	}
	printf("\n");
}

