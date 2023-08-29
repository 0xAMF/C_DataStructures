#include "SingleLinkedList.h"
#include <stdint.h>

return_status_t insert_node(node_t **list, uint32_t index) {
  return_status_t ret = OK;
  node_t *newNode = NULL;
  node_t *tempNode = NULL;
  uint32_t counter = 0;

  if (NULL != list) {

    if (0 == index) { /* insert node at the beginning of the list */
      insert_beginning(list);
    } 
    else if (index < 0 || index > getLength(*list)) {
      ret = NOK;
      #ifdef LL_DEBUG
      printf("No elements exist at this index!\n");
      #endif
    }
    else if (index == (getLength(*list) - 1)) { /* insert node at the end of the list */
      append_node(list); 
    }
    else {
      newNode = (node_t *)malloc(sizeof(node_t));
      
      if (NULL != newNode) {
        tempNode = *list;
        
        printf("Enter the data you want to insert at index %i: ", index);
        scanf("%i", &(newNode->data));
        
        tempNode = *list;
        while (counter != (index - 1)) {
          counter++;
          tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        tempNode->next = newNode;
      }
      else {
        ret = NOK;
        #ifdef LL_DEBUG
        printf("\nCouldn't allocate memory for the node!!\n\n");
        #endif
      }
    }
  }
  else {
    ret = NOK;

    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif
  }

  return ret;
}

static return_status_t insert_beginning(node_t **list) {
  return_status_t ret = OK;
  node_t *newNode = NULL;

  if (NULL != list) {
    newNode = (node_t *)malloc(sizeof(node_t));
    if (NULL != newNode) {
      printf("Enter the data you want to insert at beginning : ");
      scanf("%i", &(newNode->data));
     
      if (NULL == *list) { /* List is empty */
        *list = newNode;
        newNode->next = NULL;
      }
      else { /* List is not empty */
        newNode->next = *list; 
        *list = newNode;
      }
      
      #ifdef LL_DEBUG
      printf("Inserted %i to the list\n", newNode->data);
      #endif
    }
    else {
      ret = NOK;
      
      #ifdef LL_DEBUG
      printf("Couldn't allocate memory for node!!\n");
      #endif     
    }
  }
  else {
    ret = NOK;
    
    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif
  }

  return ret;
}

return_status_t append_node(node_t **list) {
  
  return_status_t ret = OK;
  node_t *lastNode = NULL;  
  node_t *newNode = NULL;

  newNode = (node_t *)malloc(sizeof(node_t));
  
  if (NULL != list) { /* Check if null pointer is passed to the function */
    if (NULL != newNode) { /* Check if memeory is allocated */
      printf("Enter the data you want to append: ");
      scanf("%i", &(newNode->data));
      newNode->next = NULL;
      
      if (NULL == *list) { /* List is empty */
        *list = newNode;
        #ifdef LL_DEBUG
        printf("adding %i to an empty list\n", newNode->data);
        #endif
      }
      else { /* List is not empty */
        lastNode = *list;
        while (NULL != lastNode->next) {
          lastNode = lastNode->next; 
        }
        lastNode->next = newNode;
      } 
      
      #ifdef LL_DEBUG
      printf("Appending %i to the list\n", newNode->data);
      #endif
    }
    else {
      ret = NOK;
      
      #ifdef LL_DEBUG
      printf("Couldn't allocate memory for the node!!\n");
      #endif     
    }
  }
  else {
    ret = NOK;
    
    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif
  }

  return ret;
}

return_status_t remove_node(node_t **list, uint32_t index) {
  return_status_t ret = OK;
  uint32_t counter = 0;
  node_t *tempNode = NULL;
  node_t *nextNode = NULL;

  if (NULL != list) {
    if (index > getLength(*list)) {
      ret = NOK;
      #ifdef LL_DEBUG
      printf("Exceeded the size of the list\n");
      #endif
    }
    else if(index == 0) { /* Remove the head node */
      remove_beginning(list);  
    }
    else if(index == getLength(*list) - 1) { /* Remove the end node */
      remove_end(list);
    }
    else {
      tempNode = *list;
      while (counter != index - 1) {
        counter++;
        tempNode = tempNode->next;
      }
      nextNode = tempNode->next; 
      tempNode->next = nextNode->next;
      free(nextNode);
    }
  }
  else {
     ret = NOK;
    
    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif 
  }

  return ret;
}

static return_status_t remove_beginning(node_t **list) {
  return_status_t ret = OK;
  node_t *tempNode = NULL;
  
  if (NULL != list) {
    tempNode = *list;
    *list = tempNode->next;
    #ifdef LL_DEBUG
    printf("Removed %i from the head of the list\n", tempNode->data);
    #endif
    free(tempNode);
  }
  else {
    ret = NOK;
    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif
  }
    
  return ret;
}

static return_status_t remove_end(node_t **list) {
  return_status_t ret = OK;
  node_t *tempNode = NULL;
  uint32_t counter = 0;
  uint32_t end = getLength(*list) - 2;

  if (NULL != list) {
    tempNode = *list; 
    while(counter < end) {
      counter++;
      tempNode = tempNode->next; 
    }
    tempNode->next = NULL;
  }
  else {
    ret = NOK; 
    #ifdef LL_DEBUG
    printf("NULL pointer error!!\n");
    #endif
  }

  return ret;
}

return_status_t display_list(node_t *list) {
  return_status_t ret = OK;
  node_t *tempNode = list;

  if (NULL != list) { 
    printf("The elements of the list: ");
    while (NULL != tempNode) {
      printf("%i ==> ", tempNode->data);
      tempNode = tempNode->next;
    }
    if (NULL == tempNode) {
      printf("NULL\n");
    }
  }
  else {
    ret = NOK; 
    #ifdef LL_DEBUG
    printf("NULL pointer error\n"); 
    #endif
  } 

  return ret;
}

uint32_t retrieve(node_t *list, uint32_t index) {
  uint32_t ret = 0;
  node_t *tempNode = NULL;
  uint32_t counter = 0;
  
  if (NULL != list) {
    tempNode = list; 
    while (counter != index) {
      counter++; 
      tempNode = tempNode->next;
    }
    ret = tempNode->data; 
  }
  else {
    printf("NULL pointer error\n"); 
  }
 
  return ret;
}

uint32_t getLength(node_t *list) {
  uint32_t length = 0; 
  node_t *tempNode = list; 
  
  if (NULL != list) {
    while(NULL != tempNode) {
     tempNode = tempNode->next;
     length++;
    }
  }
  else {
    length = 0;
  }

  return length;
}
