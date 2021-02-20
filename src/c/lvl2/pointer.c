#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *x;   // Create pointer
  int *y;

  x = malloc(sizeof(int));    // Initialize and allocate memory for int

  *x = 42;    // Dereference pointer and store value

  printf("%i\n", *x);
}