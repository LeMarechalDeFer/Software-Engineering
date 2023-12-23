
CC = gcc
CCFLAGS = -Wall -Werror -Wextra

MAIN_EXE = main
OBJS = main.o list.o

all: $(MAIN_EXE)

$(MAIN_EXE) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(MAIN_EXE) $(OBJS)

main.o: main.c
	$(CC) $(CCFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CCFLAGS) -c list.c

clean:
	rm -f $(OBJS) $(MAIN_EXE)
