#include "stack_ds.h"
#include "stdtypes.h"
#include <stdio.h>

stack_t mystack;
uint32_t stackpop;

int main()
{
  retStatus_t ret = NOK;
  ret = stack_init(&mystack);
  if (NOK == ret) {
    printf("Failed to initialize stack!!!!\n");
  }
  else {
    printf("Stack has been initialized!!\n");
    ret = stack_push(&mystack, 11);
    ret = stack_push(&mystack, 22);
    ret = stack_push(&mystack, 33);
    ret = stack_push(&mystack, 44);
    ret = stack_push(&mystack, 55);
    ret = stack_top(&mystack, &stackpop);
    ret = stack_size(&mystack, &stackpop);

    ret = stack_display(&mystack);
  }
}
