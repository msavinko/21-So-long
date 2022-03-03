NAME_SL		=	so_long

INCLUDES_SL	=	includes/
HEADER_SL	=	includes/so_long.h

LIBFT		=	libft/libft.a
DIR_SL		=	src/

FILES_SL	=	so_long.c create_map.c valid_utils.c\
				game.c draw.c

SRCS_SL		=	$(addprefix $(DIR_SL), $(FILES_SL))

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

%.o			:	%.c $(LIBFT) $(HEADER_SL) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_SL) -c $< -o $@

clean		:
			$(RM) $(OBJS_SL)
			make -C libft/ clean

fclean		:	clean
			$(RM) $(NAME_SL)
			make -C libft/ fclean

re			:	fclean all