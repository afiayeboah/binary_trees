#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree or 0 if tree is NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = tree_height(tree->left);
    size_t right_height = tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_height(const binary_tree_t *tree)
{
	if (tree == NULL)
        return 0;

    size_t left_height = tree_size_height(tree->left);
    size_t right_height = tree_size_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * _preorder - Goes through a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Will be the last node in the traversal.
 * @height: Height of the tree.
 *
 * Return: No Return.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
    if (tree == NULL || height == 0)
        return;

    if (height == 1)
    {
        *node = tree;
        return;
    }

    _preorder(tree->left, node, height - 1);
    _preorder(tree->right, node, height - 1);
}

/**
 * heapify - Heapifies a max binary heap.
 * @root: Pointer to the root of the binary heap.
 *
 * Return: No Return.
 */
void heapify(heap_t *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left != NULL && left->n > largest->n)
        largest = left;

    if (right != NULL && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        int temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify(largest);
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Pointer to the heap root.
 * Return: Value of the extracted node.
 **/
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int value = (*root)->n;
    size_t height = tree_height(*root);
    heap_t *last_node = NULL;

    _preorder(*root, &last_node, height);

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    (*root)->n = last_node->n;
    free(last_node);

    heapify(*root);

    return value;
}
