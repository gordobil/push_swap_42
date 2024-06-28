# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/24 13:22:45 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror

UTILS				=	./utils/

SOURCES				=	push_swap.c \

SOURCES_PF			=	$(UTILS)ft_atoi.c \
						$(UTILS)ft_printf.c \
						$(UTILS)ft_putchar.c \
						$(UTILS)ft_putstr.c \
						$(UTILS)ft_putnbr.c \
						$(UTILS)ft_putunbr.c \
						$(UTILS)ft_puthex.c \
						$(UTILS)ft_putptr.c \

OBJECTS				=	$(SOURCES:%.c=%.o)
OBJECTS_PF			=	$(SOURCES_PF:%.c=%.o)

INCLUDE				=	push_swap.h

define PUSH_SWAP
\033[0;33m

 ██▓███   █    ██  ██████  ██░ ██         ██████  █     █░ ▄▄▄       ██▓███  
▓██░  ██▒ ██  ▓██▒██    ▒ ▓██░ ██▒      ▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒
▓██░ ██▓▒▓██  ▒██░ ▓██▄   ▒██▀▀██░      ░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒
▒██▄█▓▒ ▒▓▓█  ░██░ ▒   ██▒░▓█ ░██         ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒
▒██▒ ░  ░▒▒█████▓▒██████▒▒░▓█▒░██▓      ▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░
▒▓▒░ ░  ░░▒▓▒ ▒ ▒▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒      ▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░
░▒ ░     ░░▒░ ░ ░░ ░▒  ░ ░ ▒ ░▒░ ░      ░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░     
░░        ░░░ ░ ░░  ░  ░   ░  ░░ ░      ░  ░  ░    ░   ░    ░   ▒   ░░       
            ░          ░   ░  ░  ░            ░      ░          ░  ░         

$(END)
endef
export PUSH_SWAP

.SILENT:

all: 			$(NAME)

$(NAME):		$(OBJECTS) $(OBJECTS_PF) $(INCLUDE)
				$(CC) $(CC_FLAGS) $(OBJECTS) $(OBJECTS_PF) -o $(NAME)
				mkdir ./objects/
				mkdir ./utils/objects/
				mv $(OBJECTS) ./objects/
				mv $(OBJECTS_PF) ./utils/objects/
				echo "\n\n··················· Compilation complete ···················"
				echo "$$PUSH_SWAP"

clean:
				rm -rf ./objects/
				rm -rf ./*.o
				rm -rf ./utils/objects/
				rm -rf ./utils/*.o
				echo "\n·······························"
				echo "\n· Objects correctly removed."

fclean:			clean
				rm -rf $(NAME)
				echo "· Executable correctly removed."

nl:
				echo "\n·······························"

re:				fclean nl all
.PHONY:			all clean fclean nl re
