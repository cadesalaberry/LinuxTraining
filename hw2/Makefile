CC=gcc
CXX=g++
CC_FLAGS=-g -lm -O2 -c
OBJECTS=q1.o q2.o q3.o q4.o q5.o

all:$(OBJECTS)
	$(CC) q1.o -lm -o q1
	$(CC) q2.o -lm -o q2
	$(CC) q3.o -lm -o q3
	$(CC) q4.o -lm -o q4
	$(CC) q5.o -lm -o q5

$(OBJECTS):%.o:%.c
	$(CC) $(CC_FLAGS) $< -o $@

test_engine:test_engine.cc
	$(CXX) -g -O2 $< -o $@

clean:
	rm -rf *.o
	rm -rf q1 q2 q3 q4 q5
