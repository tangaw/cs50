#include <stdio.h>

int main(void)
{
  int n = 50;
  int *p = &n;    // Creating pointer variable that stores the position of n in memory
  printf("%p\n", p);  // Position of n
  printf("%i\n", *p); // Value at pointer p

  char *s = "HI!";
  printf("%s\n", s);
  printf("%c\n", *(s+1));
}