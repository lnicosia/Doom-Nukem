/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:21:53 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 18:17:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "utils.h"
# define EVENT_ICON 42
# define TARGET_ICON 43
# define ACTION_ICON 44
# define CONDITION_ICON 45
# define EVENT_ICON_DOWN 46
# define TARGET_ICON_DOWN 47
# define ACTION_ICON_DOWN 48
# define CONDITION_ICON_DOWN 49
# define EVENT_ICON_HOVER 50
# define TARGET_ICON_HOVER 51
# define ACTION_ICON_HOVER 52
# define CONDITION_ICON_HOVER 53
# define PREVIOUS_ICON 54
# define NEXT_ICON 55
# define PREVIOUS_ICON_DOWN 56
# define NEXT_ICON_DOWN 57
# define PREVIOUS_ICON_HOVER 58
# define NEXT_ICON_HOVER 59

typedef struct				s_button_tab
{
	void					*env;
	t_point					pos;
	void					*target;
	int						type;
}							t_button_tab;

typedef struct				s_button_next
{
	void					*env;
	void					*target;
	int						i;
	int						max;
	int						min;
	int						type;
	int						button_type;
	t_point					pos;
}							t_button_next;

typedef struct				s_var_sp
{
	t_button				scale_x;
	t_button				scale_y;
	t_button				pos_x;
	t_button				pos_y;
	t_button				add_sprite;
	t_button_tab			t_scale_x;
	t_button_tab			t_scale_y;
	t_button_tab			t_pos_x;
	t_button_tab			t_pos_y;
	t_button_tab			t_num;
	t_button_tab			t_add_sprite;
}							t_var_sp;

typedef struct				s_var_s
{
	t_button				brightness;
	t_button				color;
	t_button				intensity;
	t_button				gravity;
	t_button_tab			t_brightness;
	t_button_tab			t_color;
	t_button_tab			t_intensity;
	t_button_tab			t_gravity;
}							t_var_s;

typedef struct				s_var_g
{
	t_button				height;
	t_button				slope;
	t_button				texture;
	t_button				texture_scale_x;
	t_button				texture_scale_y;
	t_button				texture_align_x;
	t_button				texture_align_y;
	t_button				brightness;
	t_button				color;
	t_button				intensity;
	t_button				gravity;
	t_button				floor;
	t_button				ceiling;
	t_button				ceiling_slope;
	t_button				floor_slope;
	t_button				pos_x;
	t_button				pos_y;
	t_button				pos_z;
	t_button				health;
	t_button				armor;
	t_button				angle;
	t_button				speed;
	t_button				scale;
	t_button				damage;
	t_button				portal;
	t_button				add_sprite;
	t_button				sector;
	t_button				vertex;
	t_button				num;
	t_button_tab			t_brightness;
	t_button_tab			t_color;
	t_button_tab			t_intensity;
	t_button_tab			t_gravity;
	t_button_tab			t_height;
	t_button_tab			t_slope;
	t_button_tab			t_texture;
	t_button_tab			t_texture_scale_x;
	t_button_tab			t_texture_scale_y;
	t_button_tab			t_texture_align_x;
	t_button_tab			t_texture_align_y;
	t_button_tab			t_floor;
	t_button_tab			t_ceiling;
	t_button_tab			t_ceiling_slope;
	t_button_tab			t_floor_slope;
	t_button_tab			t_pos_x;
	t_button_tab			t_pos_y;
	t_button_tab			t_pos_z;
	t_button_tab			t_health;
	t_button_tab			t_armor;
	t_button_tab			t_angle;
	t_button_tab			t_speed;
	t_button_tab			t_scale;
	t_button_tab			t_damage;
	t_button_tab			t_portal;
	t_button_tab			t_add_sprite;
	t_button_tab			t_sector;
	t_button_tab			t_vertex;
	t_button_tab			t_num;
}							t_var_g;

typedef struct				s_hud
{
	int						draw_hud;
	int						x;
	int						y;
	t_button				plr;
	t_var_g					g_wall;
	t_var_g					g_floor;
	t_var_g					g_ceiling;
	t_var_g					g_sector;
	t_var_g					g_vertex;
	t_var_g					g_player;
	t_var_g					g_enemy;
	t_var_g					g_object;
	t_var_s					s_wall;
	t_var_s					s_wall_sprite;
	t_var_s					s_floor;
	t_var_s					s_ceiling;
	t_var_s					s_sector;
	t_var_s					s_player;
	t_var_s					s_enemy;
	t_var_s					s_object;
	t_var_sp				sp_floor_sprite;
	t_var_sp				sp_ceiling_sprite;
	t_var_sp				sp_wall_sprite;
	t_var_sp				sp_enemy_sprite;
	t_var_sp				sp_object_sprite;
	t_var_sp				sp_player_sprite;
}							t_hud;

typedef struct				s_add_vertex
{
	int						*sector_list;
	int						v1;
	int						v2;
}							t_add_vertex;

typedef	struct				s_split
{
	int						v1;
	int						v2;
	int						sector;
}							t_split;

typedef struct				s_button_param
{
	void					*env;
	int						i;
}							t_button_param;

typedef struct				s_action_panel
{
	t_button				go_to;
	t_button				add;
	t_button				value;
	t_button				speed;
	t_button				delay;
	t_button				max_uses;
	t_button				text;
	Uint32					uint32_value;
	double					double_value;
	int						int_value;
	int						delay_value;
}							t_action_panel;

typedef enum				e_target_panel_types
{
	SECTOR_TYPE,
	WALL_TYPE,
	WALL_SPRITE_TYPE,
	WEAPON_TYPE,
	ENEMY_TYPE,
	OBJECT_TYPE,
	VERTEX_TYPE,
	PLAYER_TYPE,
	OTHER_TYPE,
	FLOOR_TYPE,
	CEILING_TYPE,
	SECTOR_OTHER_TYPE
}							t_target_panel_types;

typedef struct				s_target_panel
{
	int						target_selection_phase;
	int						sector_type;
	int						wall_type;
	int						wall_sprite_type;
	int						weapon_type;
	int						enemy_type;
	int						object_type;
	int						player_type;
	int						vertex_type;
	int						floor_type;
	int						ceiling_type;
	int						other_type;
	int						sector_other_type;
	int						target_type;
	int						target_main_type;
	int						selected_button;
	t_button				next;
	t_button				previous;
	t_button				sector;
	t_button				wall;
	t_button				wall_sprite;
	t_button				weapon;
	t_button				enemy;
	t_button				object;
	t_button				player;
	t_button				vertex;
	t_button				floor;
	t_button				ceiling;
	t_button				other;
	t_button				sector_other;
	t_button				targets[9];
}							t_target_panel;

typedef struct				s_event_panel
{
	t_event					event;
	t_point					pos;
	t_point					size;
	t_point					content_panel_size;
	t_button				target_tab;
	t_button				action_tab;
	t_button				launch_conditions_tab;
	t_button				exec_conditions_tab;
	t_button				ok;
	t_button				cancel;
	t_button				next_condition;
	t_button				previous_condition;
	t_button				new_condition;
	t_button				modify_condition;
	t_button				delete_condition;
	t_target_panel			target_panel;
	t_action_panel			action_panel;
	t_event_trigger			trigger;
	int						selected_event;
	int						top_size;
}							t_event_panel;

typedef struct				s_select_event_panel
{
	t_button				global;
	t_button				press;
	t_button				shoot;
	t_button				stand;
	t_button				walk_in;
	t_button				walk_out;
	t_button				death;
}							t_select_event_panel;

typedef struct				s_weapon_picker
{
	t_point					pos;
	t_point					size;
	t_button				next;
	t_button				previous;
	t_button				ok;
	t_button				cancel;
}							t_weapon_picker;

typedef struct				s_condition_panel
{
	t_button				condition_tab;
	t_button				target_tab;
	t_button				equals;
	t_button				different;
	t_button				less;
	t_button				greater;
	t_button				less_or_equals;
	t_button				greater_or_equals;
	t_button				event_ended;
	t_button				event_ended_start;
	t_button				function;
	t_button				value;
	t_condition				condition;
	t_target_panel			target_panel;
	t_select_event_panel	event_panel;
	Uint32					uint32_value;
	double					double_value;
	int						int_value;
	int						selected_condition;
}							t_condition_panel;

typedef struct				s_editor
{
	t_v2					start_pos;
	int						key_delay;
	int						keyup_allowed;
	int						start_key_delay;
	int						existing_vertex;
	int						divide_sector;
	int						split_sector;
	int						selected_sector;
	int						selected_player;
	int						selected_start_player;
	int						selected_vertex;
	int						selected_weapon;
	int						selected_wall;
	int						dragged_object;
	int						selected_wall_sprite;
	int						dragged_player;
	int						dragged_start_player;
	int						dragged_vertex;
	int						dragged_enemy;
	int						start_vertex;
	int						nb_vertex;
	int						player_exist;
	int						tab;
	int						select;
	int						select_portal;
	int						current_texture;
	int						current_enemy;
	int						current_object;
	int						current_sprite;
	int						current_weapon;
	int						selected_events;
	size_t					selected_event;
	size_t					selected_launch_condition;
	size_t					selected_exec_condition;
	t_v2					center;
	double					scale;
	t_list					*vertices;
	t_hud					hud;
	t_list					*current_vertices;
	int						reverted;
	int						in_game;
	int						enter_locked;
	int						click_locked;
	t_add_vertex			add;
	t_split					split;
	int						select_vertex_on_going;
	int						draw_texture_tab;
	int						draw_enemy_tab;
	int						draw_object_tab;
	int						draw_sprite_texture_tab;
	int						draw_sprite_tab;
	int						create_enemy;
	int						create_object;
	int						creating_event;
	int						event_panel_dragged;
	int						selecting_target;
	int						selecting_condition_target;
	int						selecting_weapon;
	int						selecting_condition_weapon;
	int						creating_condition;
	int						creating_launch_condition;
	int						creating_exec_condition;
	int						selecting_event;
	int						just_selected;
	t_point					texture_selection_size;
	t_point					object_selection_size;
	t_point					enemy_selection_size;
	t_point					wall_sprite_selection_size;
	t_point					texture_selection_pos;
	t_point					object_selection_pos;
	t_point					enemy_selection_pos;
	t_point					wall_sprite_selection_pos;
	t_button				current_texture_selection;
	t_button				current_enemy_selection;
	t_button				current_object_selection;
	t_button				change_mode;
	t_button				quit_options;
	t_button				save;
	t_button				launch_game;
	t_button				texture_background;
	t_button				enemy_background;
	t_button				sprite_background;
	t_button				sector_tab;
	t_button				sprite_tab;
	t_button				general_tab;
	t_button				events_tab;
	t_button				textures[MAX_WALL_TEXTURE];
	t_button				skyboxes[MAX_SKYBOX + MAX_SKYBOX];
	t_button				enemy_tab[MAX_MONSTER_MINI];
	t_button				object_tab[MAX_OBJECTS];
	t_button				add_enemy;
	t_button				add_object;
	t_button_next			next_sprite_env;
	t_button				next_sprite;
	t_button_next			previous_sprite_env;
	t_button				previous_sprite;
	t_button_next			next_wall_env;
	t_button_next			previous_wall_env;
	t_button				next_wall;
	t_button				previous_wall;
	t_button_next			next_slope_swap_env;
	t_button_next			previous_slope_swap_env;
	t_button				previous_slope_swap;
	t_button				next_slope_swap;
	t_button				next_events;
	t_button				previous_events;
	t_button				next_event;
	t_button				previous_event;
	t_button				next_launch_condition;
	t_button				previous_launch_condition;
	t_button				next_exec_condition;
	t_button				previous_exec_condition;
	t_button				sprite_selection[MAX_OBJECTS];
	t_button				current_sprite_selection;
	t_button				options;
	t_button				create_event_button;
	t_event_panel			event_panel;
	t_condition_panel		condition_panel;
	t_weapon_picker			weapon_picker;
	t_button				new_event;
	t_button				modify_event;
	t_button				delete_event;
	t_button				select_event;
	t_button				next_ambiance_music;
	t_button				previous_ambiance_music;
	t_button				next_fighting_music;
	t_button				previous_fighting_music;
	t_button				mipmapping;
	t_button				zbuffer;
	t_button				light;
	t_button				fps;
	int						texture_tab;
	int						options_from_h;
	t_list					*events_to_delete;
}							t_editor;

#endif
