/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_option_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:12:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/10 11:07:22 by gaerhard         ###   ########.fr       */
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