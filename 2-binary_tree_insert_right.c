#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description - If parent already has a right-child, the new node must
 *				take its place, and the old right-child must be set as
 *				the right-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/*Create a new binary tree node*/
	binary_tree_t *new_right_child;

	/* Check if the parent is NULL (cannot insert into a NULL parent) */
	if (!parent)
		return (NULL);

	/* Allocate memory for the new left node */
	new_right_child = malloc(sizeof(binary_tree_t));
	if (!new_right_child)
		/* Return NULL on memory allocation failure */
		return (NULL);

	/* Assign the value to the new node */
	new_right_child->n = value;

	/* Set parent and child pointers */
	new_right_child->parent = parent;
	new_right_child->left = NULL;
	new_right_child->right = parent->right;

	/* Update parent's right child pointer to point to the new node */
	parent->right = new_right_child;

	/* If the new node's right child is not NULL, update its parent pointer */
	if (new_right_child->right)
		new_right_child->right->parent = new_right_child;

	/* Return the pointer to the new node */
	return (new_right_child);
}
