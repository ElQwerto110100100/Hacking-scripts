#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

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

int main(int argc, char *argv[]) {
  long cash = ULONG_MAX;
  uint64_t l = LONG_MAX;
  printf("%lu \n",ULONG_MAX);
  printf("%lu \n",LONG_MAX );
  printf("%lu \n",cash );
  printf("%lu \n",l );

  

  return 0;
}
