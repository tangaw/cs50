#include <stdio.h>
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

typedef struct
{
  char name;
  int number;
} subject;

int main(void)
{
  subject subjects[2];

  subjects[0].name = 'A';
  subjects[1].number = 1;

  subjects[1].name = 'B';
  subjects[1].number = 2;

  for (int i=0, n=NELEMS(subjects); i<n; i++) {
    printf("Name: %c, Number: %i\n", subjects[i].name, subjects[i].number);
  }
  return 0;
}
