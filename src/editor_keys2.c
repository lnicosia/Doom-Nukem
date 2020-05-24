/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:56:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:56:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int		save_map_keys(t_env *env)
{
	int	ret;

	ret = valid_map(env);
	if (ret == -1)
		return (-1);
	else if (ret)
		return (0);
	if (env->editor.creating_event)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Please save your event before saving the map", ERROR, env))
			return (-1);
	}
	else
	{
		if (new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
		STRING, &env->save_file))
			return (-1);
		env->input_box.update = &save_map;
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
		env->input_box.text_size = 42;
	}
	return (1);
}

int		editor_keys8(t_env *env)
{
	if (env->editor.creating_event && !env->confirmation_box.state)
	{
		if (event_panel_keys(env))
			return (-1);
	}
	if ((env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
		&& !env->confirmation_box.state)
	{
		if (weapon_picker_keys(env))
			return (-1);
	}
	if ((env->inputs.plus || env->inputs.minus)
		&& !env->editor.in_game && env->editor.selected_sector != -1)
	{
		if (!env->time.tick4)
			env->time.tick4 = SDL_GetTicks();
	}
	if (env->inputs.h)
	{
		env->editor.options_from_h = 1;
		env->options.editor_options = 1;
	}
	return (0);
}

int		editor_keys7(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_enemy_tab)
	{
		while (i < MAX_ENEMIES)
		{
			if (button_keys(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_object_tab)
	{
		while (i < MAX_OBJECTS)
		{
			if (button_keys(&env->editor.object_tab[i], env))
				return (-1);
			i++;
		}
	}
	return (editor_keys8(env));
}

int		editor_keys6(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_texture_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keys(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			button_keys(&env->editor.skyboxes[i], env);
			i++;
		}
	}
	return (editor_keys7(env));
}
