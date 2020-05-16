/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:08 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/16 13:02:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	print_sprite_tab(t_env *env)
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
	if (draw_wall_sprites_general_buttons(env))
		return (-1);
	return (0);
}

int	draw_editor_tabs3(t_env *env)
{
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

int	draw_editor_tabs2(t_env *env)
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
	return (draw_editor_tabs3(env));
}

int	draw_editor_tabs(t_env *env)
{
	if (draw_editor_general_tab(env))
		return (-1);
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
