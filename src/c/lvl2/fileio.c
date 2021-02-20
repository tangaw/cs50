#include <stdio.h>

int main(void)
{
  FILE *file = fopen("phonebook.csv", "a"); // Opening file in 'append' mode

  char *name = "Aaron";
  char *number = "123-456-9870";

  fprintf(file, "%s, %s", name, number);  // Appending a row of data to file
  fclose(file); // Close file
}