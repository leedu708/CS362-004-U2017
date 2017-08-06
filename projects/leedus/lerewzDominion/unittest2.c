#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

// testing for the correct implementation of whoseTurn

int testWhoseTurn() {
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

  // grab the current player's turn
  status = whoseTurn(&G);

  assert(status == 0);

  printf("Test for whoseTurn is successful!\n");

  status = 0;
  return status;
}

int main() {
  return testWhoseTurn();
}
