#include "binary_trees.h"

/**
 * binary_tree_node - creates a custom binary tree node
 * @parent: pointer to the parent node of the new node
 * @value: value to be stored in the new node
 * Return: Pointer to the newly created node
 *          NULL if memory allocation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
