#include "binary_trees.h"


/**
 * binary_tree_node - create new binary tree node.
 *
 * @parent: Pointer to parent node of the new node being created.
 * @value: Integer value to assign to the new node being created.
 *
 * Return: Pointer to created binary tree node or NULL in case of failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    
    if (new_node == NULL) 
    {
        return NULL; // Return NULL on failure to allocate memory
    }

    new_node->parent = parent;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
