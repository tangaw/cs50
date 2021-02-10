#include <stdio.h>

int main(void)
{
  int x;
  int y;

  printf("Enter x: ");
  scanf("%i", &x);
  printf("Enter y: ");
  scanf("%i", &y);

  float z = (float) x / (float) y; // Type casting integers x and y
  printf("x divided by y is: %f\n", z);
}