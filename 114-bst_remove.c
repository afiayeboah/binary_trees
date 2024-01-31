#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the
 * tree after removal, or NULL
 *         on failure.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_find_min(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * bst_find_min - Finds the smallest node in a Binary Search Tree.
 * @root: A pointer to the root node of the tree.
 *
 * Return: A pointer to the smallest node.
 */
bst_t *bst_find_min(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}
