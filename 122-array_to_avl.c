#include "binary_trees.h"

/**
 * array_to_avl - Function that builds an AVL tree from an array
 * @array: Array to create from
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created otherwise, NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
