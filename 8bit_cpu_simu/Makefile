CC = gcc
CFLAGS = -g -Wall -I.
SRCS = $(wildcard **/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = cpu_sim

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run