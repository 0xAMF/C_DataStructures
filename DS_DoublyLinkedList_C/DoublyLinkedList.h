#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DLL_DEBUG

typedef struct node {
    uint32_t data;
    struct node *next;
    struct node *prev;
} node_t;

typedef enum {
    OK,
    NOK,
} return_status_t;

/*
 * @brief : insert a node anywhere in the list.
 * @param : double pointer to the list, the index.
 * @retval: return status type.
 */
return_status_t insert_node(node_t **list, uint32_t index);

/*
 * @brief : insert a node at the head of the list. 
 * @param : double pointer to the list.
 * @retval: return status type.
 */
return_status_t insert_beginning(node_t **list);

/*
 * @brief : insert a node at the end of the list. 
 * @param : double pointer to the list.
 * @retval: return status type.
 */
return_status_t append_node(node_t **list);

/*
 * @brief : remove a node anywhere in the list.
 * @param : double pointer to the list, the index of the node we want to remove.
 * @retval: return status type.
 */
return_status_t remove_node(node_t **list, uint32_t index); 

/*
 * @brief : remove the head node.
 * @param : double pointer to the list.
 * @retval: return status type.
 */
return_status_t remove_beginning(node_t **list);

/*
 * @brief : remove the rear node.
 * @param : double pointer to the list.
 * @retval: return status type.
 */
return_status_t remove_end(node_t **list);

/*
 * @brief : Display the elements of the list in forward.
 * @param : single pointer to the list.
 * @retval: return status type.
 */
return_status_t display_forward(node_t *list);

/*
 * @brief : Display the elements of the list in reverse.
 * @param : single pointer to the list.
 * @retval: return status type.
 */
return_status_t display_reverse(node_t *list);

/*
 * @brief : Calculate the length of the list.
 * @param : single pointer to the list.
 * @retval: The length of the list as a 32-bit integer.
 */
uint32_t getLength(node_t *list);

#endif
