#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #define LL_DEBUG

/* Structure of the node */
typedef struct node {
  uint32_t data;
  struct node *next;
} node_t;

typedef enum {
  OK,   /* Indicates no error */
  NOK,  /* Indicates an error */
  EMPTY /* Indicates empty list */
} return_status_t;

/* Insert functions section */

/*
 * @brief  : Insert an element anywhere in the list.
 * @param  : Double pointer to the list.
 * @retval : return status enumeration.
 */
return_status_t insert_node(node_t **list, uint32_t index);

/*
 * @brief  : Insert and element at the beginning of the function
 * @param  : Double pointer to a list.
 * @retval : return status enumeration.
 */
static return_status_t insert_beginning(node_t **list);

/*
 * @brief  : Insert and element at the end of the function
 * @param  : Double pointer to a list.
 * @retval : return status enumeration.
 */
return_status_t append_node(node_t **list);

/* Remove functions sections */

/*
 * @brief  : Remove a functions eveywhere in the list.
 * @param  : Double pointer to the list.
 * @retval : return status enumeration.
 */
return_status_t remove_node(node_t **list, uint32_t index);

/*
 * @brief  : Remove an element from the beginning.
 * @param  : Double pointer to a list.
 * @retval : return status enumeration.
 */
static return_status_t remove_beginning(node_t **list);

/*
 * @brief  : Insert and element at the end of the function
 * @param  : Double pointer to a list.
 * @retval : return status enumeration.
 */
static return_status_t remove_end(node_t **list);

/*
 * @brief  : Displays the lists elements.
 * @param  : pointer to the list.
 * @retval : error return status.
 */
return_status_t display_list(node_t *list);

/* 
 * @brief  : Retrieve an element from the list.
 * @param  : Pointer to the list, index of the element.
 * @retval : void pointer to the element. 
 */
uint32_t retrieve(node_t *list, uint32_t index);

/*
 * @brief  : Calculate the length of the list. 
 * @param  : Pointer to the list.
 * @retval : the length of the list. 
 */
uint32_t getLength(node_t *list);

#endif
