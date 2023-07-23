#include "sort.h"
/**
 * swap - allows two int variables to switch values with one another.
 * @num1: first integer
 * @num2: second integer
 * Return: void
 */
void swap(int *num1, int *num2)
{
int tmp;
tmp = *num1;
*num1 = *num2;
*num2 = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: int arrays to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int swapped;
for (i = 0; i < size; i++)
{
swapped = 0;
for (j = 0; j < (size - 1 - i); j++)
{
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);
print_array(array, size);
swapped = 1;
}
}
if (!swapped)
{
break;
}
}
}
