# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 17:33:17 by msanjuan          #+#    #+#              #
#    Updated: 2021/12/01 16:13:05 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS = 01_Errors/check_digit.c \
		01_Errors/check_quotes.c \
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
		04_Algorithms/big_sort.c \
		04_Algorithms/20numbers.c \
		05_Utils/find_min.c \
		05_Utils/isolate_lowest.c \
		05_Utils/find_index.c \
		05_Utils/find_max.c \
		05_Utils/sort_copy.c \
		05_Utils/big_sort_utils.c \
		06_Opti/ra_or_rr.c \
		06_Opti/rra_or_rrr.c \
		06_Opti/rra_or_ra.c \
		06_Opti/sa_or_ss.c \


OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -g -Wall -Werror -Wextra #-MMD
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = push_swap
RM = rm -f

# /* ~~~~~~~ BONUS ~~~~~~~ */
BONUS = checker
BONUS_DIR = ./bonus/
BONUS_SRCS = checker.c \
		get_next_line.c \
		get_next_line_utils.c \
		double_op_exception.c \

B_OBJS = ${addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o}}

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

$(BONUS): $(OBJS) $(B_OBJS)
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) $(BONUS_DIR)bonus_main.c $(IFLAGS) $(LFLAGS) -o $(BONUS)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} ${B_OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME} a.out
		@${RM} ${B_OBJS} ${BONUS} a.out

re: 	fclean all

.PHONY: all clean fclean re