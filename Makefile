NAME_SL		=	so_long

HEADER_SL	=	so_long.h

LIBFT		=	libft/libft.a

SRCS_SL		=	so_long.c map.c valid_utils.c

OBJS_SL		=	$(SRCS_SL:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY		:	all clean fclean re libft

all			:	libft $(NAME_SL)

libft		:
			@make -C libft/

$(NAME_SL)	:	$(OBJS_SL)
			$(CC) $(OBJS_SL) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $@

%.o			:	%.c $(LIBFT) $(HEADER_SL)
			$(CC) $(CFLAGS) -I $(HEADER_SL) -c $< -o $@

clean		:
			$(RM) $(OBJS_SL)
			make -C libft/ clean

fclean		:	clean
			$(RM) $(NAME_SL)
			make -C libft/ fclean

re			:	fclean all