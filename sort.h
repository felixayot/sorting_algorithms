#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *num1, int *num2);
void bubble_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void recursive_qs(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_swap(int *array, int num1, int num2);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void *_calloc(size_t nmemb, size_t size);
void counting_sort(int *array, size_t size);
void top_down_ms(int *array, int *tmp, int top, int mid, int down);
void recursive_ms(int *array, int *tmp, int top, int down);
void merge_sort(int *array, size_t size);
void floyd_siftdown(int *array, size_t size, int idx, size_t n);
void heap_sort(int *array, size_t size);
int getmax(int *array, int length);
void lsd_sort(int *array, size_t size, int exp, int *output);
void radix_sort(int *array, size_t size);
void ordered_swap(int array[], int num1, int num2, int order);
void merge(int array[], int low, int n, int order);
void bitonic_mergesort(int array[], int low, int n, int order, int size);
void bitonic_sort(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* _SORT_H_ */
