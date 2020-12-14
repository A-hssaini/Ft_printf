# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 15:01:27 by ahssaini          #+#    #+#              #
#    Updated: 2020/02/08 15:01:28 by ahssaini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_itoa.c ft_itoa_base.c ft_printf.c ft_strdup.c\
	   ft_strlen.c outils1.c typed.c typep.c types.c typeu.c typexx.c\
		ft_itoa_base_utils.c ft_itoa_base_utils1.c outils2.c\
		typed1.c typeu1.c typexx1.c

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix objs/, $(OBJ))
OBJS_DIR = objs/

FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $(OBJS)
	@ranlib $@

objs/%.o: srcs/%.c incs/ft_printf.h
	@gcc $(FLAGS) -c $< -o $@ -I incs

$(OBJS_DIR):
	@mkdir -p $@

.PHONY: clean
clean:
	@rm -rf objs/

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all