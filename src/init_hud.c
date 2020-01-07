/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:10:19 by sipatry           #+#    #+#             */
/*   Updated: 2019/12/04 18:37:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	save_texture(void *target)
{
	t_button *button;

	button = (t_button*)target;
	button->state = 1;
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
	if (!(env->editor.textures = (t_button*)malloc(sizeof(t_button) * MAX_WALL_TEXTURE)))
		return (ft_perror("Could not maloc the texture buttons array"));
	while (i < MAX_WALL_TEXTURE - 1)
	{
		env->editor.textures[i] = new_image_button(WHEN_DOWN, &save_texture, &env->editor.textures[i], env);
		env->editor.textures[i].img_up = &env->wall_textures[i];
		env->editor.textures[i].img_pressed = &env->wall_textures[i];
		env->editor.textures[i].img_down = &env->wall_textures[i];
		env->editor.textures[i].size_up = new_point(64, 64);
		env->editor.textures[i].size_down = new_point(env->editor.textures[i].img_down->surface->w,
		env->editor.textures[i].img_down->surface->h);
        	env->editor.textures[i].size_hover = new_point(env->editor.textures[i].img_hover->surface->w,
        	env->editor.textures[i].img_hover->surface->h);
		env->editor.textures[i].size_pressed = new_point(env->editor.textures[i].img_pressed->surface->w,
		env->editor.textures[i].img_pressed->surface->h);
		env->editor.textures[i].pos = new_point(60 + (64 * (i % mod)) + 5, 370 + 5 + (64 * (i / mod)));
		i++;
	}
     	env->editor.current_texture_selection = new_image_button(ON_PRESS, &save_texture, &env->editor.current_texture_selection, env);
	env->editor.current_texture_selection.img_up = &env->wall_textures[env->editor.current_texture];
	env->editor.current_texture_selection.img_pressed = &env->wall_textures[env->editor.current_texture];
	env->editor.current_texture_selection.img_down = &env->wall_textures[env->editor.current_texture];
	env->editor.current_texture_selection.size_up = new_point(64, 64);
	env->editor.current_texture_selection.size_down = new_point(env->editor.current_texture_selection.img_down->surface->w,
	env->editor.current_texture_selection.img_down->surface->h);
        env->editor.current_texture_selection.size_hover = new_point(env->editor.current_texture_selection.img_hover->surface->w,
        env->editor.current_texture_selection.img_hover->surface->h);
        env->editor.current_texture_selection.size_pressed = new_point(env->editor.current_texture_selection.img_pressed->surface->w,
        env->editor.current_texture_selection.img_pressed->surface->h);	
        env->editor.current_texture_selection.pos = new_point(10, 350);
	return (1);
}

void	init_enemy_selection_button(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_ENEMY > 20)
		mod = 10;
	else
		mod = 5;
	i = 0;
 	while (i < MAX_ENEMIES)
	{
		env->editor.enemies.img_up = &env->enemy_sprite[env->editor.enemies[i]];
		env->editor.enemies.img_pressed = &env->wall_textures[env->editor.current_texture];
		env->editor.enemies.img_down = &env->wall_textures[env->editor.current_texture];
		env->editor.enemies.size_up = new_point(64, 64);
		env->editor.enemies.size_down = new_point(env->editor.current_enemy_selection.img_down->surface->w,
		env->editor.enemies.img_down->surface->h);
        	env->editor.enemies.size_hover = new_point(env->editor.current_enemy_selection.img_hover->surface->w,
        	env->editor.enemies.img_hover->surface->h);
        	env->editor.enemies.size_pressed = new_point(env->editor.current_enemy_selection.img_pressed->surface->w,
        	env->editor.enemies.img_pressed->surface->h);	
		env->editor.enemies.pos = new_point(120 + (64 * (i % mod)) + 5, 370 + 5 + (64 * (i / mod)));
		i++;
	}
	env->editor.current_enemy_selection.img_up = &env->editor.main-enemies_sprite[env->editor.current_enemy];
	env->editor.current_enemy_selection.img_pressed = &env->wall_textures[env->editor.current_texture];
	env->editor.current_enemy_selection.img_down = &env->wall_textures[env->editor.current_texture];
	env->editor.current_enemy_selection.size_up = new_point(64, 64);
	env->editor.current_enemy_selection.size_down = new_point(env->editor.current_enemy_selection.img_down->surface->w,
	env->editor.current_enemy_selection.img_down->surface->h);
        env->editor.current_enemy_selection.size_hover = new_point(env->editor.current_enemy_selection.img_hover->surface->w,
        env->editor.current_enemy_selection.img_hover->surface->h);
        env->editor.current_enemy_selection.size_pressed = new_point(env->editor.current_enemy_selection.img_pressed->surface->w,
        env->editor.current_enemy_selection.img_pressed->surface->h);	
        env->editor.current_enemy_selection.pos = new_point(80, 350);

}

void	init_options_buttons(t_env *env)
{
	editor_mode_button(env);
	editor_save_button(env);
}

int	init_hud(t_env *env)
{
	if (!init_array_texture_buttons(env))
		return (0);
	init_enemy_selection_button(env);
	init_options_buttons(env);
	return (1);
}
