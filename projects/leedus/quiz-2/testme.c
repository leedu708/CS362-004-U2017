#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // generate random ASCII value for char
    return (rand() % 95) + 32;
}

char *inputString()
{
    // return a random string
    int i, j;
    char err[5] = "erst";
    static char output[6];

    // generate a random number from 0-10, if number is less than 4
    // generate random chars for output
    if((rand() % 10) < 4) {
      for (i = 0; i < 5; i++) {
        output[i] = inputChar();
      }
    // if number is greater than or equal to 4, only use the chars "e", "r",
    // "s" and "t" to generate output
    } else {
      for (i = 0; i < 5; i++) {
        j = rand() % 4;
        output[i] = err[j];
      }
    }

    output[5] = '\0';

    return output;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
