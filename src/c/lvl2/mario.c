#include <stdio.h>

void draw(int n);

int main(void)
{
  int x = 4;

  draw(x);
}

void draw(int n) {
  if (n > 1) {
    draw(n -1);
  }

  for (int i = 0; i < n; i++) {
    printf("#");
  }
  printf("\n");
}