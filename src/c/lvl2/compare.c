#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *s = "Aaron";
  char *t = "Aaron";

  // If using (s == t), the boolean will be False since they are pointing to different addresses
  if (strcmp(s, t) == 0) {
    printf("Same\n");
  }
  else {
    printf("Different\n");
  }
}
