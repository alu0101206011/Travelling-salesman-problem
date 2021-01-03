CC = g++
CFLAGS = -g -Wall --std=c++17
OBJ = ./tsp_main.o ./tsp.o 
EXEC = tsp

all: $(OBJ)
	$(CC) $(CFLAGS) -o ./$(EXEC) $^

./%.o: ./%.cpp 
	$(CC) -c -o $@ $<

run: clean all
	./$(EXEC)

.PHONY: clean

clean:
	bash -O extglob -c "rm -vf !(*.cc|*.h|"makefile"|*.txt|README.md)"