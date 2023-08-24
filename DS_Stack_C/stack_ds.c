#include "stack_ds.h"


/* Basic Functions Section */

retStatus_t stack_push(stack_t *stack, uint32_t value) {
  retStatus_t ret = OK;

  if (NULL == stack) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK NULL POINTER ERROR!!\n");
    #endif
  }
  else if (STACK_FULL == stack_full(stack)) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK FULL!!\n");
    #endif
  }
  else {
    (stack->stack_pointer)++;
    printf_s("Stack pointer -> %i\n", stack->stack_pointer);
    stack->stack_array[stack->stack_pointer] = value;
    #ifdef STACK_DEBUG
    printf("Added %i to the stack\n", value);
    #endif
  }

  return ret;
}

retStatus_t stack_pop(stack_t *stack, uint32_t *value) {
  retStatus_t ret = OK;

  if (NULL == stack || NULL == value) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK NULL POINTER ERROR!!\n");
    #endif

  }
  else if (STACK_EMPTY == stack_empty(stack)) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK EMPTY!!\n");
    #endif
  }
  else {
    *value = stack->stack_array[stack->stack_pointer];
    stack->stack_pointer--;
    #ifdef STACK_DEBUG
    printf("Popped %i from the stack!!\n", *value);
    printf("Stack pointer --> %i\n", stack->stack_pointer);
    #endif
  }

  return ret;
}

retStatus_t stack_top(stack_t *stack, uint32_t *value) {
  retStatus_t ret = OK;

  if (NULL == stack || NULL == value) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK POINTER ERROR!!\n");
    #endif
  }
  else if (STACK_EMPTY == stack_empty(stack)) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK EMPTY!!\n");
    #endif
  }
  else {
    *value = stack->stack_array[stack->stack_pointer];
    #ifdef STACK_DEBUG
    printf("%i is the top of the stack!!\n", *value);
    #endif
  }

  return ret;
}

/* Helper Functions Section */

static stack_status_t stack_full(stack_t *stack) {
  stack_status_t ret = STACK_NOT_FULL;
  uint32_t stackPtr = stack->stack_pointer;

  if (stackPtr == (MAX_ELEMENTS - 1)) {
    ret = STACK_FULL;
    #ifdef STACK_DEBUG
    printf("STACK FULL\n");
    #endif
  }

  return ret;
}

static stack_status_t stack_empty(stack_t *stack) {
  stack_status_t ret  = STACK_NOT_FULL;

  if (stack->stack_pointer == -1) {
    ret = STACK_EMPTY;
    #ifdef STACK_DEBUG
    printf("STACK EMPTY\n");
    #endif
  }

  return ret;
}

retStatus_t stack_init(stack_t *stack) {
  retStatus_t ret = NOK;

  if (NULL != stack) {
    stack->stack_pointer = -1;
    ret = OK;
  }

  return ret;
}

retStatus_t stack_size(stack_t *stack, uint32_t *value) {
  retStatus_t ret = OK;

  if ((NULL == stack) || (NULL == value)) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK NULL POINTER ERROR!!!\n");
    #endif
  }
  else {
    *value = stack->stack_pointer + 1;
  }

  return ret;
}

retStatus_t stack_display(stack_t *stack) {
  retStatus_t ret = OK;
  uint8_t i = 0;

  if (NULL == stack) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK NULL POINTER ERROR!!!\n");
    #endif
  }
  else if (STACK_EMPTY == stack_empty(stack)) {
    ret = NOK;
    #ifdef STACK_DEBUG
    printf("STACK EMPTY!!\n");
    #endif
  }
  else {
    printf("Stack Elements: ");
    for (i = 0; i <= stack->stack_pointer; i++) {
      printf("%i\t", stack->stack_array[i]);
    }
    printf("\n");
  }

  return ret;
}
