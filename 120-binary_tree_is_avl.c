#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

int is_avl_tree(const binary_tree_t *tree, int min, int max);
size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_tree(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_tree - Helper function to check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_tree(tree->left, min, tree->n - 1) &&
		is_avl_tree(tree->right, tree->n + 1, max));
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 *         -1 if the tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (-1);

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
