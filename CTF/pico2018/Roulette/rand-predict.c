#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

#define MAX_NUM_LEN 12
#define HOTSTREAK 3
#define MAX_WINS 16
#define ONE_BILLION 1000000000
#define ROULETTE_SIZE 36
#define ROULETTE_SPINS 128
#define ROULETTE_SLOWS 16
#define NUM_WIN_MSGS 10
#define NUM_LOSE_MSGS 5

long cash = 0;
long wins = 0;

int is_digit(char c) {
    return '0' <= c && c <= '9';
}

long get_long() {
    printf("> ");
    uint64_t l = 0;
    char c = 0;
    while(!is_digit(c))
      c = getchar();
    while(is_digit(c)) {
      if(l >= LONG_MAX) {
	l = LONG_MAX;
	break;
      }
      l *= 10;
      l += c - '0';
      c = getchar();
    }
    while(c != '\n')
      c = getchar();
    return l;
}

const char *win_msgs[NUM_WIN_MSGS] = {
  "Wow.. Nice One!",
  "You chose correct!",
  "Winner!",
  "Wow, you won!",
  "Alright, now you're cooking!",
  "Darn.. Here you go",
  "Darn, you got it right.",
  "You.. win.. this round...",
  "Congrats!",
  "You're not cheating are you?",
};

const char *lose_msgs1[NUM_LOSE_MSGS] = {
  "WRONG",
  "Nice try..",
  "YOU LOSE",
  "Not this time..",
  "Better luck next time..."
};

const char *lose_msgs2[NUM_LOSE_MSGS] = {
  "Just give up!",
  "It's over for you.",
  "Stop wasting your time.",
  "You're never gonna win",
  "If you keep it up, maybe you'll get the flag in 100000000000 years"
};

int main(int argc, char *argv[]) {
  puts("rember: win msg = 1 rand(); lose msg = 2 rand() uses");
  long seed = get_long();
  srand(seed);
  for (int i = 0; i< 20; i++) {
    long spin = (rand() % ROULETTE_SIZE)+1;
    printf("\n Spin #'%d': '%lu' \n", i,spin);
  }
  return 1;
}

/*
 we know the seed of the rand() function, because the get_rand() func returns the seed and stores that value as your start cash value
 next bug is getting one billion. since the cash value is sotred in Long but it comparese the MAX value which means its unisigned.
 therefor a interger over flow bug is avaliable so LONG_MAX = 2147483647 but if we put LONG_MAX + 1 it will flow over to 0.
 therefore if we want a higher value whhat we can do is LONG_MAX + 2000000 do this when you lose so the cash value will be reduced to 0 then overflow,
 into one_billion. if you did it on a win the bet would be * 2 then you have the reverse happen it ends up in the negative.

 TODO make blog post
*/
