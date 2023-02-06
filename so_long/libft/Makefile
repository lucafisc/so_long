FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_is_sign.c ft_lstnew_int.c ft_is_space.c ft_atoli.c ft_power.c ft_itobin.c ft_bintoi.c get_next_line.c get_next_line_utils.c
B_FILES = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstadd_front_bonus.c ft_lstmap_bonus.c
OBJECTS = ${FILES:.c=.o}
B_OBJECTS = ${B_FILES:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME) bonus

$(NAME): ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

bonus: ${B_OBJECTS}
	ar rcs ${NAME} ${B_OBJECTS}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	rm -f ${OBJECTS} ${B_OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all
