# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 17:33:17 by msanjuan          #+#    #+#              #
#    Updated: 2021/10/26 14:26:41 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS = 01_Errors/check_digit.c \
		01_Errors/check_duplicates.c \
		01_Errors/check_int_size.c \
		01_Errors/check_sorted.c \
		02_Format/format_list.c \
		02_Format/display_stack.c \
		02_Format/free_stacks.c \
		03_Operations/swap_op.c \
		03_Operations/rotate_op.c \
		03_Operations/reverse_op.c \
		03_Operations/push_op.c \
		04_Algorithms/2numbers.c \
		04_Algorithms/parsing.c \
		04_Algorithms/3numbers.c \
		04_Algorithms/4numbers.c \
		04_Algorithms/5numbers.c \
		04_Algorithms/6_and_more.c \
		05_Utils/find_lowest.c \
		05_Utils/isolate_lowest.c \
		

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}
# OBJ_DIR = ./obj
# OBJS =  ${SRCS:.c=$(OBJDIR)/%.o}
# OBJS = ${SRCS:${SRCS_DIR}/%.c=$(OBJDIR)/%.o}
# OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -Wall -Werror -Wextra #-MMD
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = push_swap
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

# vpath %.c ${addprefix ${SRCS_DIR}, 01_Errors/, 02_format/, 03_Operations/, 04_Algorithms/, 05_Utils/}

all:	${NAME}		

$(NAME): $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

# ${OBJ_DIR}/%.o:%.c | ${OBJ_DIR}
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR):
# 			@mkdir -p $@

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME} a.out

re: 	fclean all

.PHONY: all clean fclean re