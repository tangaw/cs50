#include <stdio.h>

int get_size(void);
int get_num(int i);
float average(int length, int array[]);

int main(void)
{
  int size;
  size = get_size();
  int nums[size];

  for (int i=0; i<size; i++) {
    nums[i] = get_num(i+1);
  }

  printf("The average is: %f\n", average(size, nums));
}

int get_size(void)
{
  int size;
  printf("Enter the amount of numbers to compute with: ");
  scanf("%i", &size);
  return size;
}

int get_num(int i)
{
  int num;
  printf("Enter number %i: ", i);
  scanf("%i", &num);
  return num;
}

float average(int length, int array[])
{
  int sum = 0;  // If not assigned a value of 0, sum will start from a random number and increment from there
  for (int i=0; i<length; i++) {
    sum += array[i];
  }
  return sum / (float) length;
}