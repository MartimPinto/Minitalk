# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 15:07:37 by mcarneir          #+#    #+#              #
#    Updated: 2023/07/27 14:25:55 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_S = src/server.c \

SRC_SB = src_bonus/server_bonus.c \

SRC_C = src/client.c \

SRC_CB = src_bonus/client_bonus.c \

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = minitalk


LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_S) $(OBJ_C)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ_S) $(LIBFT) -o server
	@$(CC) $(OBJ_C) $(LIBFT) -o client

bonus: $(OBJ_SB) $(OBJ_CB)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ_SB) $(LIBFT) -o server_bonus
	@$(CC) $(OBJ_CB) $(LIBFT) -o client_bonus
clean:
		$(MAKE) clean -C ./libft
		@$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_SB) $(OBJ_CB)
fclean: clean
		@$(RM) $(LIBFT) $(NAME) server client server_bonus client_bonus
re: fclean $(NAME)	

