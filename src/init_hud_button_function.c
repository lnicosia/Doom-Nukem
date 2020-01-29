/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/29 17:36:55 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_wall_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	if (env->sectors[env->editor.selected_sector].
		textures[env->editor.selected_wall] < 0)
		env->contains_skybox = 1;
	if (set_sector_wall_map_array(&env->sectors[env->editor.selected_sector],
		env->wall_textures[env->sectors[env->editor.selected_sector].
		textures[env->editor.selected_wall]], env->editor.selected_wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera, env->editor.selected_sector,
		env->editor.selected_wall, env))
		return (-1);
	return (0);
} 

int			update_ceiling_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	if (env->sectors[env->selected_ceiling].ceiling_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
		env->wall_textures[env->sectors[env->selected_ceiling].
		ceiling_texture], env))
		return (-1);
	return (0);
}

int			update_floor_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	if (env->sectors[env->selected_floor].floor_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
		env->wall_textures[env->sectors[env->selected_floor].
		floor_texture], env))
		return (-1);
	return (0);
}

int		change_ceiling_sprite(t_button_next *button)
{
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_ceiling_sprite > 0)
			env->selected_ceiling_sprite--;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_ceiling_sprite <
		env->sectors[env->selected_ceiling].ceiling_sprites.nb_sprites - 1)
			env->selected_ceiling_sprite++;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_floor_sprite(t_button_next *button)
{
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_floor_sprite > 0)
			env->selected_floor_sprite--;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_floor_sprite <
		env->sectors[env->selected_floor].floor_sprites.nb_sprites - 1)
			env->selected_floor_sprite++;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_wall_sprite(t_button_next *button)
{	
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_wall_sprite_sprite > 0)
			env->selected_wall_sprite_sprite--;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_wall_sprite_sprite <
		env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].nb_sprites - 1)
			env->selected_wall_sprite_sprite++;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_sprite(void *target)
{
	t_button_next	*button;
	t_env			*env;
	 
	env = (t_env *)target;
	button = NULL;
	if (env->editor.next_sprite.state == DOWN)
		button = &env->editor.next_sprite_env;
	else if (env->editor.previous_sprite.state == DOWN)
		button = &env->editor.previous_sprite_env;
	if (button->type == WALL_S)
		change_wall_sprite(button);
	else if (button->type == FLOOR_S)
		change_floor_sprite(button);
	else if (button->type == CEILING_S)
		change_ceiling_sprite(button);
	return (0);
}

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

int		save_texture(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_target*)param)->env;
	i = ((t_button_target*)param)->i;
	env->editor.current_texture = i;
	env->editor.current_texture_selection.img_down = env->wall_textures[i].maps[6];
	env->editor.current_texture_selection.img_pressed = env->wall_textures[i].maps[6];
	env->editor.current_texture_selection.img_hover = env->wall_textures[i].maps[6];
	env->editor.current_texture_selection.img_up = env->wall_textures[i].maps[6];
	env->editor.draw_selection_tab = 0;
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
