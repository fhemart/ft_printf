# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhemart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 20:39:33 by fhemart           #+#    #+#              #
#    Updated: 2018/01/31 01:59:57 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/

LIB = libft/libft.a

SRC = ft_printf.c formatstr.c ft_strrjoin.c wchar.c conv_signed.c conv.c        \
	  checkmod.c baseconv1.c baseconv2.c checkpre.c freejoin.c checkcast.c		\
	  flags.c flag_ss.c flag_signed.c flag_unsigned.c flag_c.c flags2.c			\
	  flag_unsigned2.c engine.c ft_strnew2.c ft_strdup2.c

OBJ = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -c -Werror -Wextra -Wall

HEADER = ft_printf.h

INCLUDE = -I libft
.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(LIB) $(OBJ) $(HEADER)
	@echo "==========> LINKING"
	@cp $(LIB) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@echo "==========> RANLIB"
	@ranlib $(NAME)
	@echo "==========> OK ALL DONE"

$(LIB): 
	@echo "==========> COMPIL LIBFT"
	@make -C $(LIBFT)

%.o: %.c 
	@$(CC) $(CCFLAGS) $(INCLUDE) $< -o $@
	@echo $<

clean :
	@echo "==========> CLEANING"
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)
	@echo "==========> DONE"

fclean : clean
	@echo "==========> FCLEAN"
	@rm -f $(LIB)
	@rm -f $(NAME)
	@echo "==========> DONE"

re :
	@make fclean
	@make all

