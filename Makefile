# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 17:25:28 by smokashi          #+#    #+#              #
#    Updated: 2022/07/12 11:25:07 by smokashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = bship.c color.c julia.c mbrot.c utils.c utils2.c main.c ft_atof.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

MLXFLAGS = -L ./ -lmlx

RM = rm -rf

all : $(NAME)
		
$(NAME):$(OBJS)
	make -C mlx/
	mv mlx/libmlx.dylib ./ 
	$(CC) $(CFLAGS) $(MLXFLAGS) -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		$(RM) $(OBJS) libmlx.dylib

bonus : all

fclean : clean
		make clean -C mlx/
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus