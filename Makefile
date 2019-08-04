# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:53:40 by mobouzar          #+#    #+#              #
#    Updated: 2019/08/03 23:16:05 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
OBJECTS = ft_init.o ft_print_c.o ft_print_x.o ft_print_d.o ft_printf.o ft_split_format.o main.o \
			ft_print_o.o ft_print_p.o ft_print_persent.o
LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		@ar rc $(NAME) $(OBJECTS) libft/*.o
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[0;32m| >>>>>>>>>>>>>>>>>>>>>>>>>> Compiled Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"

%.o : %.c
		@gcc -c $< -o $@
$(LIBFT):
		@make -C libft/
clean : 
		@make clean -C libft/
		@rm -f $(OBJECTS)
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"

fclean : clean
		@make fclean -C libft/
		@rm -f $(NAME)

re : fclean all
