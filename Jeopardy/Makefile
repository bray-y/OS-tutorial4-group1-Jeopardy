# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = jeopardy.c questions.c players.c

# Object files (compiled versions of .c files)
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = jeopardy

# Default rule: compile everything
all: $(TARGET)

# Linking step: create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the game
run: all
	./$(TARGET)
