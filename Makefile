# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anain <anain@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 03:28:17 by anain             #+#    #+#              #
#    Updated: 2017/06/22 17:04:05 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_take_coord.c ft_graph.c ft_draw.c ft_pic.c ft_layout.c ft_param.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -I minilibx -o $(NAME) libft/libft.a $(OBJ) minilibx/libmlx.a -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	make -C minilibx/ clean
	/bin/rm -f $(OBJ)

fclean:  clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
