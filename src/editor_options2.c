/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_options2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:09:21 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 14:37:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

int	editor_options6(t_env *env)
{
	if (env->editor.draw_enemy_tab)
	{
		enemy_tab(env, MAX_ENEMIES);
	}
	if (env->editor.draw_object_tab)
	{
		object_tab(env, MAX_OBJECTS);
	}
	if (env->editor.draw_sprite_tab)
	{
		sprite_selection(env, MAX_OBJECTS);
	}
	if (env->editor.draw_texture_tab || env->editor.draw_enemy_tab
	|| env->editor.draw_sprite_tab)
		env->editor.texture_tab = 1;
	else
		env->editor.texture_tab = 0;
	return (0);
}

int	editor_options5(t_env *env)
{
	if (!env->editor.in_game || (env->editor.in_game && env->editor.tab))
	{
		if (draw_button(env, env->editor.previous_ambiance_music,
		env->editor.previous_ambiance_music.str))
			return (-1);
		if (draw_button(env, env->editor.next_ambiance_music,
		env->editor.next_ambiance_music.str))
			return (-1);
		if (draw_button(env, env->editor.previous_fighting_music,
		env->editor.previous_fighting_music.str))
			return (-1);
		if (draw_button(env, env->editor.next_fighting_music,
		env->editor.next_fighting_music.str))
			return (-1);
	}
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
	new_point(20, 450), new_point(360, 430));
	if (draw_editor_tabs(env))
		return (-1);
	return (editor_options6(env));
}
