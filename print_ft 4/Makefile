# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:53:40 by mobouzar          #+#    #+#              #
#    Updated: 2019/07/30 19:10:30 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = *.c
OBJECTS = s

all : $(NAME)

$(NAME) :
		@make -C libft/
		@gcc -c $(SRC)
		@ar rc $(NAME) $(OBJECTS) libft/*.o
clean : 
		@make clean -C libft/
		@rm -f $(OBJECTS)
fclean : clean
		@make fclean -C libft/
		@rm -f $(NAME)

re : fclean all
