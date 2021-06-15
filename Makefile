# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 10:51:35 by abenouda          #+#    #+#              #
#    Updated: 2021/06/13 15:27:05 by abenouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c ft_split.c cmd.c execute.c ft_strrchr.c\
		ft_strncmp.c ft_strjoin.c ft_putstr.c
# OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(SRC)
	gcc $(SRC) $(FLAGS) -o $(NAME)

clean:
	# /bin/rm -f $(OBJ)
	# /bin/rm -f $(OBJ_BONUS)
	
fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all