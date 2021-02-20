#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
  int x = 1;
  int y = 2;

  printf("x is: %i, y is: %i\n", x, y);
  
  swap(&x, &y);

  printf("x is: %i, y is: %i\n", x, y);


}

void swap(int *p, int *q) {   // Create function that accesses addresses to swap instead of creating copies
  int temp = *p;
  *p = *q;
  *q = temp;
}
