#include "DoublyLinkedList.h"

return_status_t insert_node(node_t **list, uint32_t index)
{
    return_status_t ret = OK;
    node_t *tempNode = NULL;
    node_t *newNode = NULL;
    uint32_t length = getLength(*list);
    uint32_t counter = 0;

    if (NULL != list) {
        if ((length - 1) == index && 0 != index) { /* Make sure to append to a full list */
            append_node(list);
        }
        else if (0 == index) { /* Insert at beginning only when index = 0 */
            insert_beginning(list);
        }
        else if (length <= index) { /* Check index boundaries */
            ret = NOK;
            #ifdef DLL_DEBUG
            printf("index out of bounds error!!\n");
            #endif 
        }
        else {
            newNode = (node_t *)malloc(sizeof(node_t));
            printf("Enter the data you want to insert at index %i: ", index);
            scanf("%i", &newNode->data);
            
            if (NULL != newNode) {
                tempNode = *list;
                while (counter != (index - 1)) {
                    counter++;
                    tempNode = tempNode->next;
                }
                newNode->prev = tempNode;
                newNode->next = tempNode->next;
                (tempNode->next)->prev = newNode;
                tempNode->next = newNode;
            }
            else {
                ret = NOK;
                #ifdef DLL_DEBUG  
                printf("Couldn't allocate memory for node\n");
                #endif
            }
        }
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }

    return ret;
}

return_status_t insert_beginning(node_t **list) 
{
    return_status_t ret = OK;
    node_t *newNode = NULL;
    
    if (NULL != list) {
        newNode = (node_t *)malloc(sizeof(node_t)); 
        if (NULL != newNode) {
            printf("Enter the data to insert at beginning: ");
            scanf("%i", &(newNode->data));
            newNode->prev = NULL; 
            
            if (NULL != *list) {
                newNode->next = *list; /* Make next node the old head node */
                *list = newNode; /* Set the new node as the head node */
            }
            else {
                *list = newNode; /* Make the new node the head of the list */
                newNode->next = NULL;
            }
            #ifdef DLL_DEBUG
            printf("Added %i to the list\n", (*list)->data);
            #endif 
        }
        else {
            ret = NOK;
            #ifdef DLL_DEBUG  
            printf("Couldn't allocate memory for node\n");
            #endif
        }
    }  
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }
    
    return ret;
}

return_status_t append_node(node_t **list)
{
    return_status_t ret = OK;
    node_t *tempNode = NULL;
    node_t *newNode = NULL;
    
    if (NULL != list) {
        newNode = (node_t *)malloc(sizeof(node_t));
        if (NULL != newNode) {
            printf("Enter the data you want to append: ");
            scanf("%i", &(newNode->data));
            newNode->next = NULL;
            tempNode = *list;

            while(NULL != tempNode->next) {
                tempNode = tempNode->next;
            }

            newNode->prev = tempNode;
            tempNode->next = newNode;
        }
        else {
            ret = NOK;
            #ifdef DLL_DEBUG
            printf("Couldn't allocate memory for the node!!\n");
            #endif   
        }
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }

    return ret;
}

return_status_t remove_node(node_t **list, uint32_t index)
{
    return_status_t ret = OK;
    node_t *tempNode = NULL;
    uint32_t counter = 0;
    
    if (NULL != list) {
        if ((getLength(*list) - 1) == index) {
            remove_end(list);
        }
        else if (0 == index) {
            remove_beginning(list);
        }
        else if (getLength(*list) <= index) {
            ret = NOK;
            
            #ifdef DLL_DEBUG
            printf("index out of bounds error!!\n");
            #endif 
        }
        else {
            tempNode = *list;
            while (counter != index) {
                counter++;
                tempNode = tempNode->next;
            }
            (tempNode->prev)->next = tempNode->next;
            (tempNode->next)->prev = tempNode->prev;
            
            #ifdef DLL_DEBUG
            printf("Removed element %i at index %i\n",tempNode->data , index);
            #endif 
            free(tempNode);
        }
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }

    return ret;
}

return_status_t remove_end(node_t **list)
{
    return_status_t ret;
    node_t *tempNode = NULL;
    uint32_t counter = 0;

    if (NULL != list) {
        tempNode = *list;
        
        while (counter < (getLength(*list) - 2)) { /* itirate untill the node before the last node */
            counter++; 
            tempNode = tempNode->next;
        } 
        #ifdef DLL_DEBUG
        printf("Removed %i from the end of the list\n", (tempNode->next)->data);
        #endif
        tempNode->next = NULL;        
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }

    return ret;
}

return_status_t remove_beginning(node_t **list)
{
    return_status_t ret;
    node_t *tempNode = NULL;
    
    if (NULL != list) {
        tempNode = *list;
        *list = tempNode->next;
        (*list)->prev = NULL;

        #ifdef DLL_DEBUG
        printf("Removed %i from the head of the list\n", tempNode->data);
        #endif
        free(tempNode);
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("NULL pointer error!!\n");
        #endif
    }   
    
    return ret;
}

return_status_t display_forward(node_t *list)
{
    return_status_t ret = OK;
    node_t *lastNode = NULL;
    
    if (NULL != list) {
        lastNode = list;
        while (NULL != lastNode) {
            printf("%i =>  ", lastNode->data);
            lastNode = lastNode->next;
        }
        if (lastNode == NULL) {
            printf("NULL\n");
        }
        else {/* Nothing */}
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("The list is empty!\n");
        #endif       
    }

    return ret;
}

return_status_t display_reverse(node_t *list) 
{
    return_status_t ret = OK;
    node_t *tempNode = NULL;

    if (NULL != list) {
        tempNode = list;
        while (NULL != tempNode->next) {
           tempNode = tempNode->next;
        }
        while (NULL != tempNode) {
            printf("%i => ", tempNode->data);
            tempNode = tempNode->prev;
        }
        if (tempNode == NULL) {
            printf("NULL\n");
        }
        else {/* Nothing */}
    }
    else {
        ret = NOK;
        #ifdef DLL_DEBUG
        printf("The list is empty!\n");
        #endif       
    }

    return ret;
}

uint32_t getLength(node_t *list)
{
    node_t *tempNode = NULL;
    uint32_t len = 0;

    if (NULL != list) {
        tempNode = list;
        
        while (NULL != tempNode) {
            tempNode = tempNode->next;
            len++;
        }
    }
    else {
        len = 0;
    }

    return len;
}
