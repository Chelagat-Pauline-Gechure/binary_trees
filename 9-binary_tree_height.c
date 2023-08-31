#include "binary_trees.h"

/**
 * count_height - Recursively measures the height of a binary tree
 * @tree: A pointer to a tree node
 * @height: The current height of the tree being traversed
 * @max: A pointer to the maximum height found so far
 * Return:  the height
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int right_counter = 0, left_counter = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_counter = binary_tree_height(tree->left);
	right_counter = binary_tree_height(tree->right);
	if (left_counter > right_counter)
		return (left_counter + 1);
	else
		return (right_counter + 1);
}
