CC		= gcc
C_FLAGS = -Wall -Wextra

BIN		= ./bin
SRC		= ./src
INCLUDE	= ./include
LIB		= ./lib

EXECUTABLE	= BucketSort

all: $(EXECUTABLE)

$(EXECUTABLE): buckesort.o listaenc.o listaseq.o txtio.o
	$(CC) $(C_FLAGS) -o $(EXECUTABLE) buckesort.o listaenc.o listaseq.o txtio.o

buckesort.o: $(LIB)/buckesort.c $(LIB)/buckesort.h
	$(CC) #(C_FLAGS) -c $(LIB)/buckesort.c

listaenc.o: $(LIB)/listaenc.c $(LIB)/listaenc.h
	$(CC) 