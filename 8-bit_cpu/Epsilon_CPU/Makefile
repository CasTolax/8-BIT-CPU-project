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
         $(wildcard lib/logic_gates/*.c) \
         $(wildcard lib/sys_status/*.c) \
         $(wildcard lib/registers/*.c) \
         $(wildcard lib/registers/Fregisters/*.c)

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
