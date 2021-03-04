#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Hint at "node" so that it is able to be used to declare property *next
  int number;
  struct node *next;
} node;

int main(void)
{
  /* Create list of size 3 using malloc, storing and printing values */
  int *list = malloc(3*sizeof(int));  // malloc uses the heap, square bracket notation uses the stack

  if (list == NULL) { // Check to see if address is valid, and abort if not
    free(list);
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  for (int i=0; i < 3; i++) {
    printf("%i\n", list[i]);
  }

  /* Add 1 new element to list by creating a copy with size+1 */
  int *tmp = realloc(list, 4*sizeof(int));  // Use realloc to copy the contents of the original array and increase size by 1

  if (tmp == NULL) {
    free(list);
    free(tmp);
    return 1;
  }

  tmp[3] = 4;

  free(list);
  list = tmp; // Point original list to new temp array

  for (int i=0; i < 4; i++) {
    printf("%i\n", list[i]);
  }

  free(list);
}