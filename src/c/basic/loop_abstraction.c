#include <stdio.h>

// Prototypes
// A way of hinting at the existence of the following functions to avoid errors
void hi(int n);
int get_positive_integer(void);


int main(void)
{
  int k = get_positive_integer();
  hi(k);
}


void hi(int n)
{
  // for-loop
  for (int i=0; i<n; i++) {
    printf("Hello\n");
  }
}

int get_positive_integer(void)
{
  // Initialize n outside of loop for scope
  int n;
  
  // do-while loop is the same as a while loop except it runs the loop once before checking the condition
  do {
    printf("Enter positive integer: ");
    scanf("%i", &n);
  }
  while (n<1);
  return n;
}