# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2020/02/04 11:47:36 by sipatry          ###   ########.fr        #
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
FMOD_LIB_DIR = sound_lib
FMOD_INC_DIR = sound_inc

LIBFT = $(LIBFT_DIR)/libft.a

SRC_GAME_RAW = main_game.c init_game.c draw_game.c doom.c enemy_utils.c \
				print_results.c projectile.c projectiles_maths.c \
				draw_projectiles.c \
				keys.c init_weapons.c weapons.c draw_hud.c death.c \
				projectiles_collisions.c projectiles_utils.c \
		   		draw_projectile_no_light.c draw_projectile_color.c \
		   		draw_projectile_both.c draw_projectile_brightness.c \
				explosion.c init_events_map.c draw_explosion.c \
				explosion_maths.c \

SRC_EDITOR_RAW = main_editor.c editor.c init_editor.c \
		 draw_grid.c editor_keys.c grid_tools.c editor_render.c \
		 draw_grid_walls.c draw_grid_vertices.c \
		 get_existing_vertex.c add_vertex.c print_target_functions2.c \
		 add_player.c editor_hud.c add_sector.c fill_new_sector.c \
		 save_map.c write_vertices.c write_sectors.c write_objects.c \
		 write_player.c write_enemies.c add_object.c editor_keyup.c \
		 player_selection.c objects_selection.c vertices_selection.c \
		 draw_grid_player.c draw_grid_objects.c events_tab_conditions.c \
		 is_new_vertex_valid.c add_enemy.c enemy_selection.c \
		 delete_object.c delete_action.c delete_enemy.c draw_grid_enemy.c \
		 fill_triangle.c editor_3d_keys.c wall_sprites_keys.c \
		 editor_start_game.c apply_texture.c \
		 editor_3d_keyup.c add_vertex_in_sector.c split_sector.c \
		 write_events.c init_print_target_data.c print_event_condition.c \
		 write_events_utils.c write_events_utils2.c init_events_writers.c \
		 write_event_conditions.c write_event_conditions_utils.c \
		 write_event_conditions_utils2.c init_event_conditions_writers.c \
		 write_events_links.c print_target_functions.c \
		 split_sector_utils.c selection_tab.c init_hud_button.c\
		 editor_hud_buttons.c init_hud_button_function.c editor_floor_tabs.c \
		 editor_ceiling_tabs.c editor_player_tabs.c editor_wall_tabs.c \
		 init_editor_tab_buttons.c editor_ceiling_tab_button.c \
		 editor_floor_tab_button.c editor_wall_tab_button.c \
		 editor_env_wall_buttons.c editor_env_floor_buttons.c \
		 editor_env_ceilling_buttons.c  change_editor_mode.c \
		 editor_3d_button_keys.c editor_3d_button_keyup.c enemy_tab.c \
		 init_add_buttons.c editor_env_sector_buttons.c \
		 editor_sector_tab_button.c editor_sector_tabs.c editor_button_keys.c \
		 editor_button_keyup.c editor_env_player_buttons.c \
		 editor_player_tab_button.c editor_enemy_tabs.c \
		 editor_env_enemy_buttons.c editor_enemy_tab_button.c \
		 editor_object_tabs.c editor_env_object_buttons.c \
		 sprite_selection.c init_sprite_selection_buttons.c\
		 editor_object_tab_button.c print_events_tabs.c \
		 init_events_selection_buttons.c print_event.c init_event_types.c \
		 are_condition_selection_buttons_visible.c init_event_links_types.c \
		 print_link_target_functions.c print_condition_target_functions.c \
		 print_condition_target_functions2.c init_print_condition_target_data.c\
		 change_sprite_buttons.c input_box_checkers.c input_box_updaters.c \
		 update_textures_buttons.c init_skybox_selection_buttons.c \
		 draw_editor_tabs.c new_tabs_position.c editor_buttons_functions.c \

SRC_ALL_RAW = init_sdl.c clear_image.c init_keys.c update_sprites.c \
		   draw_line.c menu_tools.c screen_utils.c init_ttf.c init_textures.c \
		   print_text.c bmp_parser.c bmp_parser_wall.c update_sprites_light.c \
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
		   sound_utils.c draw_rectangle.c confirmation_box.c\
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
		   objects_utils.c misc_utils.c map_parse_events.c \
		   gravity.c input_box_utils.c init_ui_textures.c \
		   input_box_mouse.c delete_box_selection.c \
		   validate_input.c button_event.c player_keys.c init_weapons_sprites.c\
		   pop_events.c start_event.c event_updaters.c \
		   generate_mipmaps.c get_current_wall_map.c get_current_floor_map.c \
		   get_current_ceiling_map.c init_skybox.c init_sprites.c \
		   draw_floor_sprites.c draw_floor_sprites_no_light.c \
		   draw_floor_sprites_color.c draw_floor_sprites_brightness.c \
		   draw_floor_sprites_both.c bmp_parser_ui.c bmp_parser_ui_enemies.c \
		   bmp_parser_ui_objects.c bmp_parser_ui_skyboxes.c \
		   draw_ceiling_sprites.c draw_ceiling_sprites_no_light.c \
		   draw_ceiling_sprites_color.c draw_ceiling_sprites_brightness.c \
		   draw_ceiling_sprites_both.c get_clockwise_order.c \
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
		   draw_wall_bullet_holes.c intersect_maths.c \
		   equals_condition.c less_condition.c greater_condition.c \
		   less_or_equals_condition.c greater_or_equals_condition.c \
		   event_ended_condition.c event_ended_start_condition.c \
		   different_condition.c init_events.c init_events_parser.c \
		   new_global_event.c new_press_event.c new_shoot_event.c \
		   new_stand_event.c new_walk_in_event.c new_walk_out_event.c \
		   new_death_event.c parse_event_target.c \
		   init_events_parser_target_types.c parse_event_launch_conditions.c \
		   sector_parser.c enemy_parser.c wall_sprite_parser.c wall_parser.c \
		   vertex_parser.c set_event_target.c floor_sprite_parser.c \
		   ceiling_sprite_parser.c set_event_target2.c weapon_parser.c \
		   object_parser.c parse_event_type.c parse_event_various_data.c \
		   set_condition_target.c set_condition_target2.c \
		   init_events_parser_target_parsers.c parse_event_exec_conditions.c \
		   init_events_parser_checkers.c init_events_parser_updaters.c \
		   event_checkers.c check_vertex_event.c intersects_with_player.c \
		   parse_events_links.c events_links_protection.c set_event_link.c \
		   get_event_array.c get_event_nb.c init_objects_main_sprites.c \
		   precompute_floor_ceiling_sprites_scales.c \

HEADERS = utils.h render.h collision.h bmp_parser.h map_parser.h object_types.h \
		  editor.h env.h save.h create_portals.h input_box_utils.h add_vertex.h \
		  wall_sprite_remover.h wall_sprite_modifier.h events_conditions.h \
		  events_parser.h \

SRC_GAME = $(addprefix $(SRC_DIR)/, $(SRC_GAME_RAW))
OBJ_GAME = $(addprefix $(OBJ_GAME_DIR)/, $(SRC_GAME_RAW:.c=.o))

SRC_EDITOR = $(addprefix $(SRC_DIR)/, $(SRC_EDITOR_RAW))
OBJ_EDITOR = $(addprefix $(OBJ_EDITOR_DIR)/, $(SRC_EDITOR_RAW:.c=.o))

SRC_ALL = $(addprefix $(SRC_DIR)/, $(SRC_ALL_RAW))
OBJ_ALL = $(addprefix $(OBJ_ALL_DIR)/, $(SRC_ALL_RAW:.c=.o))

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDES_DIR) \
		  -I $(LIBFT_DIR) -I $(SDL_DIR) -I $(SDL_TTF_DIR) -I $(FMOD_INC_DIR)\
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
              /usr/local/bin/SDL2_ttf.dll \
              -L/usr/local/lib -lcygwin -lSDL2main \

SDL_OSX = -F ~/Library/Frameworks/ -framework SDL2 \
	  -F ~/Library/Frameworks/ -framework SDL2_ttf \
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
	@gcc $(CFLAGS) $(OBJ_EDITOR) $(OBJ_ALL) $(LIBFT) -o $(EDITOR_NAME) $(SDL) sound_lib/libfmod.dylib sound_lib/libfmodL.dylib
	@install_name_tool -add_rpath @executable_path/sound_lib $(EDITOR_NAME)
	@echo ${GREEN}"[INFO] Compiled '$(EDITOR_DIR)/$(EDITOR_NAME)' with success!"${RESET}

$(GAME_NAME): $(LIBFT) $(OBJ_GAME_DIR) $(OBJ_ALL_DIR) $(OBJ_GAME) $(OBJ_ALL)
	@gcc $(CFLAGS) $(OBJ_GAME) $(OBJ_ALL) $(LIBFT) -o $(GAME_NAME) $(SDL) sound_lib/libfmod.dylib sound_lib/libfmodL.dylib
	@install_name_tool -add_rpath @executable_path/sound_lib $(GAME_NAME)
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
