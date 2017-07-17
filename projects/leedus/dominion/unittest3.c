#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

// testing for the correct implementation of shuffle

int testShuffle() {
  // status of test initialized to -1
  // status = 0 if test passes
  int status = -1;

  // create play variable
  int playVar = 0;

  // create game state
  struct gameState G;

  // set up the deck for testing
  G.deckCount[p] = 3;
  G.deck[p][0] = copper;
  G.deck[p][1] = gold;
  G.dekc[p][2] = silver;

  // shuffle cards
  status = shuffle(p, &G);
  if (status < 0) {
    return status;
  }

  // initialize a deck to 0
  int deck[MAX_DECK] = {0};

  int i;
  for (i = 0; i < 3; i++) {
    deck[G.deck[p][i]] = 1;
  }

  assert(deck[copper] && deck[gold] && deck[silver]);
  status = 0;

  printf("Test for shuffle is successful!\n");

  return status;
}

int main() {
  return testShuffle();
}
