# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 11:10:37 by ngordobi          #+#    #+#              #
#    Updated: 2024/07/29 11:10:37 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	checker

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror

UTILS				=	../utils/

SOURCES				=	checker.c \
						get_next_line.c \
						get_next_line_utils.c \

SOURCES_UT			=	$(UTILS)check_numbers.c \
						$(UTILS)ft_atoi.c \
						$(UTILS)ft_split.c \
						$(UTILS)ft_substr.c \
						$(UTILS)ft_printf.c \
						$(UTILS)ft_putchar.c \
						$(UTILS)ft_putstr.c \
						$(UTILS)ft_putnbr.c \
						$(UTILS)ft_putunbr.c \
						$(UTILS)ft_puthex.c \
						$(UTILS)ft_putptr.c \

OBJECTS				=	$(SOURCES:%.c=%.o)
OBJECTS_UT			=	$(SOURCES_UT:%.c=%.o)

INCLUDE				=	push_swap_bonus.h

.SILENT:

all: 			$(NAME)

$(NAME):		$(OBJECTS) $(OBJECTS_UT) $(INCLUDE)
				$(CC) $(CC_FLAGS) $(OBJECTS) $(OBJECTS_UT) -o $(NAME)
				mkdir ./objects/
				mv $(OBJECTS) ./objects/
				mv $(NAME) ../
				echo "\n···················· Checker compilation complete ····················"

clean:
				rm -rf ./objects/
				rm -rf ./*.o
				echo "\n·······································"
				echo "\n· Checker objects correctly removed."

fclean:			clean
				rm -rf ../$(NAME)
				echo "· Checker executable correctly removed.\n"

re:				fclean all
.PHONY:			all clean fclean re
