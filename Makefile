SRCS	= ft_strtrim.c ft_putnbr_fd.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl.c ft_strdup.c ft_strlen.c ft_substr.c ft_strnew.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= libft.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm