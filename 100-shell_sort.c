#include "sort.h"
/**
 * shell_swap - allows two ints in an array to switch values with one another.
 * @array: array of ints
 * @num1: first integer
 * @num2: second integer
 * Return: void
 */
void shell_swap(int *array, int num1, int num2)
{

int tmp;
tmp = array[num1];
array[num1] = array[num2];
array[num2] = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm and the Knuth sequence implementation.
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j = 0;
if (array == NULL || size < 2)
return;
while (gap < size / 3)
gap = 3 * gap + 1;
while (gap >= 1)
{
for (i = gap; i < size; i++)
for (j = i; j >= gap &&
(array[j] < array[j - gap]); j -= gap)
shell_swap(array, j, j - gap);
print_array(array, size);
gap /= 3;
}
}
