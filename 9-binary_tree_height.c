#include "binary_trees.h"

/**
 * count_height - Recursively measures the height of a binary tree
 * @tree: A pointer to a tree node
 * @height: The current height of the tree being traversed
 * @max: A pointer to the maximum height found so far
 * Return:  the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int counter_right = 0, counter_left = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	counter_left = binary_tree_height(tree->left);
	counter_right = binary_tree_height(tree->right);
	if (counter_left > counter_right)
		return (counter_left + 1);
	else
		return (counter_right + 1);
}
