#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_child;

	if (!parent)
		return (NULL);

	new_left_child = malloc(sizeof(binary_tree_t));
	if (!new_left_child)
		return (NULL);

	new_left_child->n = value;
	new_left_child->parent = parent;
	new_left_child->right = NULL;
	new_left_child->left = parent->left;
	parent->left = new_left_child;
	if (new_left_child->left)
		new_left_child->left->parent = new_left_child;
	return (new_left_child);
}
