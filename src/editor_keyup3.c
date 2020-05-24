/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:41:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 11:33:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		is_point_in_rectangle(t_point point, t_point pos, t_point size)
{
	if (point.x >= pos.x && point.x <= pos.x + size.x
		&& point.y >= pos.y && point.y <= pos.y + size.y)
		return (1);
	return (0);
}

int		is_mouse_on_texture_selection_tab(t_env *env)
{
	if (env->editor.draw_texture_tab
		&& is_point_in_rectangle(new_point(env->sdl.mx, env->sdl.my),
		env->editor.texture_selection_pos,
		env->editor.texture_selection_size))
		return (1);
	return (0);
}

int		is_mouse_on_object_selection_tab(t_env *env)
{
	if (env->editor.draw_object_tab
		&& is_point_in_rectangle(new_point(env->sdl.mx, env->sdl.my),
		env->editor.object_selection_pos,
		env->editor.object_selection_size))
		return (1);
	return (0);
}

int		is_mouse_on_enemy_selection_tab(t_env *env)
{
	if (env->editor.draw_enemy_tab
		&& is_point_in_rectangle(new_point(env->sdl.mx, env->sdl.my),
		env->editor.enemy_selection_pos,
		env->editor.enemy_selection_size))
		return (1);
	return (0);
}

int		is_mouse_on_wall_sprite_selection_tab(t_env *env)
{
	if (env->editor.draw_sprite_tab
		&& is_point_in_rectangle(new_point(env->sdl.mx, env->sdl.my),
		env->editor.wall_sprite_selection_pos,
		env->editor.wall_sprite_selection_size))
		return (1);
	return (0);
}
