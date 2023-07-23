#include "sort.h"
#include <stdio.h>
/**
* getmax - gets maximum value in an array
* @array: array
* @length: size of the array
* Return: array
*/
int getmax(int *array, int length)
{
int i, max = array[0];
for (i = 1; i < length; i++)
if (array[i] > max)
max = array[i];
return (max);
}

/**
* lsd_sort - radix sort function that implements
* the least significant digit(LSD).
* @array: array to be sorted
* @size: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void lsd_sort(int *array, size_t size, int exp, int *output)
{
int i;
int count[10] = {0};
for (i = 0; i < (int)size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < (int)size; i++)
array[i] = output[i];
}

/**
* radix_sort - sorts an array of integers in ascending order
* using the Radix sort algorithm.
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
int exp, maximum = 0;
int *output = NULL;
if (array == NULL || size < 2)
return;
maximum = getmax(array, size);
output = malloc(size * sizeof(int));
if (output == NULL)
return;
for (exp = 1; maximum / exp > 0; exp *= 10)
{
lsd_sort(array, size, exp, output);
print_array(array, size);
}
free(output);
}
