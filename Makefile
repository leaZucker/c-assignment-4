CC = gcc
FLAGS = -Wall -g
all:frequency.o main.o
	$(CC) $(FLAGS) -o frequency frequency.o main.o

frequency.o: frequency.c frequency.h
	$(CC) $(FLAGS) -c frequency.c

main.o: main.c frequency.h
	$(CC) $(FLAGS) -c main.c