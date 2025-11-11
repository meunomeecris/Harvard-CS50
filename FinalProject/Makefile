# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./library -I./core -I./menu -I./cleaner

# Executable name
TARGET = run

# List of source files (.c)
SRC = \
	core/core.c \
	library/cs50.c \
	menu/menu_cli.c \
	cleaner/cleaner.c

# Generate object files automatically (.o)
OBJ = $(SRC:.c=.o)

# Default rule (build the executable)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
