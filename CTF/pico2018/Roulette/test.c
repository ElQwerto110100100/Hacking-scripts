#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

int is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main(int argc, char *argv[]) {
  long cash = ULONG_MAX;
  printf("%lu \n",ULONG_MAX );
  printf("%lu \n",LONG_MAX );
  printf("%lu \n",cash );
  return 0;
}
