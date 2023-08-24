#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "stdtypes.h"
#include <stdio.h>
#define STACK_DEBUG
#define MAX_ELEMENTS 5

typedef struct {
  uint32_t stack_array[MAX_ELEMENTS];
  sint32_t stack_pointer;
}stack_t;

typedef enum {
  STACK_FULL,
  STACK_EMPTY,
  STACK_NOT_FULL,
  STACK_NOT_EMPTY
}stack_status_t;

/* Basic operations */

/*
 * @brief : Add an element to the stack
 * @param : the stack, and the element we want to Add
 * @retval : standard error
 * */
retStatus_t stack_push(stack_t *stack, uint32_t value);

/*
 * @brief : pop an element to the stack.
 * @param : the stack, pointer to store the popped element.
 * @retval : standard error.
 * */
retStatus_t stack_pop(stack_t *stack, uint32_t *value);

/*
 * @brief : returns the element at the top of the stack.
 * @param : the stack, pointer to store the top element.
 * @retval : standard error.
 * */
retStatus_t stack_top(stack_t *stack, uint32_t *value);

/* Helper functions */

/*
 * @brief : Check if the stack is full
 * @param : The stack
 * @retval : stack status type
 */
static stack_status_t stack_full(stack_t *stack);

/*
 * @brief : Check if the stack is empty.
 * @param : The stack.
 * @retval : stack status type.
 */
static stack_status_t stack_empty(stack_t *stack);

/*
 * @brief : initialize the stack, and set the stack pointer to -1
 * @param : the stack
 * @retval : error return
 */
retStatus_t stack_init(stack_t *stack);

/*
 * @brief : Returns how many element in the stack currently.
 * @param : the stack, pointer to the value we want to store the size in.
 * @retval : error return.
 */
retStatus_t stack_size(stack_t *stack, uint32_t *value);

/*
 * @brief : Displays the elements of the stack.
 * @param : the stack.
 * @retval : error return.
 */
retStatus_t stack_display(stack_t *stack);

#endif /* ifndef _STACK_DS_H */
