#include <stdio.h>

int main(void)
{
  char s[3];
  int i;

  printf("Enter x: ");
  scanf("%s", s); // Doesn't need dereferencer * since s itself is already a pointer

  printf("x is %s\n", s);
}