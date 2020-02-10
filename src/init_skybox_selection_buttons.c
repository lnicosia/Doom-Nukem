/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skybox_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:40:31 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/07 16:21:35 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_skybox_selection_buttons(t_env *env)
{
	int	i;
	int	mod;
	int	mod_e;
	if (MAX_WALL_TEXTURE > 20)
		mod_e = 10;
	else
		mod_e = 5;
	if (MAX_SKYBOX > 20)
		mod = 10;
	else
		mod = 5;
	i = 0;
	while (i < MAX_SKYBOX + MAX_SKYBOX)
	{
		if (i < MAX_SKYBOX)
		{
			env->editor.skyboxes[i] = new_image_button(WHEN_DOWN, &save_texture, new_button_target(env, (-i -1)), env);
			env->editor.skyboxes[i].img_up = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_hover = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_pressed = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_down = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].size_up = new_point(64, 64);
			env->editor.skyboxes[i].size_hover = new_point(64, 64);
			env->editor.skyboxes[i].size_pressed = new_point(64, 64);
			env->editor.skyboxes[i].size_down = new_point(64, 64);
			env->editor.skyboxes[i].pos = new_point(300 + (64 * (i % mod)) + 5,
			(150 + 20 + (((MAX_WALL_TEXTURE / mod_e)) * 64)) + 64 * (i / mod) + 5);
		}
		else
		{
			env->editor.skyboxes[i] = new_image_button(WHEN_DOWN, &save_texture, new_button_target(env, (-i -1)), env);
			env->editor.skyboxes[i].img_up = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_hover = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_pressed = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].img_down = env->mini_skyboxes[i].surface;
			env->editor.skyboxes[i].size_up = new_point(128, 128);
			env->editor.skyboxes[i].size_hover = new_point(128, 128);
			env->editor.skyboxes[i].size_pressed = new_point(128, 128);
			env->editor.skyboxes[i].size_down = new_point(128, 128);
		}
		
		i++;
	}
	return (0);
}