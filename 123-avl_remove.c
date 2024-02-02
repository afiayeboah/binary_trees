#include "binary_trees.h"

/**
 * bal - Measures balance factor of an AVL tree.
 * @tree: Pointer to the tree to calculate balance factor.
 *
 * Return: Balanced factor.
 */
void bal(avl_t **tree)
{
    int bval;

    if (tree == NULL || *tree == NULL)
        return;

    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;

    bal(&(*tree)->left);
    bal(&(*tree)->right);

    bval = binary_tree_balance((const binary_tree_t *)*tree);

    if (bval > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (bval < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Root of the tree.
 * @value: Value of the node to remove.
 *
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return NULL;

    if (value < root->n)
        bst_remove(root->left, value);
    else if (value > root->n)
        bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_type(root);
        if (type != 0)
            bst_remove(root->right, type);
    }
    else
        return NULL;

    return root;
}

/**
 * avl_remove - Function that removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: the value to remove
 * Return: Pointer to the new root otherwise, NULL on failure
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
    return (root_a);
}
