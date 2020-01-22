/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:21:53 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 15:59:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "utils.h"

typedef struct		s_button_tab
{
	void			*env;
	t_point			pos;
	void			*target;
	int				type;
}					t_button_tab;

typedef struct		s_var_s
{
	t_button		brightness;
	t_button		color;
	t_button		intensity;
	t_button		gravity;
	t_button_tab	t_brightness;
	t_button_tab	t_color;
	t_button_tab	t_intensity;
	t_button_tab	t_gravity;
}					t_var_s;

typedef struct	s_var_g
{
	t_button		height;
	t_button		slope;
	t_button		texture;
	t_button		texture_scale_x;
	t_button		texture_scale_y;
	t_button		texture_align_x;
	t_button		texture_align_y;
	t_button		brightness;
	t_button		color;
	t_button		intensity;
	t_button		gravity;
	t_button		floor;
	t_button		ceiling;
	t_button		ceiling_slope;
	t_button		floor_slope;
	t_button		pos_x;
	t_button		pos_y;
	t_button		pos_z;
	t_button		health;
	t_button		armor;
	t_button		speed;
	t_button_tab	t_brightness;
	t_button_tab	t_color;
	t_button_tab	t_intensity;
	t_button_tab	t_gravity;
	t_button_tab	t_height;
	t_button_tab	t_slope;
	t_button_tab	t_texture;
	t_button_tab	t_texture_scale_x;
	t_button_tab	t_texture_scale_y;
	t_button_tab	t_texture_align_x;
	t_button_tab	t_texture_align_y;
	t_button_tab	t_floor;
	t_button_tab	t_ceilling;
	t_button_tab	t_ceiling_slope;
	t_button_tab	t_floor_slope;
	t_button_tab	t_pos_x;
	t_button_tab	t_pos_y;
	t_button_tab	t_pos_z;
	t_button_tab	t_health;
	t_button_tab	t_armor;
	t_button_tab	t_speed;
}				t_var_g;

typedef struct	s_hud
{
	int			draw_hud;
	int			x;
	int			y;
	t_button	plr;
	t_var_g		g_wall;
	t_var_g		g_floor;
	t_var_g		g_ceilling;
	t_var_g		g_sector;
	t_var_g		g_player;
	t_var_g		g_enemy;
	t_var_g		g_object;
	t_var_s		s_wall;
	t_var_s		s_floor;
	t_var_s		s_ceilling;
	t_var_s		s_sector;
	t_var_s		s_player;
	t_var_s		s_enemy;
	t_var_s		s_object;
}				t_hud;


typedef struct	s_plr
{
	double		x;
	double		y;
	double		z;
	double		angle;
	int			sector;
}				t_plr;

typedef struct  s_add_vertex
{
    int *sector_list;
    int v1;
    int v2;
}               t_add_vertex;

typedef	struct	s_split
{
	int	v1;
	int	v2;
	int	sector;

}				t_split;

typedef struct	s_button_target
{
	void		*env;
	int			i;
}				t_button_target;

typedef struct	s_editor
{
	t_v2			start_pos;
	int				existing_vertex;
	int				divide_sector;
	int				split_sector;
	int				selected_sector;
	int				selected_object;
	int				selected_player;
	int				selected_vertex;
	int				selected_wall;
	int				dragged_object;
	int				selected_wall_sprite;
	int				dragged_player;
	int				dragged_vertex;
	int				dragged_enemy;
	int				start_vertex;
	int				nb_vertex;
	int				player_exist;
	int				tab;
	int				select;
	int				current_texture;
	int				current_enemy;
	t_v2			center;
	double			scale;
	t_list			*vertices;
	t_hud			hud;
	t_plr			player;
	t_list			*current_vertices;
	int				reverted;
	int				in_game;
	int				game;
	int				enter_locked;
	t_add_vertex	add;
	t_split			split;
	int				select_vertex_on_going;
	int				draw_selection_tab;
	int				draw_enemy_tab;
	int				draw_object_tab;
	int				create_enemy;
	int				create_object;
	t_texture		miniature;
	t_button		current_texture_selection;
	t_button		current_enemy_selection;
	t_button		change_mode;
	t_button		save;
	t_button		launch_game;
	t_button		texture_background;
	t_button		enemy_background;
	t_button		sector_tab;
	t_button		sprite_tab;
	t_button		general_tab;
	t_button		textures[MAX_WALL_TEXTURE];
	t_button		enemy_tab[MAX_MONSTER_MINI];
	t_button		add_enemy;
	t_button		add_object;
}				t_editor;

#endif
