NAME_SL		=	so_long
NAME_SLB	=	so_long_bonus

INCLUDES_SL	=	includes/
HEADER_SL	=	includes/so_long.h
HEADER_SLB	=	includes/so_long_bonus.h

LIBFT		=	libft/libft.a
DIR_SL		=	src/
DIR_SLB		=	bonus/

FILES_SL	=	so_long.c create_map.c valid_utils.c\
				game.c draw.c
FILES_SLB	=	so_long_bonus.c create_map_bonus.c valid_utils_bonus.c\
				game_bonus.c draw_bonus.c sprite_bonus.c \
				draw_enemy_bonus.c draw_enemy_bonus2.c

SRCS_SL		=	$(addprefix $(DIR_SL), $(FILES_SL))
SRCS_SLB	=	$(addprefix $(DIR_SLB), $(FILES_SLB))

OBJS_SL		=	$(SRCS_SL:%.c=%.o)
OBJS_SLB	=	$(SRCS_SLB:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY		:	all clean fclean re libft bonus

all			:	libft $(NAME_SL)

libft		:
			@make -C libft/

bonus		:
			@make NAME_SL="$(NAME_SLB)" \
			HEADER_SL="$(HEADER_SLB)" \
			OBJS_SL="$(OBJS_SLB)" all

$(NAME_SL)	:	$(OBJS_SL)
			$(CC) $(OBJS_SL) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $@

%.o			:	%.c $(LIBFT) $(HEADER_SL) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_SL) -c $< -o $@

clean		:
			$(RM) $(OBJS_SL) $(OBJS_SLB)
			make -C libft/ clean

fclean		:	clean
			$(RM) $(NAME_SL) $(NAME_SLB)
			make -C libft/ fclean

re			:	fclean all