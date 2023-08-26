#include "SingleLinkedList.h"
#include <stdint.h>


node_t *listHead = NULL;
uint32_t choice;
uint32_t insert_index;
uint32_t remove_index;
uint32_t ret_index;
uint32_t ret_element;
uint32_t length;

int main() {
  
  printf("=================================\n");
  printf("1) Insert node\n");
  printf("2) Append node\n");
  printf("3) Remove node\n");
  printf("4) Retrieve node\n");
  printf("5) Length of the list\n");
  printf("6) Display the list\n");
  printf("7) Quit\n");
  printf("=================================\n");

  while (choice != 7) {
    printf("Choice: ");
    scanf("%i", &choice);

    switch (choice) {
      case 1:
        printf("Insertion index = ");
        scanf("%i", &insert_index);
        insert_node(&listHead, insert_index);
        break;
      case 2:
        append_node(&listHead);
        break;
      case 3:
        printf("Removal index = "); 
        scanf("%i", &remove_index);
        remove_node(&listHead, remove_index);
        break;
      case 4:
        printf("Index of the element = "); 
        scanf("%i", &ret_index);
        ret_element = retrieve(listHead, ret_index);
        printf("Element at index %i = %i\n", ret_index, ret_element);
        break;
      case 5: 
        length = getLength(listHead); 
        printf("The length of the list = %i\n", length);
        break;
      case 6:
        display_list(listHead);
        break;
      case 7:
        printf("Application Terminated");
        break;
      default:
        printf("Invalid choice!!, try again: \n");
        break;
    }
      
  }
}
