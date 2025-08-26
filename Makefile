# ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; #
#                                                                              #
#                        ______                                                #
#                     .-"      "-.                                             #
#                    /            \                                            #
#        _          |              |          _                                #
#       ( \         |,  .-.  .-.  ,|         / )                               #
#        > "=._     | )(__/  \__)( |     _.=" <                                #
#       (_/"=._"=._ |/     /\     \| _.="_.="\_)                               #
#              "=._ (_     ^^     _)"_.="                                      #
#                  "=\__|IIIIII|__/="                                          #
#                 _.="| \IIIIII/ |"=._                                         #
#       _     _.="_.="\          /"=._"=._     _                               #
#      ( \_.="_.="     `--------`     "=._"=._/ )                              #
#       > _.="                            "=._ <                               #
#      (_/                                    \_)                              #
#                                                                              #
#      Filename: Makefile                                                      #
#      By: espadara <espadara@pirate.capn.gg>                                  #
#      Created: 2025/08/23 15:29:20 by espadara                                #
#      Updated: 2025/08/26 11:24:51 by amoraru                                 #
#                                                                              #
# ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; #

CC = gcc

SRCS_PATH = srcs/

NAME = sealib.a

INC = -I ./includes/

FLAGS = -Wall -Wextra -Werror

SOURCES = sea_isalpha.c sea_isdigit.c sea_isalnum.c sea_isascii.c sea_isprint.c \


SRCS =  $(addprefix $(SRCS_PATH), $(SOURCES))

OBJ_PATH = objs/

OBJ = $(addprefix $(OBJ_PATH), $(SOURCES:.c=.o))


all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	echo "Binary $(NAME) created."
	echo "Making test"
	gcc test.c sealib.a -I includes

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	echo "Compilation of $(notdir $<)"
	/bin/mkdir -p `dirname $@`
	gcc -c $(FLAGS) $(INC) $< -o $@


clean:
	/bin/rm -rf $(OBJ_PATH)
	echo "$(NAME) objects removed"

fclean: clean
	/bin/rm -rf $(NAME)
	echo "Bin $(NAME) removed."
	/bin/rm -rf a.out
	echo "Test for $(NAME) removed."


re:             fclean all

.PHONY: all, clean, fclean, re
