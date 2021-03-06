CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unit1: dominion.o unittest1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c rngs.c -o unittest1 -lm -g

unit2: dominion.o unittest2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c rngs.c -o unittest2 -lm -g

unit3: dominion.o unittest3.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c rngs.c -o unittest3 -lm -g

unit4: dominion.o unittest4.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c rngs.c -o unittest4 -lm -g

card1: dominion.o cardtest1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c rngs.c -o cardtest1 -lm -g

card2: dominion.o cardtest2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c rngs.c -o cardtest2 -lm -g

card3: dominion.o cardtest3.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest3.c rngs.c -o cardtest3 -lm -g

card4: dominion.o cardtest4.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest4.c rngs.c -o cardtest4 -lm -g

unittestresults.out: card1 card2 card3 card4 unit1 unit2 unit3 unit4 dominion.o
	./unittest1 				 >> unittestresults.out 2>&1
	./unittest2 				 >> unittestresults.out 2>&1
	./unittest3 				 >> unittestresults.out 2>&1
	./unittest4 				 >> unittestresults.out 2>&1
	./cardtest1 				 >> unittestresults.out 2>&1
	./cardtest2 				 >> unittestresults.out 2>&1
	./cardtest3 				 >> unittestresults.out 2>&1
	./cardtest4 				 >> unittestresults.out 2>&1
	gcov dominion.c 		 >> unittestresults.out 2>&1
	cat dominion.c.gcov 	>> unittestresults.out 2>&1

randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

randomtestadventurer.out: randomtestadventurer dominion.o
	./randomtestadventurer	>> randomtestadventurer.out 2>&1
	gcov -f dominion.c			>> randomtestadventurer.out 2>&1
	cat dominion.c.gcov			>> randomtestadventurer.out 2>&1

randomtestcard1: dominion.o randomtestcard1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard1.c rngs.c -o randomtestcard1 -lm -g

randomtestcard1.out: randomtestcard1 dominion.o
	./randomtestcard1				>> randomtestcard1.out 2>&1
	gcov -f dominion.c			>> randomtestcard1.out 2>&1
	cat dominion.c.gcov			>> randomtestcard1.out 2>&1

randomtestcard2: dominion.o randomtestcard2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard2.c rngs.c -o randomtestcard2 -lm -g

randomtestcard2.out: randomtestcard2 dominion.o
	./randomtestcard2				>> randomtestcard2.out 2>&1
	gcov -f dominion.c			>> randomtestcard2.out 2>&1
	cat dominion.c.gcov			>> randomtestcard2.out 2>&1

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestadventurer.out randomtestcard1 randomtestcard1.out randomtestcard2 randomtestcard2.out player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so badTestDrawCard testDrawCard unittestresults.out
