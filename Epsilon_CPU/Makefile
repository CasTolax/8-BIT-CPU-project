# Makefile for Epsilon_CPU

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
INCLUDES = -I./lib -I./src
SRCDIR = src
OBJDIR = obj
TARGET = epsilon_cpu

SRCS = $(wildcard $(SRCDIR)/*.c) \
       $(wildcard lib/*.c) \
       $(wildcard lib/alu/*.c) \
       $(wildcard lib/err/*.c) \
       $(wildcard lib/scheduler/*.c) \
       $(wildcard lib/command/*.c) \
       $(wildcard lib/interrupts/*.c) \
       $(wildcard lib/Logic Gates/*.c)

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Progress system
TOTAL := $(words $(SRCS))
COUNT_FILE := $(OBJDIR)/.count

# Colors
GREEN = \033[1;32m
BLUE  = \033[1;34m
RESET = \033[0m

.DEFAULT_GOAL := run
.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)[BUILD OK]$(RESET) $(TARGET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

	@count=$$(cat $(COUNT_FILE) 2>/dev/null || echo 0); \
	count=$$((count + 1)); \
	echo $$count > $(COUNT_FILE); \
	printf "$(GREEN)[%d$(RESET)/$(BLUE)%d$(RESET)] $(GREEN)OK!$(RESET) %s\n" \
	$$count $(TOTAL) $@

clean:
	@rm -rf $(OBJDIR) $(TARGET) $(COUNT_FILE)
	@echo "$(GREEN)[CLEAN OK]$(RESET)"
