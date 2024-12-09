# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror


SRC = ft_printf.c main.c myheader.c  

# Object files (automatic conversion from .c to .o)
OBJ = $(SRC:.c=.o)

# Executable name
NAME = my_printf

# Default target to build the executable
all: $(NAME)

# Link the object files to create the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Compile the object files
%.o: %.c myheader.h  # Ensure myheader.h is available for function prototypes
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ)

# Clean up object files, the executable, and other generated files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
