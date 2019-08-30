# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/08/30 14:13:17 by sipatry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GAME_NAME = doom

EDITOR_NAME = doom_editor

MAKEFILE = Makefile

SRC_DIR = src
OBJ_GAME_DIR = obj_game
OBJ_EDITOR_DIR = obj_editor
OBJ_ALL_DIR = obj_all
INCLUDES_DIR = includes
GAME_DIR = .
EDITOR_DIR = .
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_GAME_RAW = main_game.c init_game.c draw_game.c doom.c enemy_utils.c \

SRC_EDITOR_RAW = main_editor.c editor.c init_editor.c \
				 draw_grid.c editor_keys.c grid_tools.c editor_render.c \
				 draw_grid_walls.c draw_circle.c draw_grid_vertices.c \
				 get_existing_vertex.c add_vertex.c get_clockwise_order.c \
				 add_player.c editor_hud.c add_sector.c fill_new_sector.c \
				 save_map.c write_vertices.c write_sectors.c write_objects.c \
				 write_player.c add_object.c editor_options.c \
				 player_selection.c objects_selection.c vertices_selection.c \
				 draw_grid_player.c draw_grid_objects.c create_portals.c \
				 is_new_vertex_valid.c delete_sector.c vertices_utils.c \
				 delete_vertex.c delete_object.c

SRC_ALL_RAW = init_sdl.c clear_image.c init_pointers.c init_keys.c keys.c inputs.c \
		   draw_line.c menu_tools.c screen_utils.c init_ttf.c init_textures.c \
		   print_text.c bmp_parser.c bmp_parser_utils.c \
		   bmp_parse_header.c bmp_parse_pixel_data.c bmp_parse_color_table.c \
		   check_bmp_parsing.c options.c raycasting.c render.c movement.c \
		   get_slope.c maths_utils.c movement_collision.c weapons.c \
		   get_screen_sectors.c check_parsing.c view.c init_options.c \
		   render_maths.c draw_functions.c minimap.c fps.c \
		   valid_map.c game_menu.c get_sector.c draw_line_minimap.c \
		   fill_triangle.c color_utils.c clipping.c camera.c \
		   print_debug.c intersections.c init_animations.c \
		   map_parse_vertices.c is_in_sector.c map_parser_protection_utils.c \
		   map_parse_sectors.c map_parser_utils.c map_parse_sectors_utils.c \
		   physics.c init_weapons.c map_parse_player.c \
		   init_sound.c init_sprites.c \
		   init_screen_pos.c draw_sprites.c sprites_maths.c \
		   map_parse_objects.c draw_hud.c map_init_objects.c \
		   free_all.c map_parser.c


HEADERS = utils.h render.h collision.h bmp_parser.h map_parser.h object_types.h \
		  editor.h env.h save.h create_portals.h

SRC_GAME = $(addprefix $(SRC_DIR)/, $(SRC_GAME_RAW))
OBJ_GAME = $(addprefix $(OBJ_GAME_DIR)/, $(SRC_GAME_RAW:.c=.o))

SRC_EDITOR = $(addprefix $(SRC_DIR)/, $(SRC_EDITOR_RAW))
OBJ_EDITOR = $(addprefix $(OBJ_EDITOR_DIR)/, $(SRC_EDITOR_RAW:.c=.o))

SRC_ALL = $(addprefix $(SRC_DIR)/, $(SRC_ALL_RAW))
OBJ_ALL = $(addprefix $(OBJ_ALL_DIR)/, $(SRC_ALL_RAW:.c=.o))

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		  -I $(LIBFT_DIR) \
		  -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers/ \
		  -I ~/Library/Frameworks/SDL2_ttf.framework/Versions/A/Headers/ \
		  -I ~/Library/Frameworks/SDL2_mixer.framework/Versions/A/Headers/ \
		  -fsanitize=address -g3 \
		  #-flto -Ofast \

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

all:
	@make -C $(LIBFT_DIR) -j8
	@make $(GAME_DIR)/$(GAME_NAME) -j8
	@make $(EDITOR_DIR)/$(EDITOR_NAME) -j8

game:
	@make -C $(LIBFT_DIR) -j8
	@make $(GAME_DIR)/$(GAME_NAME) -j8

editor:
	@make -C $(LIBFT_DIR) -j8
	@make $(EDITOR_DIR)/$(EDITOR_NAME) -j8

($LIBFT):
	@make -C $(LIBFT_DIR) -j8

$(OBJ_GAME_DIR):
	@mkdir -p $(OBJ_GAME_DIR)

$(OBJ_EDITOR_DIR):
	@mkdir -p $(OBJ_EDITOR_DIR)

$(OBJ_ALL_DIR):
	@mkdir -p $(OBJ_ALL_DIR)

$(OBJ_ALL_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_GAME_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_EDITOR_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@gcc -c $< -o $@ $(CFLAGS) 

$(EDITOR_NAME): $(LIBFT) $(OBJ_EDITOR_DIR) $(OBJ_ALL_DIR) $(OBJ_EDITOR) $(OBJ_ALL)
	@gcc  -pg $(CFLAGS) $(OBJ_EDITOR) $(OBJ_ALL) $(LIBFT) $(SDL) -o $(EDITOR_NAME)
	@echo ${GREEN}"[INFO] Compiled '$(EDITOR_DIR)/$(EDITOR_NAME)' with success!"${RESET}

$(GAME_NAME): $(LIBFT) $(OBJ_GAME_DIR) $(OBJ_ALL_DIR) $(OBJ_GAME) $(OBJ_ALL)
	@gcc  -pg $(CFLAGS) $(OBJ_GAME) $(OBJ_ALL) $(LIBFT) $(SDL) -o $(GAME_NAME)
	@echo ${GREEN}"[INFO] Compiled '$(GAME_DIR)/$(GAME_NAME)' with success!"${RESET}

clean: 
	@make clean -C libft
	@rm -Rf $(OBJ_ALL_DIR)
	@rm -Rf $(OBJ_EDITOR_DIR)
	@rm -Rf $(OBJ_GAME_DIR)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}

fclean:
	@make fclean -C libft
	@rm -Rf $(OBJ_ALL_DIR)
	@rm -Rf $(OBJ_EDITOR_DIR)
	@rm -Rf $(OBJ_GAME_DIR)
	@echo ${CYAN}"[INFO] Removed objs"${RESET}
	@rm -Rf $(GAME_DIR)/$(GAME_NAME)
	@rm -Rf $(EDITOR_DIR)/$(EDITOR_NAME)
	@echo ${CYAN}"[INFO] Removed $(GAME_DIR)/$(GAME_NAME) and $(EDITOR_DIR)/$(EDITOR_NAME)"${RESET}

re: fclean all

.PHONY: fclean all clean libft
