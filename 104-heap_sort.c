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
 * floyd_siftdown - implements the sift-down heap sort algorithm
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array to be sorted
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 * Return: void
 */
void floyd_siftdown(int *array, size_t size, int idx, size_t n)
{
int largest = idx;
int left = 2 * idx + 1;
int right = 2 * idx + 2;
if (left < (int)n && array[left] > array[largest])
largest = left;
if (right < (int)n && array[right] > array[largest])
largest = right;
if (largest != idx)
{
swap(&array[idx], &array[largest]);
print_array(array, size);
floyd_siftdown(array, size, largest, n);
}
}

/**
 * heap_sort -  sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
int i;
for (i = (size - 2) / 2; i >= 0; --i)
floyd_siftdown(array, size, i, size);
for (i = (size - 1); i > 0; --i)
{
swap(&array[0], &array[i]);
print_array(array, size);
floyd_siftdown(array, size, 0, i);
}
}
