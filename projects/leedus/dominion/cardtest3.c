#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int testEmbargo() {
  // tests that fullDeckCount is properly implemented
  // initialize status of test to -1
  // if status = 0 by end of test, then test passes

  int status = -1;

  // create play variable
  int playVar = 0;
  int random = 4;

  // create cards variable
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

  // create game state
  struct gameState G;

  status = initializeGame(2, k, random, &G);

  assert(status == 0);

  int choices[3] = {0};
  int i;
  int j = 0;
  buyCard(embargo, &G);
  buyCard(embargo, &G);
  int found = 0;

  while(found == 0 && j < 5) {
    for (i = 0; i < numHandCards(&G); i++) {
      if (handCard(i, &G) == embargo) {
        found = 1;
      }

      j++;
    }

    endTurn(&G);
  }

  status = cardEffect(embargo, choices[0], choices[1], choices[2], &G, i, NULL);

  assert(status == 0);

  printf("Test Embargo Successful!\n");

  status = 0;
  return status;
}

int main() {
  return testEmbargo();
}
