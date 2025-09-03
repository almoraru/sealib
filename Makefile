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
#      Updated: 2025/09/03 13:56:52 by espadara                                #
#                                                                              #
# ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; #

CC = gcc

SRCS_PATH = srcs/

NAME = sealib.a

INC = -I ./includes/

FLAGS = -Wall -Wextra -Werror -msse2

SOURCES = sea_isalpha.c sea_isdigit.c sea_isalnum.c sea_isascii.c sea_isprint.c \
	sea_strlen.c sea_memset.c sea_bzero.c sea_memcpy.c sea_memmove.c			\
	sea_strcpy.c sea_strncpy.c sea_strlcpy.c sea_strlcat.c sea_toupper.c 		\
	sea_tolower.c sea_strchr.c sea_strrchr.c sea_strstr.c sea_strncmp.c			\
	sea_strcmp.c sea_strnstr.c sea_memchr.c	sea_memcmp.c sea_atoi.c 			\
	sea_iswhitespace.c sea_atoi_base.c sea_atof.c sea_arena_init.c				\
	sea_arena_alloc.c sea_arena_free.c sea_memcpy_fast.c sea_strdup.c			\
	sea_strsub.c sea_strjoin.c sea_strtrim.c sea_split.c sea_itoa.c				\
	sea_strmapi.c sea_striteri.c sea_putchar_fd.c sea_putstr_fd.c				\
	sea_putnbr_fd.c sea_putendl_fd.c sea_lstnew.c sea_lstadd_front.c			\
	sea_lstsize.c

SRCS =  $(addprefix $(SRCS_PATH), $(SOURCES))

OBJ_PATH = objs/

OBJ = $(addprefix $(OBJ_PATH), $(SOURCES:.c=.o))


all: $(NAME) test

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "Binary $(NAME) created."

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@echo "Compilation of $(notdir $<)"
	/bin/mkdir -p `dirname $@`
	gcc -c $(FLAGS) $(INC) $< -o $@

test:
	@echo "Making test"
	gcc test.c sealib.a -I includes -lbsd -fsanitize=address

clean:
	/bin/rm -rf $(OBJ_PATH)
	@echo "$(NAME) objects removed"

fclean: clean
	/bin/rm -rf $(NAME)
	@echo "Bin $(NAME) removed."
	/bin/rm -rf a.out
	@echo "Test for $(NAME) removed."


re:             fclean all

.PHONY: all, clean, fclean, re test
