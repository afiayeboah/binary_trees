#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root node of the heap.
 * @size: Address to store the size of the array.
 * Return: Pointer to the sorted array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (heap == NULL || size == NULL)
		return (NULL);

	size_t heap_size = binary_tree_size(heap);

	if (heap_size == 0)
		return (NULL);

	int *sorted_array = malloc(sizeof(int) * heap_size);

	if (sorted_array == NULL)
		return (NULL);

	*size = heap_size;

	for (size_t i = 0; i < heap_size; ++i)
	{
		sorted_array[i] = heap->n;
		heap_extract(&heap);
	}

	return (sorted_array);
}
