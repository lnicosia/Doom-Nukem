/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:08 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 16:12:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_sprite_tab(t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (print_wall_sprite_tab(env))
			return (-1);
	}
	else if (env->selected_ceiling_sprite != -1)
	{
		if (print_ceiling_sprite_tab(env))
			return (-1);
	}
	else if (env->selected_floor_sprite != -1)
	{
		if (print_floor_sprite_tab(env))
			return (-1);
	}
	if (env->selected_floor_sprite != -1
		|| env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1)
	{
		if (draw_button(env, env->editor.next_sprite,
			env->editor.next_sprite.str))
			return (-1);
		if (draw_button(env, env->editor.previous_sprite,
		env->editor.previous_sprite.str))
			return (-1);
		if (draw_button(env, env->editor.sprite_background,
		env->editor.sprite_background.str))
			return (-1);
		apply_sprite(env->object_sprites[env->editor.current_sprite],
		new_point(env->editor.current_sprite_selection.pos.y,
		env->editor.current_sprite_selection.pos.x),
		new_point(60, 60), env);
	}
	return (0);
}

int		print_sector_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
	{
		if (print_object_sector_tab(env))
			return (-1);
	}
	else if (env->selected_enemy != -1)
	{
		if (print_enemy_sector_tab(env))
			return (-1);
	}
	else if (env->editor.selected_start_player != -1)
	{
		if (print_player_sector_tab(env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		if (print_ceiling_sector_tab(env))
			return (-1);
	}
	else if (env->selected_floor != -1)
	{
		if (print_floor_sector_tab(env))
			return (-1);
	}
	else if (env->editor.selected_wall != -1
	&& env->editor.selected_sector != -1)
	{
		if (print_wall_sector_tab(env))
			return (-1);
	}
	else if (env->selected_wall_sprite_sprite != -1)
	{
		if (print_wall_sprite_sector_tab(env))
			return (-1);
	}
	return (0);
}

int		print_general_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
	{
		if (print_object_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
	{
		if (print_sector_general_tab(env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		if (print_ceiling_general_tab(env))
			return (-1);
	}
	else if (env->selected_floor != -1)
	{
		if (print_floor_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_start_player != -1)
	{
		if (print_player_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_wall != -1
		&& env->editor.selected_sector != -1)
	{
		if (print_wall_general_tab(env))
			return (-1);
	}
	else if (env->selected_enemy != -1)
	{
		if (print_enemy_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_vertex != -1)
	{
		if (print_vertices_general_tab(env))
			return (-1);
	}
	return (0);
}

int		draw_editor_tabs2(t_env *env)
{
	if (env->editor.tab &&
	(env->selected_ceiling_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_wall_sprite_sprite != -1))
	{
		if (draw_button(env, env->editor.sprite_tab,
			env->editor.sprite_tab.str))
			return (-1);
	}
	if (env->editor.sector_tab.state == DOWN)
	{
		if (print_sector_tab(env))
			return (-1);
	}
	else if (env->editor.sprite_tab.state == DOWN)
	{
		if (print_sprite_tab(env))
			return (-1);
	}
	else if (env->editor.general_tab.state == DOWN)
	{
		if (print_general_tab(env))
			return (-1);
	}
	if (env->editor.events_tab.state == DOWN)
	{
		if (print_events_tab(env))
			return (-1);
	}
	if (env->editor.draw_texture_tab)
	{
		if (texture_tab(env, MAX_WALL_TEXTURE + MAX_SKYBOX))
			return (-1);
	}
	return (0);
}

int		draw_editor_tabs(t_env *env)
{
	if (((env->selected_ceiling_sprite == -1
	&& env->selected_floor_sprite == -1
	&& env->selected_wall_sprite_sprite == -1)
	&& (env->selected_object != -1 || env->editor.selected_wall != -1 ||
	env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1))
	|| ((env->editor.selected_sector != -1
	|| env->editor.selected_start_player != -1
	|| env->selected_object != -1 || env->selected_enemy != -1
	|| env->editor.selected_vertex != -1)))
	{
		if (draw_button(env, env->editor.general_tab,
			env->editor.general_tab.str))
			return (-1);
	}
	if (((env->editor.selected_start_player != -1
		|| env->selected_enemy != -1
	|| env->selected_object != -1)) || ((env->selected_object != -1
		|| env->editor.selected_wall != -1 ||
	env->editor.selected_wall_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1 || env->selected_wall_sprite_sprite != -1)))
	{
		if (draw_button(env, env->editor.sector_tab,
			env->editor.sector_tab.str))
			return (-1);
	}
	if (draw_button(env, env->editor.events_tab, env->editor.events_tab.str))
		return (-1);
	return (draw_editor_tabs2(env));
}
