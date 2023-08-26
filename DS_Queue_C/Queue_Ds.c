#include "Queue_Ds.h"


/* Basic Functions */
QueueStatus enqueue(queue_t *queue, void *element) {
  QueueStatus ret = Q_OK;

  if ((NULL == queue) || (NULL == element)) {
    ret = Q_NOK;
#ifdef DEBUG_QUEUE
    printf("Null pointer error!!!\n");
#endif
  } else if (Q_FULL == isFull(queue)) {
    ret = Q_FULL;
#ifdef DEBUG_QUEUE
    printf("Queue is full!!!\n");
#endif
  } else {
    if (queue->rear == queue->MaxElements - 1) {
      /* Implement Circular Queue */
      queue->rear = 0;
    } else {
      /* Increment rear index */
      (queue->rear)++;
    }
    queue->queue[queue->rear] = element;
#ifdef DEBUG_QUEUE
    printf("Added element %i to the queue\t\trear ==> %i\n",
           *(uint32_t *)queue->queue[queue->rear], queue->rear);
#endif
    if (queue->CurrentSize == 0) {
      queue->front = 0;
      queue->CurrentSize = 1;
    } else {
      (queue->CurrentSize)++;
    }
  }

  return ret;
}

QueueStatus dequeue(queue_t *queue, void *DQ_Elmenet) {
  QueueStatus ret = Q_OK;

  if ((NULL == queue) || (NULL == DQ_Elmenet)) {
    ret = Q_NOK;
#ifdef DEBUG_QUEUE
    printf("Null pointer error!!!\n");
#endif
  } else if (Q_EMPTY == isEmpty(queue)) {
    ret = Q_EMPTY;
#ifdef DEBUG_QUEUE
    printf("Queue is Empty!!!\n");
#endif
  } else {
    DQ_Elmenet = queue->queue[queue->front];
    if (queue->front == queue->MaxElements - 1) {
      /* Implement Circular Queue */
      queue->front = 0;
      (queue->CurrentSize)--;
    } else {
      (queue->front)++;
      (queue->CurrentSize)--;
    }

#ifdef DEBUG_QUEUE
    printf("Removed element %i from the queue\tFront ==> %i\n",
           *(uint32_t *)DQ_Elmenet, queue->front);
#endif
  }

  return ret;
}

// FIX:  /* Find better way to return the front element */

QueueStatus getFront(queue_t *queue, void *StoreFront) {
  QueueStatus ret = Q_OK;
  uint32_t front = queue->front;

  if ((NULL == queue) || (NULL == StoreFront)) {
    ret = Q_NOK;
  } else if (Q_EMPTY == isEmpty(queue)) {
    ret = Q_EMPTY;
  } else {
    *(uint32_t *)StoreFront = *(uint32_t *)queue->queue[front];
  }

  return ret;
}

// FIX:  /* Find better way to return the rear element */

QueueStatus getRear(queue_t *queue, void *StoreRear) {
  QueueStatus ret = Q_OK;
  uint32_t rear = queue->rear;

  if ((NULL == queue) || (NULL == StoreRear)) {
    ret = Q_NOK;
  } else if (Q_EMPTY == isEmpty(queue)) {
    ret = Q_EMPTY;
  } else {
    *(uint32_t *)StoreRear = *(uint32_t *)queue->queue[rear];
  }

  return ret;
}

/* Helper Functions */
static QueueStatus isFull(queue_t *queue) {
  QueueStatus ret = Q_OK;

  if (NULL == queue) {
    ret = Q_NOK;
#ifdef DEBUG_QUEUE
    printf("Queue Doesn't Exist!!\n");
#endif
  } else {
    if (queue->CurrentSize == queue->MaxElements) {
      ret = Q_FULL;
    }
  }

  return ret;
}

static QueueStatus isEmpty(queue_t *queue) {
  QueueStatus ret = Q_OK;

  if (NULL == queue) {
    ret = Q_NOK;
#ifdef DEBUG_QUEUE
    printf("Queue Doesn't Exist!!\n");
#endif
  } else {
    if (queue->CurrentSize == 0) {
      ret = Q_EMPTY;
    }
  }

  return ret;
}

QueueStatus Q_CurrentSize(queue_t *queue, uint32_t *size) {
  QueueStatus ret = Q_OK;

  if (NULL == queue) {
    ret = Q_NOK;
    printf("NULL pointer error\n");
  } else {
    *size = queue->CurrentSize;
#ifdef DEBUG_QUEUE
    printf("Current Size = %i\n", *size);
#endif
  }
  return ret;
}

QueueStatus Q_init(queue_t *queue, uint32_t maxSize) {
  uint32_t counter = 0;
  QueueStatus ret = Q_OK;
  void **ptr = NULL;
  if (NULL == queue) {
    ret = Q_NOK;
  } else {
    queue->front = -1;
    queue->rear = -1;
    queue->CurrentSize = 0;
    queue->MaxElements = maxSize;
    ptr = (void **)calloc(queue->MaxElements, sizeof(queue_t));
    if (NULL != ptr) {
      queue->queue = ptr;
      for (counter = 0; counter < queue->MaxElements; counter++) {
        queue->queue[counter] = (void *)malloc(sizeof(void *));
      }
    } else {
      ret = Q_NOK;
#ifdef DEBUG_QUEUE
      printf("Failed to allocate memory for queue!!!\n");
#endif
    }
  }

  return ret;
}

QueueStatus Q_Destroy(queue_t *queue) {
  QueueStatus ret = Q_OK;
  uint32_t counter = 0;

  if (NULL == queue) {
    ret = Q_NOK;
  } else {
    for (counter = 0; counter < queue->MaxElements; counter++) {
      free(queue->queue[counter]);
    }
    free(queue->queue);
    free(queue);
  }

  return ret;
}
