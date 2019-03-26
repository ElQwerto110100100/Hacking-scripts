#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

long cash = 0;

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
         printf("l >= LONG_MAX uint64_t l: %lu \n",l);
	        break;
      }
      printf("uint64_t l: %lu \n",l);
      //printf("uint64_t l signed version: %ls \n",l);
      l *= 10;
      printf("uint64_t l *= 10: %lu \n",l);
      //printf("uint64_t l signed version: %ls \n",l);
      l += c - '0';
      printf("uint64_t l: += %c = %lu \n",c, l);
      //printf("uint64_t l signed version: %ls \n",l);
      c = getchar();
    }
    while(c != '\n')
      c = getchar();
    return l;
}

int main(int argc, char *argv[]) {
  //cash = ULONG_MAX;
  //uint64_t l = LONG_MAX;
  //bit too diffcult to print out max value of uint64_t
  //printf("%lu \n",ULONG_MAX); //outputs 4294967295
  printf("%lu \n",LONG_MAX ); //outputs 2147483647
  //printf("%li \n",cash ); //outputs -1 with long signed notation
  //printf("%lu \n",cash ); //outputs 294967295 with long unsigned notation
  //printf("%lu \n",l );

  //printf("\nsize of uint64_t: %d \n",sizeof(uint64_t));
  //printf("size of long: %d \n",sizeof(long));

  long bet = get_long();
  printf("bet unsigned version: %lu \n",bet);
  printf("bet signed version: %ls \n",bet);
  cash -= bet;
  printf("cash unsigned version %lu \n", cash);
  printf("cash signed version %ls \n", cash);
  return 0;
}
