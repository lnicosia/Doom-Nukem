/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud_buttons2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:08:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:08:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_mode(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->nb_sectors >= 1)
	{
		if (env->editor.in_game)
			going_in_2d_mode(env);
		else
			going_in_3d_mode(env);
	}
	return (0);
}

int		save_button(void *target)
{
	t_env	*env;
	int		ret;

	env = (t_env*)target;
	ret = valid_map(env);
	if (ret == -1)
		return (-1);
	else if (!ret)
	{
		SDL_SetRelativeMouseMode(0);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
		STRING, &env->save_file);
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
	}
	return (0);
}

int		editor_options(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->options.editor_options == 0)
		env->options.editor_options = 1;
	else
		env->options.editor_options = 0;
	return (0);
}

int		editor_options_button(t_env *env)
{
	env->editor.options = new_image_button(ON_RELEASE, &editor_options,
		env, env);
	env->editor.options.str = "OPTIONS";
	env->editor.options.pos = new_point(40, 210);
	return (0);
}
