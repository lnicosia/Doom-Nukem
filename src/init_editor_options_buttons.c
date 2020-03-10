/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_options_buttons.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/10 11:06:59 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		quit_options(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->options.editor_options = 0;
	return (0);
}

int		mipmapping_option(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->options.mipmapping)
		env->options.mipmapping = 0;
	else
		env->options.mipmapping = 1;
	return (0);
}

int		zbuffer_option(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->options.zbuffer)
		env->options.zbuffer = 0;
	else
		env->options.zbuffer = 1;
	return (0);
}

int		light_option(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->options.lighting)
		env->options.lighting = 0;
	else
		env->options.lighting = 1;
	return (0);
}

int		fps_option(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->options.show_fps)
		env->options.show_fps = 0;
	else
		env->options.show_fps = 1;
	return (0);
}

void	init_quit_options_button(t_env *env)
{
	env->editor.quit_options = new_previous_button_2(ON_RELEASE, &quit_options,
	env, env);
	env->editor.quit_options.str = NULL;
	env->editor.quit_options.pos = new_point(25, 5);
}

void	init_mipmapping_button(t_env *env)
{
	env->editor.mipmapping = new_image_button(ON_RELEASE, &mipmapping_option,
		env, env);
	env->editor.mipmapping.str = "MIPMAP";
	env->editor.mipmapping.pos = new_point(110, 60);
}

void	init_zbuffer_button(t_env *env)
{
	env->editor.zbuffer = new_image_button(ON_RELEASE, &zbuffer_option,
		env, env);
	env->editor.zbuffer.str = "ZBUFFER";
	env->editor.zbuffer.pos = new_point(110, 110);
}

void	init_light_button(t_env *env)
{
	env->editor.light = new_image_button(ON_RELEASE, &light_option,
		env, env);
	env->editor.light.str = "LIGHT";
	env->editor.light.pos = new_point(110, 160);
}

void	init_fps_button(t_env *env)
{
	env->editor.fps = new_image_button(ON_RELEASE, &fps_option,
		env, env);
	env->editor.fps.str = "FPS";
	env->editor.fps.pos = new_point(110, 210);	
}

void	init_editor_options_buttons(t_env *env)
{
	init_quit_options_button(env);
	init_mipmapping_button(env);
	init_zbuffer_button(env);
	init_light_button(env);
	init_fps_button(env);
}