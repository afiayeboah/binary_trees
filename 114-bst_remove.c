#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the
 * tree where the node will be removed.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		bst_t *temp;

		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}

		temp = bst_min_val(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return root;
}

/**
 * bst_min_val - Finds the node with the minimum value in a BST.
 * @root: A pointer to the root node of the tree.
 *
 * Return: A pointer to the node with the minimum value.
 */
bst_t *bst_min_val(bst_t *root)
{
	if (root == NULL)
		return NULL;

	while (root->left != NULL)
		root = root->left;

	return root;
}
