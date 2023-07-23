#include "sort.h"
/**
 * ordered_swap - change two values in ascending or descending order
 * @array: array
 * @num1: first int
 * @num2: second int
 * @order: order of the numbers in the array
 * Return: void
 */
void ordered_swap(int array[], int num1, int num2, int order)
{
int tmp;
if (order == (array[num1] > array[num2]))
{
tmp = array[num1];
array[num1] = array[num2];
array[num2] = tmp;
}
}

/**
 * merge - sort bitonic sequences recursively in both orders
 * @array: array to be merged
 * @low: first element
 * @n: number of elements
 * @order: order of the numbers in the array
 * Return: void
 */
void merge(int array[], int low, int n, int order)
{
int mid, i;

if (n > 1)
{
mid = n / 2;
for (i = low; i < low + mid; i++)
ordered_swap(array, i, i + mid, order);
merge(array, low, mid, order);
merge(array, low + mid, mid, order);
}
}

/**
 * bitonic_mergesort - implements bitonic mergesort algorithm.
 * @array: array to be sorted
 * @low: first element
 * @n: number of elements
 * @order: order of the numbers in the array
 * @size: size of the array
 * Return: void
 */
void bitonic_mergesort(int array[], int low, int n, int order, int size)
{
int mid;

if (n > 1)
{
if (order >= 1)
{
printf("Merging [%i/%i] (UP):\n", n, size);
print_array(&array[low], n);
}
else
{
printf("Merging [%i/%i] (DOWN):\n", n, size);
print_array(&array[low], n);
}
mid = n / 2;
bitonic_mergesort(array, low, mid, 1, size);
bitonic_mergesort(array, low + mid, mid, 0, size);
merge(array, low, n, order);
if (order <= 0)
{
printf("Result [%i/%i] (DOWN):\n", n, size);
print_array(&array[low], n);
}
if (order >= 1)
{
printf("Result [%i/%i] (UP):\n", n, size);
print_array(&array[low], n);
}
}
}

/**
 * bitonic_sort - summary sort of an array of integers in
 * ascending order using the Bitonic sort algorithm.
 * @array: array
 * @size: array lenght
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
int order = 1;
bitonic_mergesort(array, 0, size, order, size);
}
