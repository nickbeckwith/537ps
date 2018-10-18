# the compiler
CC = gcc

# Compiler Flags
FLAGS = -g -Wall -Wextra -lpthread
EXE = prodcomm

# Dir for clang static analyzer
SCAN_BUILD_DIR = scan-build-out

default: main

$(EXE):	main.o munch1.o munch2.o queue.o reader.o writer.o
	$(CC) $(FLAGS) -o $(EXE) main.o munch1.o munch2.o queue.o reader.o writer.o

main.o:	main.c main.h
	$(CC) $(FLAGS) -c main.c

munch1.o:	munch1.c munch1.h
		$(CC) $(FLAGS) -c munch1.c

munch2.o:	munch2.c munch2.h
		$(CC) $(FLAGS) -c munch2.c

queue.o:	queue.c queue.h
		$(CC) $(FLAGS) -c queue.c

reader.o:	reader.c reader.h
		$(CC) $(FLAGS) -c reader.c

writer.o:	writer.c writer.h
		$(CC) $(FLAGS) -c writer.c

clean:
	rm -f $(EXE) *.o
	rm -rf $(SCAN_BUILD_DIR)

scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

# view clang static
scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html
