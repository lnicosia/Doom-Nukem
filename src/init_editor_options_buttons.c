/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_options_buttons.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 11:49:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
