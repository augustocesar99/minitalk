# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 17:21:18 by acesar-m          #+#    #+#              #
#    Updated: 2025/01/09 14:34:54 by acesar-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program of the library
SERVER	= server
CLIENT	= client

#Compilers and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#Directories
SRCS = src
INCLUDES = -I libft/ -I src/ -I .

# Files
SRC_CLIENT = $(SRCS)/client.c
SRC_SERVER = $(SRCS)/server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

#Library
LIBFT = libft/libft.a

all: $(LIBFT) $(CLIENT) $(SERVER)

#Client Executable
$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

#Server Executable
$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	
%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C libft
	@echo "Library Compiled."

clean:
	@make -C libft clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	@make -C libft fclean
	rm -f $(CLIENT) $(SERVER)

re:	fclean all

.PHONY: clean fclean all re
