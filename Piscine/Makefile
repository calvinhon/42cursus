#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := y
CC        := o
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      C00/ex00/ft_putchar.c \
                          C00/ex01/ft_print_alphabet.c \
                          C00/ex02/ft_print_reverse_alphabet.c \
                          C00/ex03/ft_print_numbers.c \
                          C00/ft_is_negative.c \
                          C00/test.c \
                          C01/ex00/ft_ft.c \
                          C01/ex01/ft_ultimate_ft.c \
                          C01/ex02/ft_swap.c \
                          C01/ex03/ft_div_mod.c \
                          C01/ex06/ft_strlen.c \
                          C01/ft_putstr.c \
                          C03/ft_strlcat.c \
                          C03/ft_strstr.c \
                          C04/ex00/ft_strlen.c \
                          C04/ex02/ft_putnbr.c \
                          C04/ex03/ft_atoi.c \
                          C04/ex04/ft_putnbr_base.c \
                          C04/ex05/ft_atoi_base.c \
                          C05/ex02/ft_iterative_power.c \
                          C05/ex03/ft_recursive_power.c \
                          C05/ex04/ft_fibonacci.c \
                          C05/ex05/ft_sqrt.c \
                          C05/ex06/ft_is_prime.c \
                          C05/ex07/ft_find_next_prime.c \
                          Repo/C04/ex00/ft_strlen.c \
                          Repo/C04/ex01/ft_putstr.c \
                          Repo/C04/ex02/ft_putnbr.c \
                          Repo/C04/ex03/ft_atoi.c \
                          Repo/C04/ex04/ft_putnbr_base.c \
                          Repo/C04/ex05/ft_atoi_base.c \
                          Repo/C04/Test/v1_ft_putnbr_base.c \
                          Repo/C07/ex00/ft_strdup.c \
                          Repo/C07/ex01/ft_range.c \
                          Repo/C07/ex02/ft_ultimate_range.c \
                          Repo/C07/ex03/ft_strjoin.c \
                          Repo/C07/ex04/ft_convert_base.c \
                          Repo/C07/ex04/ft_convert_base2.c \
                          Rush00/ex00/ft_putchar.c \
                          Rush00/ex00/main.c \
                          Rush00/ex00/rush04.c \
                          test/Rush00/ex00/ft_putchar.c \
                          test/Rush00/ex00/main.c \
                          test/Rush00/ex00/rush04.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


