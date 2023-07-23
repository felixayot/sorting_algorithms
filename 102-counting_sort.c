#include "sort.h"
/**
 * _calloc - allocates memory for an array of
 * nmemb elements of size bytes each.
 * @nmemb: number of elements
 * @size: bite size of each element
 * Return: pointer to allocated memory
 */
void *_calloc(size_t nmemb, size_t size)
{
size_t i = 0;
char *ptr;
if (nmemb == 0 || size == 0)
return (NULL);
ptr = malloc(nmemb * size);
if (ptr == NULL)
return (NULL);
for (i = 0; i < (nmemb * size); i++)
ptr[i] = '\0';
return (ptr);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
int index, max_val = 0, *counter = '\0', *tmp = '\0';
size_t i;
if (array == NULL || size < 2)
return;
/* Find max value */
for (i = 0; i < size; i++)
if (array[i] > max_val)
max_val = array[i];
counter = _calloc(max_val + 1, sizeof(int));
tmp = _calloc(size + 1, sizeof(int));
/* Count the array elements */
for (i = 0; i < size; i++)
counter[array[i]]++;
/* Get the cumulative values */
for (index = 1; index <= max_val; index++)
counter[index] += counter[index - 1];
print_array(counter, max_val + 1);
/* Get the new sorted array */
for (i = 0; i < size; ++i)
{
tmp[counter[array[i]] - 1] = array[i];
counter[array[i]]--;
}
/* Replace old array to sorted new array */
for (i = 0; i < size; i++)
array[i] = tmp[i];
free(tmp);
free(counter);
}
