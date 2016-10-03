# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 21:37:43 by jde-rus           #+#    #+#              #
#    Updated: 2015/05/29 08:19:33 by jde-rus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror

FW = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIB = $(LIB_PATH)libft.a

LIB_PATH = libft/

MINILIB = $(MINILIB_PATH)libmlx.a

MINILIB_PATH = minilibx_macos/

INCLUDES = -I $(LIB_PATH) -I ./include -I $(MINILIB_PATH)

NAME = wolf3d

SRC = main.c\
	  main_loop.c\
	  init_env.c\
	  init_image.c\
	  destroy_env.c\
	  get_map.c\
	  read_map.c\
	  ft_exit.c\
	  player_start.c\
	  expose_hook.c\
	  put_pxl_to_img.c\
	  render.c\
	  is_wall.c\
	  draw_line.c\
	  move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(MINILIB) $(OBJ)
	@gcc $(CFLAG) $(FW) $(SRC) $(INCLUDES) -L $(LIB_PATH) -lft -o $(NAME)
	@echo " - compilation ok - "

$(LIB):
	@make -C $(LIB_PATH)
	@echo " - make libft ok - "

$(MINILIB):
	@make -C $(MINILIB_PATH)
	@echo " - make minilib ok - "

$(OBJ): $(SRC) $(LIB) $(MINILIB)
	@gcc $(CFLAG) -c $(SRC) $(INCLUDES)

clean:
	@rm -rf $(OBJ)
	@make -C $(MINILIB_PATH) clean
	@make -C $(LIB_PATH) clean
	@echo " - clean ok - "

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo " - fclean ok - "

re: fclean all

