CFLAGS = -Wno-implicit-function-declaration

stack : stack

stack: main.o stack_ds.o
	@echo "Linking files and producing final application"
	gcc $(CFLAGS) main.o stack_ds.o -o stack
	@chmod +x stack

stack_ds.o: stack_ds.c
	@echo "Compiling stack_ds file"
	gcc $(CFLAGS) -c stack_ds.c

main.o: main.c
	@echo "Compiling main file"
	gcc $(CFLAGS) -c main.c

clean:
	@echo "Cleaning files"
	@rm main.o stack_ds.o stack
