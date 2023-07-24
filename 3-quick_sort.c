#include "sort.h"
/**
 * swap - allows two int variables to switch values with one another.
 * @num1: first int
 * @num2: second int
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
 * lomuto_partition - partition an array into two parts using
 * Lomuto Partition Scheme
 * @array: array to be partitioned
 * @low: first array element
 * @high: last array element
 * @size: size of the array
 * Return: the position(index) of the chosen pivot of the array
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int i, j, pivot_val;
pivot_val = array[high];
i = low;
for (j = low; j < high; j++)
{
if (array[j] <= pivot_val)
{
swap(&array[i], &array[j]);
print_array(array, size);
i++;
}
}
swap(&array[i], &array[high]);
print_array(array, size);
return (i);
}

/**
 * recursive_qs - qucksort algorithm implementation using recursion
 * @array: array to be sorted
 * @low: first array element
 * @high: last array element
 * @size: size of the array
 * Return: void
 */
void recursive_qs(int *array, int low, int high, size_t size)
{
int pivot_point;
if (low < high)
{
pivot_point = lomuto_partition(array, low, high, size);
recursive_qs(array, low, pivot_point - 1, size);
recursive_qs(array, pivot_point + 1, high, size);
}
}

/**
 * quick_sort - summary quicksort of an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of the ints
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
recursive_qs(array, 0, size - 1, size);
}
