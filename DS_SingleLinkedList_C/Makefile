CFLAGS = -Wno-implicit-function-declaration

sll : sll 

sll : main.o SingleLinkedList.o
	@echo "=== Linking files and producing final application ==="
	gcc $(CFLAGS) main.o SingleLinkedList.o -o sll
	@chmod +x sll 

main.o: main.c
	@echo "Compiling main file"
	gcc $(CFLAGS) -c main.c

SingleLinkedList.o: SingleLinkedList.c
	@echo "==== Compiling Linked List file ===="
	gcc $(CFLAGS) -c SingleLinkedList.c

clean:
	@echo "=== Cleaning files ===" 
	@rm *.o sll 

