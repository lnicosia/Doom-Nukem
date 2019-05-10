# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/05/10 11:31:51 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

MAKEFILE = Makefile

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_RAW = main.c doom.c free_all.c init_sdl.c clear_image.c render.c parsing.c \
		  screen_utils.c check_parsing.c view.c movement.c init_options.c \
		  options.c render_maths.c draw_functions.c minimap.c fps.c \
		  init_ttf.c get_slope.c movement_collision.c print_text.c \
		  vector_utils.c inputs.c init_keys.c init_pointers.c valid_map.c \
		  bmp_parser.c bmp_parser_utils.c check_bmp_parsing.c \
		  bmp_parse_header.c bmp_parse_pixel_data.c bmp_parse_color_table.c \
		  maths_utils.c fill_triangle.c color_utils.c clipping.c init_camera.c \

HEADERS = utils.h render.h collision.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -g3 -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		  -I $(LIBFT_DIR) \
		  -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers/ \
		  -I ~/Library/Frameworks/SDL2_ttf.framework/Versions/A/Headers/ \
		  #-fsanitize=address \
		  #-O3 \

DEBUG ?= 0

#ifeq ($(DEBUG), 1)
#	CFLAGS += -fsanitize=address
#endif

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
SDL = -F ~/Library/Frameworks/ -framework SDL2 \
	  -F ~/Library/Frameworks/ -framework SDL2_ttf \
	  #`sdl-config --cflags --libs` \

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all: 
	@make -C $(LIBFT_DIR)
	@make $(BIN_DIR)/$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(BIN_DIR)/$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(SDL) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled '$(BIN_DIR)/$(NAME)' with success!"${RESET}

clean: 
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}

fclean:
	@make fclean -C libft
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}
	@rm -Rf $(NAME)
	@echo ${CYAN}"[INFO] Removed $(BIN_DIR)/$(NAME)"${RESET}

re: fclean all

.PHONY: fclean all clean libft
