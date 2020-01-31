/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 14:22:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		add_object_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.create_object = 1;
	if (!env->editor.draw_object_tab)
		env->editor.create_object = 1;
	else
		env->editor.add_object.state = UP;
		env->editor.add_object.anim_state = REST;
	return (0);
}


int		add_enemy_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	if (!env->editor.draw_enemy_tab)
		env->editor.create_enemy = 1;
	else
		env->editor.add_object.state = UP;
		env->editor.add_object.anim_state = REST;
	return (0);
}

int		open_enemy_selection(void *param)
{
	t_env *env;

	env = (t_env *)param;
	env->editor.draw_enemy_tab = 1;
	return (0);
}


int		open_wall_sprite_selection(void *param)
{
	t_env *env;

	env = ((t_button_target*)param)->env;
	env->editor.draw_sprite_tab = 1;
	return (0);
}

int		save_texture(void *param)
{
	t_env	*env;
	int		i;

	
	env = ((t_button_target*)param)->env;
	i = ((t_button_target*)param)->i;
	env->editor.current_texture = i;
	if (i >= 0)
	{
		env->editor.current_texture_selection.img_down = env->wall_textures[i].maps[6];
		env->editor.current_texture_selection.img_pressed = env->wall_textures[i].maps[6];
		env->editor.current_texture_selection.img_hover = env->wall_textures[i].maps[6];
		env->editor.current_texture_selection.img_up = env->wall_textures[i].maps[6];
	}
	if (i < 0)
	{
		env->contains_skybox = 1;
		env->editor.current_texture = -i - 1;
		env->editor.current_texture_selection.img_down = env->mini_skyboxes[-i - 1].surface;
		env->editor.current_texture_selection.img_pressed = env->mini_skyboxes[-i - 1].surface;
		env->editor.current_texture_selection.img_hover = env->mini_skyboxes[-i - 1].surface;
		env->editor.current_texture_selection.img_up = env->mini_skyboxes[-i - 1].surface;
	}
	if (env->editor.in_game)
	{
		if (env->selected_floor != -1)
		{
			env->sectors[env->selected_floor].floor_texture = i;
			update_floor_texture_button((void *)env);
		}
		else if (env->selected_ceiling != -1)
		{
			env->sectors[env->selected_ceiling].ceiling_texture = i;
			update_ceiling_texture_button((void *)env);
		}
		else if (env->editor.selected_wall != -1)
		{
			env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] = i;
			update_wall_texture_button((void *)env);
		}
	}
	env->editor.current_texture_selection.state = UP;
	env->editor.current_texture_selection.anim_state = REST;
	env->editor.draw_selection_tab = 0;
	return (0);
}

int		save_enemy(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_target*)param)->env;
	i = ((t_button_target*)param)->i;
	env->editor.current_enemy = env->enemies_main_sprites[i];
	env->editor.current_enemy_selection.img_down = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_pressed = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_hover = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_up = env->mini_enemies_textures[i].surface;
	if (env->selected_enemy != -1)
		env->enemies[env->selected_enemy].sprite = env->enemies_main_sprites[i];
	env->editor.draw_enemy_tab = 0;
	env->editor.current_enemy_selection.state = UP;
	env->editor.current_enemy_selection.anim_state = REST;
	return (0);
}

int		save_sprite(void *param)
{
	t_env	*env;
	t_wall_sprites *sprite;
	int		i;

	env = ((t_button_target*)param)->env;
	i = ((t_button_target*)param)->i;
	env->editor.current_sprite = env->objects_main_sprites[i];
	env->editor.current_sprite_selection.img_down = env->mini_objects_textures[i].surface;
	env->editor.current_sprite_selection.img_pressed = env->mini_objects_textures[i].surface;
	env->editor.current_sprite_selection.img_hover = env->mini_objects_textures[i].surface;
	env->editor.current_sprite_selection.img_up = env->mini_objects_textures[i].surface;
	if (env->selected_wall_sprite_sprite != -1)
	{
		sprite = env->sectors[env->editor.selected_sector].wall_sprites;
		sprite[env->selected_wall_sprite_wall].sprite[env->selected_wall_sprite_sprite] = env->objects_main_sprites[i];
	}
	if (env->selected_ceiling_sprite != -1)
	{
		sprite = &env->sectors[env->selected_ceiling].ceiling_sprites;
		sprite->sprite[env->selected_ceiling_sprite] = env->objects_main_sprites[i];
	}
	if (env->selected_floor_sprite != -1)
	{
		sprite = &env->sectors[env->selected_floor].floor_sprites;
		sprite->sprite[env->selected_floor_sprite] = env->objects_main_sprites[i];
	}
	env->editor.draw_sprite_tab = 0;
	env->editor.current_sprite_selection.state = UP;
	env->editor.current_sprite_selection.anim_state = REST;
	return (0);
}

int		nothing(void *target)
{
	(void)target;
	return (0);
}

int		general_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return(0);
}

int		sector_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		sprite_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		events_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	return (0);
}
