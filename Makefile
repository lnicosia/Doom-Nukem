# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/07/22 16:18:39 by sipatry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom

EDITOR = editor

MAKEFILE = Makefile

SRC_DIR = src
OBJ_DIR = obj

SRC_EDIT = src_edit
OBJ_EDIT = obj_edit

SRC_ALL = src_all
OBJ_ALL = obj_all

INCLUDES_DIR = includes
BIN_DIR = .

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_RAW = main.c doom.c free_all.c render.c map_parser.c screen_utils.c \
		  check_parsing.c view.c movement.c init_options.c \
		  options.c render_maths.c draw_functions.c minimap.c fps.c \
		  init_ttf.c get_slope.c movement_collision.c print_text.c \
		  vector_utils.c inputs.c init_keys.c valid_map.c \
		  bmp_parser.c bmp_parser_utils.c check_bmp_parsing.c \
		  bmp_parse_header.c bmp_parse_pixel_data.c bmp_parse_color_table.c \
		  maths_utils.c fill_triangle.c color_utils.c clipping.c camera.c \
		  keys.c print_debug.c intersections.c init_animations.c \
		  get_screen_sectors.c draw_line.c map_parse_vertices.c \
		  map_parse_sectors.c map_parser_utils.c map_parse_sectors_utils.c \
		  init_textures.c weapons.c physics.c init_weapons.c \
		  init_program.c draw.c menu.c init_sound.c init_sprites.c \
		  init_screen_pos.c draw_sprites.c sprites_maths.c \
		  map_parse_objects.c draw_hud.c raycasting.c map_init_objects.c \

SRC_ERAW = main.c init_edition.c

SRC_ARAW = init_sdl.c clear_image.c init_pointers.c

HEADERS = utils.h render.h collision.h bmp_parser.h map_parser.h object_types.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))

SRCE = $(addprefix $(SRC_EDIT)/, $(SRC_ERAW))
OBJE = $(addprefix $(OBJ_EDIT)/, $(SRC_ERAW:.c=.o))

SRCA = $(addprefix $(SRC_ALL)/, $(SRC_ARAW))
OBJA = $(addprefix $(OBJ_ALL)/, $(SRC_ARAW:.c=.o))

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		  -I $(LIBFT_DIR) \
		  -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers/ \
		  -I ~/Library/Frameworks/SDL2_ttf.framework/Versions/A/Headers/ \
		  -I ~/Library/Frameworks/SDL2_mixer.framework/Versions/A/Headers/ \
		  -flto -Ofast \
		  #-fsanitize=address -g3 \

DEBUG ?= 0

#ifeq ($(DEBUG), 1)
#	CFLAGS += -fsanitize=address
#endif

SDL = -F ~/Library/Frameworks/ -framework SDL2 \
	  -F ~/Library/Frameworks/ -framework SDL2_ttf \
	  -F ~/Library/Frameworks/ -framework SDL2_mixer \
	  #`sdl-config --cflags --libs` \

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all: editor game

libft:
	@make -C $(LIBFT_DIR) -j8

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) -j8

$(OBJ_EDIT):
	@mkdir -p $(OBJ_EDIT) -j8

$(OBJ_ALL):
	@mkdir -p $(OBJ_ALL) -j8

$(OBJ_ALL)/%.o: $(SRC_ALL)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_EDIT)/%.o: $(SRC_EDIT)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

editor: libft $(OBJ_EDIT) $(OBJ_ALL) $(OBJE) $(OBJA) $(LIBFT)
	@gcc  -pg $(CFLAGS) $(OBJA) $(OBJE) $(LIBFT) $(SDL) -o $(EDITOR)
	@echo ${GREEN}"[INFO] Compiled '$(BIN_DIR)/$(EDITOR)' with success!"${RESET}

game: libft $(OBJ_DIR) $(OBJ) $(OBJ_ALL) $(OBJA) $(LIBFT)
	@gcc  -pg $(CFLAGS) $(OBJ) $(OBJA) $(LIBFT) $(SDL) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled '$(BIN_DIR)/$(NAME)' with success!"${RESET}

clean: 
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@rm -f $(OBJE)
	@rm -Rf $(OBJ_EDIT)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}

fclean:
	@make fclean -C libft
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_EDIT)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}
	@rm -Rf $(NAME)
	@rm -Rf $(EDITOR)
	@echo ${CYAN}"[INFO] Removed $(BIN_DIR)/$(NAME)"${RESET}

re: fclean all

.PHONY: fclean all editor game clean libft
