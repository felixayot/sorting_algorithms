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
 * hoare_partition - partition an array into two parts using
 * Hoare Partition Scheme
 * @array: array to be partitioned
 * @low: first array element
 * @high: last array element
 * @size: size of the array
 * Return: the position of the last element sorted
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
int i = low - 1;
int j = high + 1;
int pivot_point = array[(int)floor((high - low) / 2) + low];
while (1)
{

do {
i = i + 1;
} while (array[i] < pivot_point);
do {
j--;
} while (array[j] > pivot_point);
if (i >= j)
return (j);
swap(&array[i], &array[j]);
print_array(array, size);
}
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
int pivot_point = 0;
if (low < high)
{
pivot_point = hoare_partition(array, low, high, size);
recursive_qs(array, low, pivot_point - 1, size);
recursive_qs(array, pivot_point + 1, high, size);
}
}

/**
 * quick_sort_hoare - summary quicksort of an array of integers
 * in ascending order
 * using the Quick sort algorithm
 * @array: array of the ints
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
recursive_qs(array, 0, size - 1, size);
}
