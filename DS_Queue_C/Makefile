CFLAGS = -Wno-implicit-function-declaration

queue : queue

queue : main.o Queue_Ds.o
	@echo "==== Linking files ===="
	gcc $(CFLAGS) main.o Queue_Ds.o -o queue
	@chmod +x queue

main.o : main.c
	@echo "==== Compiling main file ===="
	gcc $(CFLAGS) -c main.c

Queue_Ds.o : Queue_Ds.c
	@echo "==== Compiling Queue source file ===="
	gcc $(CFLAGS) -c Queue_Ds.c

clean :
	@echo "===Files Cleaned==="
	@rm *.o queue
