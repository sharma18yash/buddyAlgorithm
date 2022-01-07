CC = g++
CFLAGS = -Wall -std=c++14 -g
DEPS = buddy.h
OBJ = calloc.o free.o main.o mallinfo.o malloc.o posix_mem_allign.o realloc.o test.o tree.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

ibfs: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lpthread 

.PHONY: clean

clean:
	rm -rf *.o ibfs
