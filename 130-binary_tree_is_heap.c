#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - Checks if the node's value is greater than the values of its children.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the node's value is greater than its children's values, 0 otherwise.
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_max(tree->left);
	}

	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}

	return (tmp1 && tmp2);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max binary heap.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a max binary heap, 0 otherwise.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);

	return (check_max(tree));
}
