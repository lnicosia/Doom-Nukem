# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2020/01/08 11:46:10 by lnicosia         ###   ########.fr        #
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
SDL_DIR = SDL2-2.0.8/include
SDL_TTF_DIR = SDL2_ttf-2.0.15
SDL_MIXER_DIR = SDL2_mixer-2.0.4

LIBFT = $(LIBFT_DIR)/libft.a

SRC_GAME_RAW = main_game.c init_game.c draw_game.c doom.c enemy_utils.c \
				print_results.c projectile.c projectiles_maths.c draw_projectiles.c \
				keys.c init_weapons.c weapons.c draw_hud.c death.c \
				projectiles_collisions.c projectiles_utils.c \
		   		draw_projectile_no_light.c draw_projectile_color.c \
		   		draw_projectile_both.c draw_projectile_brightness.c \

SRC_EDITOR_RAW = main_editor.c editor.c init_editor.c \
		 draw_grid.c editor_keys.c grid_tools.c editor_render.c \
		 draw_grid_walls.c draw_grid_vertices.c \
		 get_existing_vertex.c add_vertex.c get_clockwise_order.c \
		 add_player.c editor_hud.c add_sector.c fill_new_sector.c \
		 save_map.c write_vertices.c write_sectors.c write_objects.c \
		 write_player.c write_enemies.c add_object.c editor_keyup.c \
		 player_selection.c objects_selection.c vertices_selection.c \
		 draw_grid_player.c draw_grid_objects.c \
		 is_new_vertex_valid.c add_enemy.c enemy_selection.c \
		 delete_object.c delete_action.c delete_enemy.c draw_grid_enemy.c \
		 fill_triangle.c editor_3d_keys.c wall_sprites_keys.c \
		 editor_start_game.c apply_texture.c selected_information.c \
		 editor_3d_keyup.c add_vertex_in_sector.c split_sector.c \
		 split_sector_utils.c selection_tab.c init_hud.c

SRC_ALL_RAW = init_sdl.c clear_image.c init_keys.c \
		   draw_line.c menu_tools.c screen_utils.c init_ttf.c init_textures.c \
		   print_text.c bmp_parser.c bmp_parser_wall.c \
		   bmp_parser_skybox.c bmp_parser_utils.c \
		   bmp_parse_header.c bmp_parse_pixel_data.c bmp_parse_color_table.c \
		   check_bmp_parsing.c keyup.c render_utils.c movement.c \
		   get_slope.c update_player_z.c movement_collision.c \
		   get_screen_sectors.c check_parsing.c view.c init_options.c \
		   minimap.c fps.c inputs.c init_editor_data.c \
		   valid_map.c game_menu.c get_sector.c draw_line_minimap.c \
		   fill_triangle_minimap.c color_utils.c camera.c \
		   print_debug.c init_animations.c vertices_utils.c \
		   map_parse_vertices.c is_in_sector.c map_parser_protection_utils.c \
		   map_parse_sectors.c map_parser_utils.c map_parse_sectors_utils.c \
		   physics.c map_parse_player.c create_portals.c \
		   init_sound.c draw_rectangle.c confirmation_box.c\
		   draw_objects.c sprites_maths.c draw_players.c \
		   map_parse_objects.c map_init_objects.c delete_vertex.c \
		   free_all.c map_parser.c animations.c map_init_enemies.c \
		   sprite_maths_enemies.c draw_enemies.c button.c delete_sector.c \
		   map_parse_enemies.c  draw_line_free.c render.c \
		   project_wall.c render_sector.c draw_ceiling.c draw_wall.c \
		   precompute_skybox.c draw_skybox.c draw_floor.c \
		   precompute_neighbors.c skybox_draw_functions.c \
		   movement_utils.c update_sprites_state.c \
		   select_line.c draw_wall_sprites.c input_box.c \
		   init_obj_enemies_data.c reset_selection.c \
		   draw_circle_free.c draw_circle.c ft_getchar.c \
		   objects_utils.c misc_utils.c \
		   gravity.c input_box_utils.c \
		   input_box_mouse.c delete_box_selection.c \
		   validate_input.c button_event.c player_keys.c init_weapons_sprites.c\
		   pop_events.c start_event.c event_updaters.c \
		   generate_mipmaps.c get_current_wall_map.c get_current_floor_map.c \
		   get_current_ceiling_map.c init_skybox.c init_sprites.c \
		   draw_floor_sprites.c draw_floor_sprites_no_light.c \
		   draw_floor_sprites_color.c draw_floor_sprites_brightness.c \
		   draw_floor_sprites_both.c \
		   draw_ceiling_sprites.c draw_ceiling_sprites_no_light.c \
		   draw_ceiling_sprites_color.c draw_ceiling_sprites_brightness.c \
		   draw_ceiling_sprites_both.c \
		   map_parse_floor_sprites.c map_parse_ceiling_sprites.c \
		   draw_vline_ceiling.c draw_vline_ceiling_brightness.c \
		   draw_vline_ceiling_both.c draw_vline_ceiling_color.c \
		   draw_vline_wall.c draw_vline_wall_brightness.c \
		   draw_vline_wall_both.c draw_vline_wall_color.c \
		   draw_vline_floor.c draw_vline_floor_brightness.c \
		   draw_vline_floor_both.c draw_vline_floor_color.c \
		   add_bullet_hole.c shift_bullet_hole.c get_bullet_hole_pos.c \
		   delete_bullet_hole.c shift_bullet_hole_events.c free_sector.c \
		   print_press_text.c modify_wall_sprite.c \
		   draw_wall_bullet_holes.c \

HEADERS = utils.h render.h collision.h bmp_parser.h map_parser.h object_types.h \
		  editor.h env.h save.h create_portals.h input_box_utils.h add_vertex.h \
		  wall_sprite_remover.h wall_sprite_modifier.h

SRC_GAME = $(addprefix $(SRC_DIR)/, $(SRC_GAME_RAW))
OBJ_GAME = $(addprefix $(OBJ_GAME_DIR)/, $(SRC_GAME_RAW:.c=.o))

SRC_EDITOR = $(addprefix $(SRC_DIR)/, $(SRC_EDITOR_RAW))
OBJ_EDITOR = $(addprefix $(OBJ_EDITOR_DIR)/, $(SRC_EDITOR_RAW:.c=.o))

SRC_ALL = $(addprefix $(SRC_DIR)/, $(SRC_ALL_RAW))
OBJ_ALL = $(addprefix $(OBJ_ALL_DIR)/, $(SRC_ALL_RAW:.c=.o))

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		  -I $(LIBFT_DIR) -I $(SDL_DIR) -I $(SDL_TTF_DIR) -I $(SDL_MIXER_DIR) \
		  -flto -Ofast \
		  #-fsanitize=address -g3 \
		  #-fdata-sections \
		  #-ffast-math \
		  #-funroll-loops \
	
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g3
endif

SDL_WINDOWS = /usr/local/bin/SDL2.dll \
              /usr/local/bin/SDL2_mixer.dll \
              /usr/local/bin/SDL2_ttf.dll \
              -L/usr/local/lib -lcygwin -lSDL2main \

SDL_OSX = -F ~/Library/Frameworks/ -framework SDL2 \
	  -F ~/Library/Frameworks/ -framework SDL2_ttf \
	  -F ~/Library/Frameworks/ -framework SDL2_mixer \
	  #`sdl-config --cflags --libs` \
	  RED := "\033[0;31m"

ifeq ($(OS), Windows_NT)
	SDL = $(SDL_WINDOWS)
else
	UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		SDL = $(SDL_OSX)
	else
		echo "Can only compile on Windows or MacOS"
		exit 1
	endif
endif

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
	@gcc $(CFLAGS) $(OBJ_EDITOR) $(OBJ_ALL) $(LIBFT) -o $(EDITOR_NAME) $(SDL)
	@echo ${GREEN}"[INFO] Compiled '$(EDITOR_DIR)/$(EDITOR_NAME)' with success!"${RESET}

$(GAME_NAME): $(LIBFT) $(OBJ_GAME_DIR) $(OBJ_ALL_DIR) $(OBJ_GAME) $(OBJ_ALL)
	@gcc $(CFLAGS) $(OBJ_GAME) $(OBJ_ALL) $(LIBFT) -o $(GAME_NAME) $(SDL)
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
