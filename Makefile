# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2020/03/12 14:40:32 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GAME_NAME = doom-nukem

EDITOR_NAME = doom_editor

MAKEFILE = Makefile

SRC_DIR = src
OBJ_GAME_DIR = obj_game
OBJ_EDITOR_DIR = obj_editor
OBJ_ALL_DIR = obj_all
FONTS_DIR = fonts
MAPS_DIR = maps
AUDIO_DIR = audio
INCLUDES_DIR = includes
IMAGES_DIR = images
TEXTURES_DIR = textures
SPRITES_DIR = sprites
SKYBOXES_DIR = skyboxes
HUD_DIR = HUD
UI_DIR = ui
GUN_DIR = gun
RAYGUN_DIR = raygun
SHOTGUN_DIR = shotgun
GAME_DIR = .
EDITOR_DIR = .
LIBFT_DIR = libft
SDL_DIR = SDL2-2.0.8/include
SDL_TTF_DIR = SDL2_ttf-2.0.15
FMOD_LIB_DIR = sound_lib
FMOD_INC_DIR = sound_inc
SOURCES_PATH =  /sgoinfre/goinfre/Perso/sipatry

LIBFT = $(LIBFT_DIR)/libft.a

SRC_GAME_RAW = main_game.c init_game.c draw_game.c doom.c enemy_utils.c \
				print_results.c projectile.c projectiles_maths.c \
				draw_projectiles.c projectile_on_wall_sprite.c \
				keys.c weapons.c draw_hud.c game_minimap.c explosion2.c \
				projectiles_collisions.c projectiles_utils.c \
		   		draw_projectile_no_light.c draw_projectile_color.c \
		   		draw_projectile_both.c draw_projectile_brightness.c \
				explosion.c draw_explosions.c draw_explosion.c doom_utils.c \
				explosion_maths.c enemy_maths.c enemy_combat.c \
				enemy_collision.c enemy_sight.c enemy_ai.c \
		   		add_projectile_bullet_hole.c add_hitscan_bullet_hole.c \
		   		shift_bullet_hole.c get_bullet_hole_pos.c \
		   		delete_bullet_hole.c shift_bullet_hole_events.c \
		        add_floor_hitscan_bullet_hole.c \
				add_ceiling_hitscan_bullet_hole.c \
		        add_floor_projectile_bullet_hole.c \
				add_ceiling_projectile_bullet_hole.c \

SRC_EDITOR_RAW = main_editor.c editor.c init_editor.c save_condition.c \
		draw_grid.c editor_keys.c grid_tools.c editor_render.c \
		draw_grid_walls.c draw_grid_vertices.c event_panel_tab_functions.c \
		add_vertex.c print_target_functions2.c draw_action_panel_bottom.c \
		add_player.c editor_hud.c add_sector.c condition_panel2.c \
		save_map.c write_vertices.c write_sectors.c write_objects.c \
		write_player.c write_enemies.c add_object.c editor_keyup.c \
		player_selection.c objects_selection.c object_selection.c\
		draw_grid_player.c draw_grid_objects.c new_arrow_buttons.c \
		add_enemy.c enemy_selection.c delete_event.c draw_grid_start_player.c \
		delete_object.c delete_action.c delete_enemy.c draw_grid_enemies.c \
		fill_triangle.c editor_3d_keys.c wall_sprites_keys.c \
		apply_texture.c init_event_panel_buttons.c enemy_drag.c \
		editor_3d_keyup.c split_sector.c set_condition_panel_buttons_state.c \
		write_events.c init_print_target_data.c print_event_condition.c \
		write_events_utils.c write_events_utils2.c init_events_writers.c \
		write_event_conditions.c write_event_conditions_utils.c \
		write_event_conditions_utils2.c init_event_conditions_writers.c \
		write_events_links.c print_target_functions.c update_existing_events.c\
		split_sector_utils.c texture_selection.c init_hud_button.c \
		editor_hud_buttons.c init_hud_button_function.c editor_floor_tabs.c \
		editor_ceiling_tabs.c editor_player_tabs.c editor_wall_tabs.c \
		init_editor_tab_buttons.c editor_ceiling_tab_button.c \
		editor_floor_tab_button.c editor_wall_tab_button.c wall_edit_keyup.c \
		editor_env_wall_buttons.c editor_env_floor_buttons.c \
		editor_env_ceilling_buttons.c  change_editor_mode.c \
		editor_3d_button_keys.c editor_3d_button_keyup.c \
		init_add_buttons.c editor_env_sector_buttons.c editor_2d.c \
		editor_sector_tab_button.c editor_sector_tabs.c editor_button_keys.c \
		editor_button_keyup.c editor_env_player_buttons.c \
		editor_player_tab_button.c editor_enemy_tabs.c print_events_tabs2.c \
		editor_env_enemy_buttons.c editor_enemy_tab_button.c \
		editor_object_tabs.c editor_env_object_buttons.c \
		sprite_selection.c init_sprite_selection_buttons.c\
		editor_object_tab_button.c print_events_tabs.c condition_panel_keys.c \
		init_events_selection_buttons.c print_event.c init_event_types.c \
		are_launch_condition_selection_buttons_visible.c \
		are_exec_condition_selection_buttons_visible.c \
		are_exec_condition_selection_buttons_visible2.c \
		init_event_links_types.c is_event_tabs_visible.c \
		print_link_target_functions.c print_condition_target_functions.c \
		print_condition_target_functions2.c init_print_condition_target_data.c\
		change_sprite_buttons.c input_box_checkers.c input_box_updaters.c \
		update_textures_buttons.c init_skybox_selection_buttons.c \
		draw_editor_tabs.c editor_buttons_functions.c weapon_picker_keys.c \
		event_panel.c target_panel.c init_target_panel_buttons.c \
		init_action_panel_buttons.c init_conditions_tabs_buttons.c \
		target_panel_keys.c modify_condition.c init_new_sector_arrays.c \
		3d_edit_change_floor_slope_start.c delete_selected_event.c \
		3d_edit_change_ceiling_slope_start.c editor_3d_button_keys2.c \
		action_panel_keys.c conditions_panel_keys.c \
		event_panel_keys.c modify_event.c delete_action_utils.c \
		new_event_panel_buttons.c new_event_panel_buttons2.c \
		editor_tab_gestion.c editor_wall_sprites_keys.c \
		3d_edit_function.c action_panel.c conditions_tabs.c \
		event_panel_input_box.c 3d_edit_change_ceiling_floor_height.c \
		init_events_creation_buttons.c reduce_texture_scales_functions.c \
		increase_texture_scales_functions.c keys_checkers.c delete_condition.c \
		init_condition_panel_buttons.c condition_type_buttons_functions.c \
		condition_type_buttons_functions2.c init_condition_target_buttons.c \
		condition_target_panel.c condition_panel.c other_panel.c  \
		floor_panel.c ceiling_panel.c wall_panel.c wall_sprite_panel.c \
		weapon_panel.c enemy_panel.c object_panel.c player_panel.c \
		vertex_panel.c sector_other_panel.c check_event_creation.c \
		set_new_condition_target.c set_new_condition_target2.c \
		set_new_condition_target3.c set_new_condition_target4.c \
		set_new_condition_target5.c set_new_condition_target6.c \
		set_new_event_target.c set_new_event_target2.c \
		set_new_event_target3.c set_new_event_target4.c \
		set_new_event_target5.c set_new_event_target6.c \
		set_new_event_target7.c delete_wall_sprite.c draw_grid_walls_utils.c \
		condition_event_panel.c init_condition_event_buttons.c \
		3d_edit_walls_texture_number.c 3d_edit_walls_keys.c \
		3d_edit_slopes.c 3d_edit_change_slope_start.c editor_3d_button_keyup2.c\
		editor_3d_tab_keys.c selection_tabs_button_keys.c \
		3d_edit_right_walls_texture_align.c delete_floor_sprite.c \
		3d_edit_left_walls_texture_align.c new_target.c \
		3d_edit_keyup_functions.c 3d_edit_walls_keyup.c \
		editor_wall_sprites_keyup.c wall_sprites_keyup.c \
		add_floor_sprite.c add_ceiling_sprite.c add_wall_sprite.c \
		update_entities.c editor_vertices_tab.c selection_tabs_keyup.c \
		editor_vertices_tab_button.c editor_env_vertices_buttons.c \
		delete_sector.c delete_vertex.c weapon_picker.c \
		write_musics_choices.c write_resources.c write_textures.c \
		write_sounds.c write_sprites.c write_skyboxes.c write_fonts.c\
		editor_minimap.c init_editor_options_buttons.c \
		editor_option_keys.c write_hud.c write_hud2.c \
		update_sector_with_deleted_vertex.c check_move_player_conditions.c \
		editor_buttons_functions2.c editor_buttons_functions3.c \
		editor_buttons_functions4.c editor_buttons_functions5.c \
		editor_ceiling_tabs2.c editor_floor_tabs2.c editor_hud2.c \
		editor_hud3.c launch_game.c editor_hud_buttons2.c editor_hud_buttons3.c\
		editor_keys2.c editor_keyup2.c editor_keyup3.c editor_keyup4.c \
		new_vertex.c editor_tab_gestion2.c editor_wall_tabs2.c \
		editor_wall_tabs3.c event_panel2.c new_event_panel_value_box.c \
		new_event_panel_box.c event_panel_keyup.c \
		are_events_selection_buttons_visible.c \

SRC_ALL_RAW = init_sdl.c clear_image.c init_keys.c update_sprites.c \
		   draw_line.c menu_tools.c screen_utils.c init_ttf.c init_textures.c \
		   print_text.c bmp_parser.c bmp_parser_wall.c update_sprites_light.c \
		   bmp_parser_skybox.c bmp_parser_utils.c get_double_len.c \
		   bmp_parse_header.c bmp_parse_pixel_data.c bmp_parse_color_table.c \
		   check_bmp_parsing.c keyup.c render_utils.c movement.c create_event.c\
		   get_slope.c update_player_z.c movement_collision.c win.c \
		   get_screen_sectors.c view.c init_options.c confirmation_box_keys.c \
		   fps.c inputs.c init_editor_data.c set_button_images.c \
		   valid_map.c game_menu.c get_sector.c draw_line_minimap.c \
		   fill_triangle_minimap.c color_utils.c camera.c  new_tabs_position.c\
		   print_debug.c init_animations.c vertices_utils.c death.c \
		   map_parse_vertices.c is_in_sector.c add_vertex_in_sector.c \
		   get_existing_vertex.c ./map_parser_protection_utils.c \
		   map_parse_sectors.c map_parser_utils.c map_parse_sectors_utils.c \
		   physics.c map_parse_player.c create_portals.c init_weapons.c \
		   sound_utils.c draw_rectangle.c confirmation_box.c apply_image.c \
		   draw_objects.c sprites_maths.c draw_player.c save_init_data.c \
		   map_parse_objects.c map_init_objects.c init_events_data.c \
		   free_all.c map_parser.c animations.c map_init_enemies.c \
		   sprite_maths_enemies.c draw_enemies.c button.c dialog_box.c \
		   map_parse_enemies.c  draw_line_free.c render.c animations2.c \
		   project_wall.c render_sector.c draw_ceiling.c draw_wall.c \
		   precompute_skybox.c draw_skybox.c draw_floor.c apply_image2.c \
		   precompute_neighbors.c skybox_draw_functions.c wall_hack.c \
		   movement_utils.c update_sprites_state.c set_event_function.c \
		   select_line.c draw_wall_sprites.c input_box.c get_pixel.c \
		   init_obj_enemies_data.c reset_selection.c events_tab_conditions.c \
		   draw_circle_free.c draw_circle.c ft_getchar.c new_button.c \
		   objects_utils.c misc_utils.c map_parse_events.c new_button2.c \
		   gravity.c input_box_utils.c init_ui_textures.c draw_objects2.c \
		   input_box_mouse.c delete_box_selection.c event_target_exists.c \
		   validate_input.c button_event.c player_keys.c init_weapons_sprites.c\
		   pop_events.c start_event.c event_updaters.c free_map.c \
		   generate_mipmaps.c get_current_wall_map.c get_current_floor_map.c \
		   get_current_ceiling_map.c init_skybox.c init_sprites.c \
		   draw_floor_sprites.c draw_floor_sprites_no_light.c \
		   draw_floor_sprites_color.c draw_floor_sprites_brightness.c \
		   draw_floor_sprites_both.c bmp_parser_ui.c bmp_parser_ui_skyboxes.c \
		   draw_ceiling_sprites.c draw_ceiling_sprites_no_light.c \
		   draw_ceiling_sprites_color.c draw_ceiling_sprites_brightness.c \
		   draw_ceiling_sprites_both.c get_clockwise_order.c draw_objects3.c \
		   map_parse_floor_sprites.c map_parse_ceiling_sprites.c \
		   draw_vline_ceiling.c draw_vline_ceiling_brightness.c \
		   draw_vline_ceiling_both.c draw_vline_ceiling_color.c \
		   draw_vline_wall.c draw_vline_wall_brightness.c bmp_parser_utils2.c \
		   draw_vline_wall_both.c draw_vline_wall_color.c dialog_box_utils.c \
		   draw_vline_floor.c draw_vline_floor_brightness.c \
		   draw_vline_floor_both.c draw_vline_floor_color.c \
		   free_sector.c init_screen_size.c dialog_parser.c \
		   print_press_text.c modify_wall_sprite.c realloc_sector_arrays.c \
		   draw_wall_bullet_holes.c intersect_maths.c camera2.c \
		   equals_condition.c less_condition.c greater_condition.c \
		   less_or_equals_condition.c greater_or_equals_condition.c \
		   event_ended_condition.c event_ended_start_condition.c \
		   different_condition.c init_events.c init_events_parser.c \
		   new_global_event.c new_press_event.c new_shoot_event.c \
		   new_stand_event.c new_walk_in_event.c new_walk_out_event.c \
		   new_enemy_event.c parse_event_target.c portal_loop.c \
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
		   precompute_floor_ceiling_sprites_scales.c check_event_validity.c \
		   menu_keys.c option_menu.c option_menu_keys.c collision_utils_2.c \
		   collision_maths.c collision_utils.c new_object_event.c \
		   is_new_vertex_valid.c collision_utils_3.c map_parse_music.c \
		   init_audio.c vertices_selection.c fill_new_sector.c \
		   map_parse_resources.c map_parser_bmp.c map_parse_sound.c \
		   map_parse_fonts.c angles_utils.c add_vertex_in_sector_utils.c \
		   add_vertex_in_sector_utils2.c add_vertex_in_sector_utils3.c \
		   check_vertex_event_utils.c draw_ceiling_utils.c \
		   draw_enemies2.c draw_enemies3.c draw_vline_projectile.c \
		   draw_skybox2.c draw_floor_utils.c draw_wall_utils.c \
		   draw_wall_sprites2.c draw_minimap_player.c minimap2.c minimap3.c \
		   check_floor_event.c check_ceiling_event.c check_floor_slope_event.c \
		   check_ceiling_slope_event.c check_x_collision_event.c \
		   check_y_collision_event.c check_z_collision_event.c \
		   event_checkers2.c event_checkers3.c event_updaters2.c \
		   event_updaters3.c event_updaters4.c events_links_protection2.c \

HEADERS = utils.h render.h collision.h bmp_parser.h map_parser.h object_types.h\
		  editor.h env.h save.h create_portals.h input_box_utils.h add_vertex.h\
		  wall_sprite_remover.h wall_sprite_modifier.h events_conditions.h \
		  events_parser.h update_existing_events.h draw_grid_walls.h \
		  draw_skybox.h \

TEXTURES =	black_tiles.bmp tiles.bmp floor0.bmp floor1.bmp grass1.bmp \
			grass2.bmp grass3.bmp grey.bmp magma_rock.bmp rock.bmp \
			rust.bmp sand.bmp wall0.bmp wall1.bmp wall2.bmp wall3.bmp \
			wall4.bmp \

SPRITES =	bullet_hole.bmp button_off.bmp button_on.bmp camera.bmp \
			cyber_demon.bmp doom_guy_face.bmp doom_guy.bmp lost_soul.bmp \
			MIDSPACE.bmp objects_sprites.bmp projectiles_sprites.bmp \
			raygun.bmp sprite_sheet.bmp

SKYBOXES =	back.bmp bottom.bmp top.bmp left.bmp right.bmp front.bmp \
			nebula_back.bmp nebula_bottom.bmp nebula_top.bmp nebula_right.bmp\
			nebula_left.bmp nebula_front.bmp night_back.bmp night_bottom.bmp \
			night_left.bmp night_right.bmp night_top.bmp night_front.bmp \

HUD =	hud.bmp Ammo_hud.bmp Life_armor_hud.bmp raygun1.bmp raygun2.bmp \
		raygun3.bmp raygun4.bmp raygun5.bmp raygun6.bmp raygun7.bmp \
		shot1.bmp shot2.bmp shot3.bmp shot4.bmp shot5.bmp shot6.bmp shot7.bmp \
		shot8.bmp shot9.bmp shot10.bmp shot11.bmp shot12.bmp shot13.bmp \
		shot14.bmp shot15.bmp Gatling_1.bmp Gatling_2.bmp Gatling_3.bmp \
		Gatling_4.bmp Gatling_5.bmp Gatling_6.bmp

UI =	button-default-up.bmp button-default-pressed.bmp \
		button-default-hover.bmp background-up-64.bmp \
		background-pressed-64.bmp background-hover-64.bmp \
		onglet-up.bmp onglet-pressed.bmp onglet-hover.bmp tab-button-up.bmp\
		tab-button-pressed.bmp tab-button-hover.bmp plus-button-up.bmp \
		plus-button-pressed.bmp plus-button-hover.bmp next-up2.bmp \
		next-pressed2.bmp next-hover2.bmp previous-up2.bmp \
		previous-pressed2.bmp  previous-hover2.bmp \
		minus-button-up.bmp minus-button-pressed.bmp minus-button-hover.bmp \
		file.bmp file_straight.bmp plus-button-up2.bmp \
		plus-button-pressed2.bmp plus-button-hover2.bmp minus-button-up2.bmp \
		minus-button-pressed2.bmp minus-button-hover2.bmp background-up2.bmp \
		background-pressed2.bmp background-hover2.bmp add_button.bmp \
		onglet-up2.bmp onglet-pressed2.bmp onglet-hover2.bmp \
		hud-button-up.bmp hud-button-pressed.bmp hud-button-hover.bmp \
		play_icon.bmp target_icon.bmp event_icon.bmp condition_icon.bmp \
		play_icon_down.bmp target_icon_down_blue.bmp event_icon_down_blue.bmp\
		condition_icon_down_blue.bmp play_icon_hover.bmp \
		target_icon_hover.bmp event_icon_hover.bmp condition_icon_hover.bmp \
		previous_arrow.bmp next_arrow.bmp previous_arrow_down.bmp \
		next_arrow_down.bmp previous_arrow_hover.bmp next_arrow_hover.bmp \
		moonlight.bmp moonlight_128.bmp nebula.bmp nebula_128.bmp \
		beautifull_scenery.bmp beautifull_scenery_128.bmp \
		previous-hover2_pink.bmp previous-pressed2_pink.bmp \
		previous-up2_pink.bmp

AUDIO = Mt_Erebus.wav bim_bam_boum.wav at_dooms_gate.wav\
		shotgun_shot.wav raygun_shot.wav footstep.wav

FONTS = Alice-Regular.ttf BebasNeue-Regular.ttf AmazDooMLeft.ttf \
		Montserrat-Regular.ttf PlayfairDisplay-Regular.ttf \
		Lato-Regular.ttf Lato-Bold.ttf Lato-Black.ttf

SRC_GAME = $(addprefix $(SRC_DIR)/, $(SRC_GAME_RAW))
OBJ_GAME = $(addprefix $(OBJ_GAME_DIR)/, $(SRC_GAME_RAW:.c=.o))

SRC_EDITOR = $(addprefix $(SRC_DIR)/, $(SRC_EDITOR_RAW))
OBJ_EDITOR = $(addprefix $(OBJ_EDITOR_DIR)/, $(SRC_EDITOR_RAW:.c=.o))

SRC_ALL = $(addprefix $(SRC_DIR)/, $(SRC_ALL_RAW))
OBJ_ALL = $(addprefix $(OBJ_ALL_DIR)/, $(SRC_ALL_RAW:.c=.o))

TEXTURES_FILES = $(addprefix $(IMAGES_DIR)/, $(addprefix $(TEXTURES_DIR)/, $(TEXTURES)))
SPRITES_FILES =  $(addprefix $(IMAGES_DIR)/, $(addprefix $(SPRITES_DIR)/, $(SPRITES)))
SKYBOXES_FILES =  $(addprefix $(IMAGES_DIR)/, $(addprefix $(SKYBOXES_DIR)/, $(SKYBOXES)))
HUD_FILES =  $(addprefix $(IMAGES_DIR)/, $(addprefix $(HUD_DIR)/, $(HUD)))
UI_FILES =  $(addprefix $(IMAGES_DIR)/, $(addprefix $(UI_DIR)/, $(UI)))
AUDIO_FILES = $(addprefix $(AUDIO_DIR)/, $(AUDIO))
FONTS_FILES = $(addprefix $(FONTS_DIR)/, $(FONTS))

TEXTURES_PATH = $(addprefix $(IMAGES_DIR)/, $(TEXTURES_DIR))
SPRITES_PATH =  $(addprefix $(IMAGES_DIR)/, $(SPRITES_DIR))
SKYBOXES_PATH =  $(addprefix $(IMAGES_DIR)/, $(SKYBOXES_DIR))
HUD_PATH =  $(addprefix $(IMAGES_DIR)/, $(HUD_DIR))
UI_PATH =  $(addprefix $(IMAGES_DIR)/, $(UI_DIR))
AUDIO_PATH = $(AUDIO_DIR)
FONTS_PATH = $(FONTS_DIR)

TEXTURES_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(addprefix $(IMAGES_DIR)/, $(TEXTURES_DIR)))
SPRITES_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(addprefix $(IMAGES_DIR)/, $(SPRITES_DIR)))
SKYBOXES_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(addprefix $(IMAGES_DIR)/, $(SKYBOXES_DIR)))
HUD_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(addprefix $(IMAGES_DIR)/, $(HUD_DIR)))
UI_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(addprefix $(IMAGES_DIR)/, $(UI_DIR)))
AUDIO_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(AUDIO_DIR))
FONTS_SOURCE_PATH = $(addprefix $(SOURCES_PATH)/, $(FONTS_DIR))


ALL_RESOURCES = $(EDITOR_DIR)

INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDES_DIR) -Wno-misleading-indentation \
		  -I $(LIBFT_DIR) -I $(SDL_DIR) -I $(SDL_TTF_DIR) -I $(FMOD_INC_DIR)\
		  -Ofast\
		  #-fsanitize=address -g3 \
		  #-flto \
		  #-fdata-sections \
		  #-ffast-math \
		  #-funroll-loops \
	
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g3
endif

SOUND_WINDOWS = fmod.dll fmodL.dll

SOUND_OSX = sound_lib/libfmod.dylib sound_lib/libfmodL.dylib

SDL_WINDOWS = /usr/local/bin/SDL2.dll \
              /usr/local/bin/SDL2_ttf.dll \
              -L/usr/local/lib -lcygwin -lSDL2main \

SDL_OSX = -F ~/Library/Frameworks/ -framework SDL2 \
	  -F ~/Library/Frameworks/ -framework SDL2_ttf \
	  #`sdl-config --cflags --libs` \
	  RED := "\033[0;31m"

ifeq ($(OS), Windows_NT)
	SDL = $(SDL_WINDOWS)
	SOUND = $(SOUND_WINDOWS)
else
	UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		SDL = $(SDL_OSX)
		SOUND = $(SOUND_OSX) install_name_tool -add_rpath @executable_path/sound_lib $(EDITOR_NAME)
	else
		echo "Can only compile on Windows or MacOS"
		exit 1
	endif
endif

GREEN := "\e[0;32m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

all:
	@make $(ALL_RESOURCES)
	@make -C $(LIBFT_DIR) -j8
	@printf "\e[0m"
	@make $(GAME_DIR)/$(GAME_NAME) -j8
	@make $(EDITOR_DIR)/$(EDITOR_NAME) -j8

game:
	@make -C $(LIBFT_DIR) -j8
	@make $(GAME_DIR)/$(GAME_NAME) -j8

editor:
	@make -C $(LIBFT_DIR) -j8
	@make $(EDITOR_DIR)/$(EDITOR_NAME) -j8

$(LIBFT):
	@make -C $(LIBFT_DIR) -j8

$(OBJ_GAME_DIR):
	@mkdir -p $(OBJ_GAME_DIR)

$(OBJ_EDITOR_DIR):
	@mkdir -p $(OBJ_EDITOR_DIR)

$(OBJ_ALL_DIR):
	@mkdir -p $(OBJ_ALL_DIR)

$(IMAGES_DIR):
	@mkdir -p $(IMAGES_DIR)

$(TEXTURES_DIR):
	@mkdir -p $(TEXTURES_PATH)

$(SPRITES_DIR):
	@mkdir -p $(SPRITES_PATH)
	
$(SKYBOXES_DIR):
	@mkdir -p $(SKYBOXES_PATH)

$(HUD_DIR):
	@mkdir -p $(HUD_PATH)

$(UI_DIR):
	@mkdir -p $(UI_PATH)

$(AUDIO_DIR):
	@mkdir -p $(AUDIO_PATH)

$(FONTS_DIR):
	@mkdir -p $(FONTS_PATH)

$(TEXTURES_PATH)/%.bmp: $(TEXTURES_SOURCE_PATH)/%.bmp $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(SPRITES_PATH)/%.bmp: $(SPRITES_SOURCE_PATH)/%.bmp $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(SKYBOXES_PATH)/%.bmp: $(SKYBOXES_SOURCE_PATH)/%.bmp $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(HUD_PATH)/%.bmp: $(HUD_SOURCE_PATH)/%.bmp $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(UI_PATH)/%.bmp: $(UI_SOURCE_PATH)/%.bmp $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(AUDIO_PATH)/%.wav: $(AUDIO_SOURCE_PATH)/%.wav $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(FONTS_PATH)/%.ttf: $(FONTS_SOURCE_PATH)/%.ttf $(MAKEFILE)
	@printf "\e[0;33m[INFO] Importing $<\e[0m\n"
	@cp $< $@

$(ALL_RESOURCES):	$(TEXTURES_DIR) $(TEXTURES_FILES) \
					$(SPRITES_DIR) $(SPRITES_FILES) \
					$(SKYBOXES_DIR) $(SKYBOXES_FILES) \
					$(HUD_DIR) $(HUD_FILES) \
					$(UI_DIR) $(UI_FILES) \
					$(AUDIO_DIR) $(AUDIO_FILES) \
					$(FONTS_DIR) $(FONTS_FILES)

$(OBJ_ALL_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@printf "\e[0;33m[INFO] Compiling $<\e[0m\n"
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_GAME_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@printf "\e[0;33m[INFO] Compiling $<\e[0m\n"
	@gcc -c $< -o $@ $(CFLAGS) 

$(OBJ_EDITOR_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@printf "\e[0;33m[INFO] Compiling $<\e[0m\n"
	@gcc -c $< -o $@ $(CFLAGS) 

$(EDITOR_NAME): $(LIBFT) $(OBJ_EDITOR_DIR) $(OBJ_ALL_DIR) $(OBJ_EDITOR) $(OBJ_ALL)
	@printf "\e[0;36m[INFO] Linking ${EDITOR_DIR}/${EDITOR_NAME}                   \e[0m\n"
	@gcc $(CFLAGS) $(OBJ_EDITOR) $(OBJ_ALL) $(LIBFT) -o $(EDITOR_NAME) $(SDL) $(SOUND)
	@printf ${GREEN}"[INFO] Compiled $(EDITOR_DIR)/$(EDITOR_NAME) with success!\n"${RESET}

$(GAME_NAME): $(LIBFT) $(OBJ_GAME_DIR) $(OBJ_ALL_DIR) $(OBJ_GAME) $(OBJ_ALL)
	@printf "\e[0;36m[INFO] Linking ${GAME_DIR}/${GAME_NAME}                    \e[0m\n"
	@gcc $(CFLAGS) $(OBJ_GAME) $(OBJ_ALL) $(LIBFT) -o $(GAME_NAME) $(SDL) $(SOUND)
	@printf ${GREEN}"[INFO] Compiled $(GAME_DIR)/$(GAME_NAME) with success!\n"${RESET}

clean: 
	@make clean -C libft
	@rm -Rf $(OBJ_ALL_DIR)
	@rm -Rf $(OBJ_EDITOR_DIR)
	@rm -Rf $(OBJ_GAME_DIR)
	@printf ${CYAN}"[INFO] Removed objs\n"${RESET}

fclean:
	@make fclean -C libft
	@rm -Rf $(OBJ_ALL_DIR)
	@rm -Rf $(OBJ_EDITOR_DIR)
	@rm -Rf $(OBJ_GAME_DIR)
	@printf ${CYAN}"[INFO] Removed objs\n"${RESET}
	@rm -Rf $(GAME_DIR)/$(GAME_NAME)
	@rm -Rf $(EDITOR_DIR)/$(EDITOR_NAME)
	@printf ${CYAN}"[INFO] Removed $(GAME_DIR)/$(GAME_NAME) and $(EDITOR_DIR)/$(EDITOR_NAME)\n"${RESET}

re: fclean all

.PHONY: fclean all clean libft maps
