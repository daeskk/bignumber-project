OBJECTS=./build/bignumber.o ./build/expression.o ./build/process.o
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

./build/expression.o: ./expression.c
	$(COMPILATION_FLAGS) $(INCLUDES) -c ./expression.c -o ./build/expression.o

./build/process.o: ./process.c
	$(COMPILATION_FLAGS) $(INCLUDES) -c ./process.c -o ./build/process.o