#include <stdio.h>

int main(void)
{
  int x;
  int y;
  printf("Enter value for x: ");
  scanf("%i", &x);  // Scan for input and store the value in x
  printf("Enter value for y: ");
  scanf("%i", &y);
  printf("The sum is: %i\n", x+y);
}