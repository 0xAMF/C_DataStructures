
CFLAGS = -Wno-implicit-function-declaration

dll : dll 

dll : main.o DoublyLinkedList.o
	@echo "=== Linking files and producing final application ==="
	gcc $(CFLAGS) main.o DoublyLinkedList.o -o dll
	@chmod +x dll 

main.o: main.c
	@echo "Compiling main file"
	gcc $(CFLAGS) -c main.c

DoublyLinkedList.o: DoublyLinkedList.c
	@echo "==== Compiling Linked List file ===="
	gcc $(CFLAGS) -c DoublyLinkedList.c

clean:
	@echo "=== Cleaning files ===" 
	@rm *.o dll 
