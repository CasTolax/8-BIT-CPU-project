# Makefile for Epsilon_CPU

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
INCLUDES = -I./lib -I./src
SRCDIR = src
OBJDIR = obj
TARGET = epsilon_cpu

SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard lib/*.c) $(wildcard lib/alu/*.c) $(wildcard lib/err/*.c) $(wildcard lib/scheduler/*.c) $(wildcard SRCDIR)command/*.c)
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

.DEFAULT_GOAL := run
.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
