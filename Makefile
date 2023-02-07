# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 01:37:41 by nverbrug          #+#    #+#              #
#    Updated: 2021/04/21 16:49:40 by nverbrug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = ./minilibx/libmlx.a

LIBFT = ./libft/libft.a

SRC = srcs/main.c\
	srcs/init_struct.c \
	srcs/parse_info.c \
	srcs/def_visual.c \
	srcs/def_textures.c \
	srcs/raycast.c \
	srcs/command.c \
	srcs/error.c \
	srcs/def_position.c \
	srcs/free.c \
	srcs/sprites_1.c \
	srcs/sprites_2.c \
	srcs/parse_map.c \
	srcs/bmp.c

OBJ = $(SRC:.c=.o)

FT_FLAGS = -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework Appkit -L mlx

all:
	@make -C ./minilibx
	@make -C ./libft
	@gcc -o $(NAME) -I./ $(FT_FLAGS) $(FLAGS) $(SRC) $(LIBFT) $(MLX)
	@echo "Compilation\t\t\t\033[0;32m[OK]\033[0m"

clean:
	@make -C ./minilibx clean
	@make -C ./libft clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@echo "Cleaning Objects\t\t\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf screenshot.bmp
	@echo "Cleaning bmp file\t\t\t\033[0;32m[OK]\033[0m"
	@rm -rf ${NAME}
	@echo "Cleaning exec\t\t\t\t\033[0;32m[OK]\033[0m"

re: fclean all

phony: all clean fclean re
