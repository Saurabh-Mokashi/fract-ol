# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 17:25:28 by smokashi          #+#    #+#              #
#    Updated: 2022/07/06 18:29:08 by smokashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
SRCS = bship.c color.c julia.c mbrot.c utils.c utils2.c main.c ft_atof.c

OBJS = $(SRCS:.c = .o)

CC = gcc
CFLAGS = -Lmlx -lmlx -Ofast
RM = rm -rf


all : $(NAME)
		
$(NAME):
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(SRCS)

clean :$(OBJS)
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re:
		fclean all

.PHONY : all clean fclean re