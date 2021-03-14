NAME = cub3D

SRCS = main.c\
			check_args.c\
			get_window_pars.c\
			read_file.c\
			ft_init.c\
			get_color.c\
			get_texture_and_spr.c\
			utils.c\
			get_map.c\
			parsing_map.c\
			player.c\
			parser.c\
			vector_sprite.c\
			event.c\
			utils_two.c\
			move_player.c\
			drow_cel_floor.c\
			sprite.c\
			sprite2.c\
			sprite3.c\
			screenshoot.c\
			free.c\
			rays.c\
			rays2.c

OBJS = $(SRCS:.c=.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDEH = -I minilibx

MLX_DIR = minilibx_opengl_20191021

%.o: %.c
	$(GCC) $(INCLUDEH) -c $<  -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_opengl_20191021
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L libft -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

bonus: all

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -f screen_save.bmp

re: fclean all

run:
	./cub3D map.cub

norm:
	norminette *.c
	norminette ./libft/*.c
	norminette *.h
	norminette ./libft/*.h

.PHONY:	all bonus clean fclean re norm run
