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

SOURCES				=	push_swap.c \

OBJECTS				=	$(SOURCES:%.c=%.o)

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

$(NAME):		$(OBJECTS) $(INCLUDE)
				$(CC) $(CC_FLAGS) $(OBJECTS) -o $(NAME)
				mkdir ./objects/
				mv $(OBJECTS) ./objects/
				echo "\n\n··················· Compilation complete ···················"
				echo "$$PUSH_SWAP"

clean:
				rm -rf ./objects/
				rm -rf ./*.o
				echo "\n·······························"
				echo "\n· Objects correctly removed."

fclean:			clean
				rm -rf $(NAME)
				echo "· Executable correctly removed."

nl:
				echo "\n·······························"

re:				fclean nl all
.PHONY:			all clean fclean nl re
