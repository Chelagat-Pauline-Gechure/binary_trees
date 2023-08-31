#include "binary_trees.h"

/**
 * binary_tree_delete - deletes the entire tree
 * @tree: Pointer to the root node of the tree to insert
 *
 * Return: Nothing
*/

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}