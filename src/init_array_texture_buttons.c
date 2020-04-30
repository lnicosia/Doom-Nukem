/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_texture_buttons.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:46:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:46:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_array_texture_buttons2(t_env *env)
{
	env->editor.current_texture_selection = new_image_button(ON_RELEASE,
	&open_texture_selection, env, env);
	env->editor.current_texture_selection.img_up =
	env->wall_textures[env->editor.current_texture].maps[7];
	env->editor.current_texture_selection.img_pressed =
	env->wall_textures[env->editor.current_texture].maps[7];
	env->editor.current_texture_selection.img_down =
	env->wall_textures[env->editor.current_texture].maps[7];
	env->editor.current_texture_selection.img_hover =
	env->wall_textures[env->editor.current_texture].maps[7];
	env->editor.current_texture_selection.size_up = new_point(128, 128);
	env->editor.current_texture_selection.size_down = new_point(128, 128);
	env->editor.current_texture_selection.size_hover = new_point(128, 128);
	env->editor.current_texture_selection.size_pressed = new_point(128, 128);
	env->editor.current_texture_selection.pos = new_point(230, 60);
	return (1);
}

int	init_array_texture_buttons(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_WALL_TEXTURE > 25)
		mod = 10;
	else
		mod = 5;
	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		env->editor.textures[i] = new_image_button(ON_RELEASE, &save_texture,
		new_button_target(env, i), env);
		env->editor.textures[i].img_up = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_pressed = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_down = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_hover = env->wall_textures[i].maps[6];
		env->editor.textures[i].size_up = new_point(64, 64);
		env->editor.textures[i].size_down = new_point(64, 64);
		env->editor.textures[i].size_hover = new_point(64, 64);
		env->editor.textures[i].size_pressed = new_point(64, 64);
		env->editor.textures[i].pos =
		new_point(300 + (66 * (i % mod)) + 7, 150 + 7 + (66 * (i / mod)));
		i++;
	}
	return (init_array_texture_buttons2(env));
}
