#ifndef _QUEUE_DS_H
#define _QUEUE_DS_H

#include "stdtypes.h"
#include <stdio.h>
#include <stdlib.h>
#define DEBUG_QUEUE

/* Queue Structure */
typedef struct {
  void **queue;
  sint32_t front;
  sint32_t rear;
  uint32_t MaxElements;
  uint32_t CurrentSize;
} queue_t;


typedef enum { Q_OK, Q_NOK, Q_EMPTY, Q_FULL } QueueStatus;

/*==== Basic Functions ====*/
/*
 * @brief  : Add element to the queue.
 * @param  : The Queue, the address of the element.
 * @retval : Queue status.
 */
QueueStatus enqueue(queue_t *queue, void *element);

/*
 * @brief  : Remove an element from the queue.
 * @param  : The Queue, pointer to store the address of the removed element.
 * @retval : Queue status.
 */
QueueStatus dequeue(queue_t *queue, void *DQ_Elmenet);

/*
 * @brief  : To return the front of the queue.
 * @param  : The Queue, pointer to store the address of the front element.
 * @retval : Queue status.
 */

QueueStatus getFront(queue_t *queue, void *StoreFront);

/*
 * @brief  : To return the rear of the queue.
 * @param  : The Queue, pointer to store the address of the rear element.
 * @retval : Queue status.
 */
QueueStatus getRear(queue_t *queue, void *StoreRear);

/*==== Helper Functions ====*/
/*
 * @brief  : To check of the queue is full.
 * @param  : The Queue.
 * @retval : Queue status.
 */
static QueueStatus isFull(queue_t *queue);

/*
 * @brief  : To check of the queue is empty.
 * @param  : The Queue.
 * @retval : Queue status.
 */
static QueueStatus isEmpty(queue_t *queue);

/*
 * @brief  : To get the current size of the queue.
 * @param  : The Queue, pointer to store the size of the queue.
 * @retval : Queue status.
 */
QueueStatus Q_CurrentSize(queue_t *queue, uint32_t *size);

/*
 * @brief  : Initialize the queue.
 * @param  : The Queue, The size of the Queue.
 * @retval : Queue status.
 */
QueueStatus Q_init(queue_t *queue, uint32_t maxSize);

/*
 * @brief  : Deallocates the queue from memory.
 * @param  : The Queue.
 * @retval : Queue status.
 */
QueueStatus Q_Destroy(queue_t *queue);

#endif /* ifndef _QUEUE_DS_H */
