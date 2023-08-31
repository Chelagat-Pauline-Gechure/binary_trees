#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If 'tree' is NULL, returns 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_tree = 0, right_tree = 0;

		/* Calculate the height of the left subtree */
		if (tree->left)
			left_tree = 1 + binary_tree_height(tree->left);
		/* Calculate the height of the right subtree */
		if (tree->right)
			right_tree = 1 + binary_tree_height(tree->right);

		/* Return the maximum height between left and right subtrees */
		if (left_tree > right_tree)
			return (left_tree);
		else
			return (right_tree);
	}
	else
		return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The number of nodes in the binary tree. If 'tree' is NULL, returns 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	/* Calculate the size of the left and right subtrees recursively */
	left_nodes = binary_tree_size(tree->left);
	right_nodes = binary_tree_size(tree->right);

	/* Return the total size of the binary tree.*/
	return (1 + left_nodes + right_nodes);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise. If 'tree' is NULL, returns 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the binary tree */
	tree_height = binary_tree_height(tree);

	/* Calculate the perfect size of the binary tree using 2^(height + 1) - 1 formula */
	perfect_size = (1 << (tree_height + 1)) - 1;

	/* Check if the size of the binary tree matches the perfect size to determine if it's perfect */
	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
