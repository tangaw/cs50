#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Hint at "node" so that it is able to be used to declare property *next
  int number;
  struct node *next;
} node;

int main(void)
{
  node *list = NULL;  // Best practice to initialize to NULL to avoid segmentation faults

  /* First Node */
  node *n = malloc(sizeof(node));

  if (n != NULL) {
    n->number = 2;  // Arrow notation replaces * and .
    n->next = NULL;
  }
  list = n; // Store the address of the first node inside list. list represents the first node

  /* Second Node */
  n = malloc(sizeof(node));

  if (n == NULL) {
    free(list);
    return 1;
  }
  n->number = 3;
  n->next = NULL;
  list->next = n; // Have the first node `list` point to the second node

  /* Third Node */
  n = malloc(sizeof(node));

  if (n == NULL) {
    free(list);
    free(n);
    return 1;
  }
  n->number = 5;
  n->next = NULL;
  list->next->next = n;

  /* Insert Node to the beginning of list */
  n = malloc(sizeof(node));

  if (n == NULL) {
    free(list);
    free(n);
    return 1;
  }
  n->number = 1;
  n->next = list; // First point the new node to the current first node
  list = n; // Then point the first node to the new node


  /* Print all Nodes */
  for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
    printf("%i\n", tmp->number);
  }

  /* Free all Nodes */
  while (list != NULL) {
    node *tmp = list->next;
    free(list);
    list = tmp;
  }


}