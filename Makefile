OBJECTS= ./build/bignumber.o ./build/custom_io.o
INCLUDES= -I ./include
OBJECT_FLAGS= -g -c
COMPILATION_FLAGS= gcc -std=c99 -g -lm

all: ${OBJECTS}
	${COMPILATION_FLAGS} ${INCLUDES} client.c ${OBJECTS} -g -o ./client

./build/bignumber.o: ./bignumber.c
	${COMPILATION_FLAGS} ${INCLUDES} ./bignumber.c -o ./build/bignumber.o ${OBJECT_FLAGS}

./build/custom_io.o: ./custom_io.c
	${COMPILATION_FLAGS} ${INCLUDES} ./custom_io.c -o ./build/custom_io.o ${OBJECT_FLAGS}