/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:41:55 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/27 13:39:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_array_sprite_buttons(t_env *env)
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
		// NE PAS OUBLIER DE FREE LES NEW_BUTTON_TARGET
		env->editor.sprite_selection[i] = new_image_button(WHEN_DOWN, &save_texture, new_button_target(env, i), env);
		env->editor.sprite_selection[i].img_up = env->wall_textures[i].maps[6];
		env->editor.sprite_selection[i].img_pressed = env->wall_textures[i].maps[6];
		env->editor.sprite_selection[i].img_down = env->wall_textures[i].maps[6];
		env->editor.sprite_selection[i].img_hover = env->wall_textures[i].maps[6];
		env->editor.sprite_selection[i].size_up = new_point(64, 64);
		env->editor.sprite_selection[i].size_down = new_point(64, 64);
		env->editor.sprite_selection[i].size_hover = new_point(64, 64);
		env->editor.sprite_selection[i].size_pressed = new_point(64, 64);
		env->editor.sprite_selection[i].pos = new_point(180 + (64 * (i % mod)) + 5, 490 + 5 + (64 * (i / mod)));
		i++;
	}
     	env->editor.current_sprite_selection = new_image_button(WHEN_DOWN, &save_texture, &env->editor.current_sprite_selection, env);
		env->editor.current_sprite_selection.img_up = env->wall_sprites[env->editor.current_texture].s;
		env->editor.current_sprite_selection.img_pressed = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_sprite_selection.img_down = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_sprite_selection.img_hover = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_sprite_selection.size_up = new_point(64, 64);
		env->editor.current_sprite_selection.size_down = new_point(64, 64);
		env->editor.current_sprite_selection.size_hover = new_point(64, 64);
		env->editor.current_sprite_selection.size_pressed = new_point(64, 64);
        env->editor.current_sprite_selection.pos = new_point(150, 450);
		env->editor.sprite_background = new_background_button(WHEN_DOWN, &nothing, &env->editor.texture_background, env);
		env->editor.sprite_background.pos = new_point(10, 350);
	return (1);
}