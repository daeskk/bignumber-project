OBJECTS=./build/bignumber.o ./build/custom_io.o ./build/expression.o
INCLUDES=-I ./
COMPILATION_FLAGS=gcc -std=c99 -g
LINKER_FLAGS=-lm

all: $(OBJECTS)
	$(COMPILATION_FLAGS) $(INCLUDES) client.c $(OBJECTS) $(LINKER_FLAGS) -o ./client

valgrind: all
	valgrind --leak-check=full ./client

clean:
	rm -f ./client
	rm -f ./build/*.o

./build/bignumber.o: ./bignumber.c
	$(COMPILATION_FLAGS) $(INCLUDES) -c ./bignumber.c -o ./build/bignumber.o

./build/custom_io.o: ./custom_io.c
	$(COMPILATION_FLAGS) $(INCLUDES) -c ./custom_io.c -o ./build/custom_io.o

./build/expression.o: ./expression.c
	$(COMPILATION_FLAGS) $(INCLUDES) -c ./expression.c -o ./build/expression.o