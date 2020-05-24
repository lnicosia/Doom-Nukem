/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_option_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:12:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 18:44:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_options_keys(t_env *env)
{
	if (button_keys(&env->editor.quit_options, env))
		return (-1);
	if (button_keys(&env->editor.mipmapping, env))
		return (-1);
	if (button_keys(&env->editor.zbuffer, env))
		return (-1);
	if (button_keys(&env->editor.light, env))
		return (-1);
	if (button_keys(&env->editor.fps, env))
		return (-1);
	if (env->editor.options_from_h == 1 && !env->inputs.h)
	{
		env->editor.options_from_h = 0;
		env->options.editor_options = 0;
		if (env->editor.in_game)
			editor_show_tab(env);
		env->editor.tab = 0;
	}
	return (0);
}

int		editor_options_keyup(t_env *env)
{
	if (button_keyup(&env->editor.quit_options, env))
		return (-1);
	if (button_keyup(&env->editor.mipmapping, env))
		return (-1);
	if (button_keyup(&env->editor.zbuffer, env))
		return (-1);
	if (button_keyup(&env->editor.light, env))
		return (-1);
	if (button_keyup(&env->editor.fps, env))
		return (-1);
	return (0);
}
