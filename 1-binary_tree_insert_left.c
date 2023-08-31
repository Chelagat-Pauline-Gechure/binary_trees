#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node.
 * @parent: Pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created binary tree node or NULL on failure or if
 *         parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    /*Create a new binary tree node*/
    binary_tree_t *new_left_child;

    /* Check if the parent is NULL (cannot insert into a NULL parent)*/
    if (!parent)
        return (NULL);

    /*Allocate memory for the new node */
    new_left_child = malloc(sizeof(binary_tree_t));
    if (!new_left_child)
        return (NULL); /*Return NULL on memory allocation failure*/

    /*Assign the value to the new node*/
    new_left_child->n = value;

    /* Set parent and child pointers*/
    new_left_child->parent = parent;
    new_left_child->right = NULL;
    new_left_child->left = parent->left;

    // Update parent's left child pointer to point to the new_left_child node
    parent->left = new_left_child;

    // If the new node's left child is not NULL, update its parent pointer
    if (new_left_child->left)
        new_left_child->left->parent = new_left_child;

    // Return the pointer to the new_left_child node
    return (new);
}
