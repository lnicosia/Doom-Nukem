/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:37:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

int		editor_hud2(t_env *env)
{
	if (env->editor.creating_event)
	{
		if (env->editor.creating_condition)
		{
			if (draw_condition_panel(env))
				return (-1);
		}
		else
		{
			if (draw_event_panel(env))
				return (-1);
		}
	}
	if (env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
	{
		if (draw_weapon_picker(env))
			return (-1);
	}
	return (0);
}

int		editor_hud(t_env *env)
{
	t_point	center;
	t_point	size;

	center = new_point(0, 0);
	size = new_point(0, 0);
	if (!env->editor.in_game || (env->editor.in_game && env->editor.tab))
	{
		draw_rectangle(env,
			new_rectangle(0xbdc3c7, 0xbdc3c7, 1, 0),
			new_point(0, 0),
			new_point(400, 900));
		if (!env->options.editor_options)
		{
			if (editor_options1(env, center, size))
				return (-1);
		}
		else
		{
			if (editor_options_hud(env))
				return (-1);
		}
	}
	return (editor_hud2(env));
}