TARGET = main
CC = g++
CFLAGS = -Wall -g -Iinclude
PROJ = n_queen.cpp
OBJS = $(PROJ:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)