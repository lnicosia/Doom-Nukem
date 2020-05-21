/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_options_buttons2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:49:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:49:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		quit_options(void *param)
{
	t_env *env;

	env = (t_env*)param;
	env->options.editor_options = 0;
	return (0);
}

int		mipmapping_option(void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->options.mipmapping)
		env->options.mipmapping = 0;
	else
		env->options.mipmapping = 1;
	return (0);
}

int		zbuffer_option(void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->options.zbuffer)
		env->options.zbuffer = 0;
	else
		env->options.zbuffer = 1;
	return (0);
}
