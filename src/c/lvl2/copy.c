#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char *s = "hi!";
  char *t = malloc(strlen(s) + 1);  // Allocating memory for t since `char *t = s` will simply make t point to the same address as s

  strcpy(t, s);

  *t = toupper(*t); // Equivalent to t[0] = toupper(t[0]);

  printf("%s\n", s);
  printf("%s\n", t);

  free(t);  // Return allocated memory
}