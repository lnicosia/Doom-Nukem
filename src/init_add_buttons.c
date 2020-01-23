/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:29:15 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/23 17:10:49 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"env.h"

void	init_change_sprite_button(t_env *env)
{
	env->editor.next_sprite = new_next_button(WHEN_DOWN, &change_sprite, env, env);
	env->editor.next_sprite.pos = new_point(30, 450);
	
	env->editor.previous_sprite = new_previous_button(WHEN_DOWN, &change_sprite, env, env);
	env->editor.previous_sprite.pos	 = new_point(280, 450);
}

void	init_add_object_button(t_env *env)
{
	env->editor.add_object = new_image_button(WHEN_DOWN, &add_object_button, env, env);
	env->editor.add_object.img_up = env->ui_textures[12].surface;
	env->editor.add_object.img_pressed = env->ui_textures[13].surface;
	env->editor.add_object.img_down = env->ui_textures[13].surface;
	env->editor.add_object.img_hover = env->ui_textures[14].surface;
	env->editor.add_object.size_up = new_point(64, 64);
	env->editor.add_object.size_down = new_point(64, 64);
    env->editor.add_object.size_hover = new_point(64, 64);
    env->editor.add_object.size_pressed = new_point(64, 64);	
    env->editor.add_object.pos = new_point(102, 152);
}


void	init_add_enemy_button(t_env *env)
{
	env->editor.add_enemy = new_image_button(WHEN_DOWN, &add_enemy_button, env, env);
	env->editor.add_enemy.img_up = env->ui_textures[12].surface;
	env->editor.add_enemy.img_pressed = env->ui_textures[13].surface;
	env->editor.add_enemy.img_down = env->ui_textures[13].surface;
	env->editor.add_enemy.img_hover = env->ui_textures[14].surface;
	env->editor.add_enemy.size_up = new_point(64, 64);
	env->editor.add_enemy.size_down = new_point(64, 64);
    env->editor.add_enemy.size_hover = new_point(64, 64);
    env->editor.add_enemy.size_pressed = new_point(64, 64);	
    env->editor.add_enemy.pos = new_point(102, 252);
}

void	init_add_buttons(t_env *env)
{
	init_add_enemy_button(env);
	init_add_object_button(env);
	init_change_sprite_button(env);
}