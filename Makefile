SRCS		= ft_printf.c \
		  ./srcs/ft_printf_utils.c \
		  ./srcs/ft_printf_utils2.c \
		  ./srcs/ft_printf_utils3.c \
		  ./srcs/ft_precision.c \
		  ./srcs/ft_precision2.c \
		  ./srcs/ft_parser.c \

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

RM			= rm -f

CFLAGS		=  -Wall -Werror -Wextra -c -Iincludes

CC			= gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
