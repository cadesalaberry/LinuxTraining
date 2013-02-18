CC=gcc
CC_FLAGS=-g -O2 -c -Wall
OBJECTS=q1.o q2.o q3.o q4.o q5.o

all:$(OBJECTS)
	$(CC) q1.o -o q1
	$(CC) q2.o -o q2
	$(CC) q3.o -o q3
	$(CC) q4.o -o q4
	$(CC) q5.o -o q5

$(OBJECTS):%.o:%.c
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm *.o
	rm -rf q1 q2 q3 q4 q5
