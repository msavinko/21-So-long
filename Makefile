NAME_SL		=	so_long

HEADER_SL	=	so_long.h

LIBFT		=	libft/libft.a
PRINTF		=	ft_printf/libftprintf.a

SRCS_SL		=	so_long.c

OBJS_SL		=	$(SRCS_SL:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY		:	all clean fclean re libft printf

all			:	libft printf $(NAME_SL)

libft		:
			@make -C libft/

printf		:
			@make -C ft_printf/

$(NAME_SL)	:	$(OBJS_SL)
			$(CC) $(OBJS_SL) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $@

%.o			:	%.c $(LIBFT) $(PRINTF) $(HEADER_SL)
			$(CC) $(CFLAGS) -I $(HEADER_SL) -c $< -o $@

clean		:
			$(RM) $(OBJS_SL)
			make -C libft/ clean
			make -C ft_printf/ clean

fclean		:	clean
			$(RM) $(NAME_SL)
			make -C libft/ fclean
			make -C ft_printf/ fclean

re			:	fclean all