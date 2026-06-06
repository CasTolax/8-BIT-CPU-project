### HOW TO COMPILE?

## Compilers...

First, we need compilers; this processor simulation runs on C and C++ code. Therefore, we need to download and use GCC and G++.
(Maybe its not compile in your machine. So, you can use compile.py if you can!)

## Possible Errors

If the code isn’t compiling, I couldn’t find a solution, and this error appears: “missing separator...”

I carefully reviewed all the code in the Makefile but couldn’t find any issues. Just in case, I removed spaces from any lines where a TAB might cause problems and added TAB characters. However, it still didn’t work, so I sought help from Cloude AI, and it suggested I use this Python script instead—and it actually worked! If you encounter a similar issue, paste this code into the terminal!

(Don’t forget to adjust the code for your own machine!)

## May 31, 2026 Latest Updates!
I’ve been working on this project for about a month (maybe longer, since I was also trying to build it physically using a 74HC chip). While working on it, I relied on solid sources like Intel to access C and C++ documentation and learn how the processor works. 

Currently, this project includes the following: CLOCK, ALU, RAM, CACHE, INTERRUPTS, ERRORS, REGISTERS, PANIC MODE, SYSTEM STATUS, a very simple SCHEDULER, OPCODES, FLAGS (ZF, OF, CF), and GATES. I can honestly say I’ve managed to simulate it quite nicely!

(Additionally, it runs in the terminal...)

# Makefile for Epsilon_CPU
CC = gcc
CXX = g++
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g
INCLUDES = -I./lib -I./src
SRCDIR = src
OBJDIR = obj
TARGET = epsilon_cpu

C_SRCS = $(wildcard $(SRCDIR)/*.c) \
         $(wildcard lib/*.c) \
         $(wildcard lib/alu/*.c) \
         $(wildcard lib/err/*.c) \
         $(wildcard lib/scheduler/*.c) \
         $(wildcard lib/command/*.c) \
         $(wildcard lib/interrupts/*.c) \
         $(wildcard lib/logic_gates/*.c)

CPP_SRCS = $(wildcard lib/sys_status/*.cpp)

C_OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(C_SRCS))
CPP_OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(CPP_SRCS))
OBJS = $(C_OBJS) $(CPP_OBJS)

TOTAL := $(words $(OBJS))
COUNT_FILE := $(OBJDIR)/.count

GREEN = \033[1;32m
BLUE  = \033[1;34m
RESET = \033[0m

.DEFAULT_GOAL := run
.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@
	@echo "$(GREEN)[BUILD OK]$(RESET) $(TARGET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@count=$$(cat $(COUNT_FILE) 2>/dev/null || echo 0); \
	count=$$((count + 1)); \
	echo $$count > $(COUNT_FILE); \
	printf "$(GREEN)[%d$(RESET)/$(BLUE)%d$(RESET)] $(GREEN)OK!$(RESET) %s\n" \
	$$count $(TOTAL) $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@count=$$(cat $(COUNT_FILE) 2>/dev/null || echo 0); \
	count=$$((count + 1)); \
	echo $$count > $(COUNT_FILE); \
	printf "$(GREEN)[%d$(RESET)/$(BLUE)%d$(RESET)] $(GREEN)OK!$(RESET) %s\n" \
	$$count $(TOTAL) $@

clean:
	rm -rf $(OBJDIR) $(TARGET) $(COUNT_FILE)
	@echo "$(GREEN)[CLEAN OK]$(RESET)"
