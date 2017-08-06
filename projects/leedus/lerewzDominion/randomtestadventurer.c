#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUM_TESTS 100

int main() {
  int i, j, player_count, player, seed, hand_size, treasures_before, treasures_after, pass, fail;

  pass = 0;
  fail = 0;
  treasures_before = 0;
  treasures_after = 0;

  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf("Start Adventurer Test\n");

  for (i = 0; i < NUM_TESTS; i++) {
    srand(time(NULL));
    player_count = rand() % 2 + 2;
    seed = rand() % 100;

    if (initializeGame(player_count, k, seed, &G) == -1) {
      printf("Failed to start a random game\n");
      fail++;
      continue;
    }

    player = rand() % player_count;
    G.whoseTurn = player;
    G.numActions = 1;
    G.handCount[player] = 5;
    G.deckCount[player] = floor(rand() % MAX_DECK) + 1;
    G.discardCount[player] = 0;

    // generate the deck, count treasures
    for (j = 0; j < G.deckCount[player]; j++) {
      G.deck[player][j] = rand() % treasure_map;
    }

    // generate player's hand, count treasures
    for (j = 1; j < G.handCount[player]; j++) {
      G.hand[player][j] = rand() % treasure_map;
      if(G.deck[player][j] == copper || G.deck[player][j] == gold || G.deck[player][j] == silver) {
        treasures_before++;
      }
    }

    // add adventurer to player's hand
    G.hand[player][0] = adventurer;
    hand_size = G.handCount[player];

    playCard(0, 0, 0, 0, &G);

    // count treasures in player's hand again
    for (j = 0; j < G.handCount[player]; j++) {
      if (G.deck[player][j] == copper || G.deck[player][j] == gold || G.deck[player][j] == silver) {
        treasures_after++;
      }
    }

    if (treasures_after < treasures_before || treasures_after > treasures_before + 2) {
      fail++;
      continue;
    }

    pass++;

  }

  printf("Number Passsed: %d\n", pass);
  printf("Number Failed: %d\n", fail);
  printf("End Adventurer Test\n");
  return 0;
}
