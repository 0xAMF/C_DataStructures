#include "Queue_Ds.h"
#include <stdint.h>
#include <stdio.h>

queue_t myQueue;
QueueStatus ret;
uint32_t element;
uint32_t *test;
uint32_t size;
uint8_t counter;
uint32_t front;
uint32_t rear;

int main()
{
  int dq;

  printf("Enter the size of the queue: ");
  scanf("%i", &size);

  ret = Q_init(&myQueue, size);

  if (ret == Q_NOK) {
    printf("Failed To Initialize Queue\n");
  }
  else {
    printf("Queue Initialized Successfully!!\n");
  }

  element = 33;
  enqueue(&myQueue, &element);

  counter = 20;
  enqueue(&myQueue, &counter);

  int newElement = 12;
  enqueue(&myQueue, &newElement);

  int nlm = 123;
  enqueue(&myQueue, &nlm);

  int _555 = 555;
  enqueue(&myQueue, &_555);

  int _666 = 666;
  enqueue(&myQueue, &_666);

  int _777 = 777;
  enqueue(&myQueue, &_777);

  dequeue(&myQueue, &dq);

  dequeue(&myQueue, &dq);

  int _888 = 888;
  enqueue(&myQueue, &_888);

  int _999 = 999;
  enqueue(&myQueue, &_999);

  dequeue(&myQueue, &dq);


  dequeue(&myQueue, &dq);

  int testst = 69;
  enqueue(&myQueue, &testst);

  getFront(&myQueue, &front);
  printf("front = %i\n", front);

  getRear(&myQueue, &rear);
  printf("rear = %i\n", rear);

 return 0;
}
