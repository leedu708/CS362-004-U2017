#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

// testing for the correct implementation of fullDeckCount

int testFullDeckCount() {
  // status of test initialized to -1
  // status = 0 if test passes
  int status = -1;
  int random = 4;

  // create game state
  struct gameState G;

  // create cards
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

  status = initializeGame(2, k, random, &G);

  assert(status == 0);

  status = fullDeckCount(0, copper, &G);

  assert (status >= 0);

  int i, j, count = 0;
  for (i = 0; i < G.deckCount[0]; i++) {
    if (G.deck[0][i] == copper) {
      count++;
    }
  }

  for (i = 0; i < G.handCount[0]; i++) {
    if (G.hand[0][i] == copper) {
      count++;
    }
  }

  for (i = 0; i < G.discardCount[0]; i++) {
    if (G.discard[0][i] == copper) {
      count++;
    }
  }

  printf("Test for fullDeckCount is successful!\n");

  status = 0;
  return status;
}

int main() {
  return testFullDeckCount();
}
