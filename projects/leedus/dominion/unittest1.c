#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

// testing for the correct implementation of SupplyCount

int testSupplyCount() {
  // status of test initialized to -1
  // status = 0 if test passes
  int status = -1;

  // create play variable
  int playVar = 0;

  // create game state
  struct gameState G;

  // setup game state for SupplyCount
  G.supplyCount[gold] = 4;

  status = supplyCount(gold, &G);

  assert(status == 4);
  status = 0;

  printf("Test for SupplyCount is successful!\n");

  return status;
}

int main() {
  return testSupplyCount();
}
