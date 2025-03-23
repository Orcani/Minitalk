# Compiler
CC = cc

MAKE = make
# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Project name
NAME = minitalk

#NOm du directory
PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)/libftprintf.a
# Server and Client names
SERVER = server
CLIENT = client

# DirectoriesS
SRC_DIR = .
OBJ_DIR = obj

# Source files
SERVER_SRCS = $(SRC_DIR)/server.c
CLIENT_SRCS = $(SRC_DIR)/client.c

# Object files
SERVER_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SERVER_SRCS))
CLIENT_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CLIENT_SRCS))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Default target
all: $(OBJ_DIR) $(SERVER) $(CLIENT)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile server
$(SERVER): $(SERVER_OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Server compiled successfully!$(RESET)"

# Compile client
$(CLIENT): $(CLIENT_OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Client compiled successfully!$(RESET)"

$(PRINTF): 
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "$(GREEN)Printf compiled successfully!$(RESET)"
# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $<$(RESET)"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@echo "$(YELLOW)Object files cleaned$(RESET)"

# Clean executables and object files
fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "$(YELLOW)Executables cleaned$(RESET)"

# Rebuild everything
re: fclean all

# Debug build
debug: CFLAGS += -g -fsanitize=address
debug: re

# Phony targets
.PHONY: all clean fclean re debug


