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
 * top_down_ms - merges sub-arrays to produce a sorted list
 * using the Top-down implementation.
 * @array: array to be merged
 * @tmp: temporary array used in merge
 * @top: first element position
 * @mid: middle of the array
 * @down: last element position
 * Return: void
 **/
void top_down_ms(int *array, int *tmp, int top, int mid, int down)
{
int size_left = mid - top + 1, size_right = down - mid;
int *array_left, *array_right;
int left, right, i = 0;
array_left = &tmp[0];
array_right = &tmp[size_right];
for (left = 0; left < size_left; left++)
array_left[left] = array[top + left];
for (right = 0; right < size_right; right++)
array_right[right] = array[mid + 1 + right];
left = 0, right = 0, i = top;
while (left < size_left && right < size_right)
{
if (array_left[left] <= array_right[right])
array[i] = array_left[left], left++;
else
array[i] = array_right[right], right++;
i++;
}
while (left < size_left)
array[i] = array_left[left], left++, i++;
while (right < size_right)
array[i] = array_right[right], right++, i++;
printf("Merging...\n");
printf("[left]: ");
print_array(array_left, left);
printf("[right]: ");
print_array(array_right, right);
printf("[Done]: ");
print_array(&array[top], left + right);
}

/**
 * recursive_ms - sorts an array using recursive merge sort.
 * @array: array to be sorted
 * @tmp: temporary array used in merge.
 * @top: fisrt element position.
 * @down: last element position.
 * Return: void
 */
void recursive_ms(int *array, int *tmp, int top, int down)
{
int mid;
mid = (top + down) / 2;
if ((top + down) % 2 == 0)
mid--;
if (mid >= top)
{
recursive_ms(array, tmp, top, mid);
recursive_ms(array, tmp, mid + 1, down);
top_down_ms(array, tmp, top, mid, down);
}
}

/**
 * merge_sort - summary mergesort that sorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
int *tmp;
if (!array || size < 2)
return;
tmp = _calloc(size, sizeof(int));
recursive_ms(array, tmp, 0, size - 1);
free(tmp);
}
