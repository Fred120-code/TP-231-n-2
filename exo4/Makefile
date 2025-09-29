CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = exo4
SRCS = main.c list.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean run valgrind

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
