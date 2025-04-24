# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 19:11:01 by aosmenaj          #+#    #+#              #
#    Updated: 2024/04/22 19:11:42 by aosmenaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR      := ar
CC      := cc
RM      := rm -f
CFLAGS  := -g -Wall -Wextra -Werror -Iminilibx-linux -I/usr/include
LDFLAGS :=  $(LDFLAGS) -L minilibx-linux
LDLIBS := -lm -lmlx_Linux -lXext -lX11

NAME := so_long

COMMON_DEPS := 

COMMON_SOURCES := 

BASE_DEPS := $(COMMON_DEPS)	\
				ber_man.h	\
				disp_man.h	\
				elem_man.h	\
				map_man.h	\
				mlx.h		\
				so_long.h	\
				utility.h	\
				win_man.h


BASE_SOURCES := $(COMMON_SOURCES)	\
					ber_man.c		\
					ber_man_1.c		\
					disp_man.c		\
					elem_man.c		\
					main.c			\
					map_man.c		\
					map_man_1.c		\
					map_man_2.c		\
					map_man_3.c		\
					so_long.c		\
					utility.c		\
					utility_1.c		\
					win_man.c		\
					win_man_1.c		\
					win_man_2.c

BASE_OBJECTS := $(BASE_SOURCES:.c=.o)

BONUS_SOURCES :=  $(COMMON_SOURCES)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(BASE_OBJECTS)

$(BASE_OBJECTS): $(BASE_SOURCES) $(DEPS)

clean: 
	$(RM) $(BASE_OBJECTS)
	$(RM) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

