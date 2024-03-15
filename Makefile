# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 22:16:34 by minkylee          #+#    #+#              #
#    Updated: 2024/02/20 20:36:52 by taehkwon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = get_next_line/get_next_line.c\
        get_next_line/get_next_line_utils.c\
        main.c\
        parsing/map_parsing.c\
		parsing/map_validation.c\
		parsing/path_and_color.c\
		parsing/path.c\
		parsing/color.c\
		parsing/utils.c\
		parsing/mk_split.c\
		parsing/put_img.c\
		parsing/read_and_copy.c\
		raycast/add_values.c\
		raycast/algorithms.c\
		raycast/draw_texture.c\
		raycast/movement.c\
		raycast/run_cub3d.c\
		raycast/update_key_status.c\
		raycast/utils_init.c\
		raycast/utils_raycasting.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_DIR = ./mlx
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c cub3d.h
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		$(MAKE) -C $(MLX_DIR)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

$(LIBFT):
		$(MAKE) -j -C ./libft

all: $(NAME)

clean:
		rm -rf $(OBJS)
		$(MAKE) -C ./libft clean
		$(MAKE) -C $(MLX_DIR) clean

fclean: clean
		rm -rf $(NAME)
		$(MAKE) -C ./libft fclean

re:
		make fclean
		make all

.PHONY: all clean fclean re
