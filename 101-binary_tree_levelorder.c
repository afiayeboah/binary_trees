#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree 
 * sing level-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	size_t level;
	size_t max_level = binary_tree_height(tree) + 1;

	for (level = 1; level <= max_level; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - Helper function to traverse a level of the binary tree.
 * @tree: A pointer to the current node.
 * @func: A pointer to a function to call for each node.
 * @level: The level of the tree to traverse.
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t height_left = binary_tree_height(tree->left);
	size_t height_right = binary_tree_height(tree->right);

	return (height_left > height_right ? height_left + 1 : height_right + 1);
}
