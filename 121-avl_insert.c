#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *tmp, *second;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	tmp = *tree;
	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else
		{
			free(new_node);
			return (NULL);
		}
	}

	if (value < second->n)
		second->left = new_node;
	else
		second->right = new_node;

	new_node->parent = second;
	return (new_node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert
 *
 * Return: A pointer to the created node, NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *node, *new_node;

	if (!tree)
		return (NULL);

	new_node = bst_insert(tree, value);
	if (!new_node)
		return (NULL);

	balance = binary_tree_balance(*tree);
	node = new_node;

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
