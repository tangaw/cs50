#include <stdio.h>

// sizeof () returns the number of BYTES
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))   // #define used to parameterize into a macro

int main(void)
{
  int numbers[] = {4, 6, 8, 2, 7, 5, 0};

  for (int i=0, n=NELEMS(numbers); i<n; i++) {
    if (numbers[i] == 0) {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
  // printf("%li\n", NELEMS(numbers));
}