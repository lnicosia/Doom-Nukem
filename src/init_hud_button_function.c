/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/27 17:02:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	change_ceiling_sprite(t_button_next *button)
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
}

void	change_floor_sprite(t_button_next *button)
{
	t_env *env;

	env = button->env;
	if (button->type == PREVIOUS)
	{
		if (env->selected_floor_sprite > 0)
			env->selected_floor_sprite--;
	}
	else if (button->type == NEXT)
	{
		if (env->selected_floor_sprite <
		env->sectors[env->selected_floor].floor_sprites.nb_sprites)
			env->selected_floor_sprite++;
	}
}

void	change_wall_sprite(t_button_next *button)
{	
	t_env *env;

	env = button->env;
	if (button->type == PREVIOUS)
	{
		if (env->editor.selected_wall_sprite > 0)
			env->editor.selected_wall_sprite--;
	}
	else if (button->type == NEXT)
	{
		if (env->editor.selected_wall_sprite <
		env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].nb_sprites)
			env->editor.selected_wall_sprite++;
	}
}

void	change_sprite(void *target)
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
}

void	add_object_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.create_object = 1;
	if (!env->editor.draw_object_tab)
		env->editor.create_object = 1;
	else
		env->editor.add_object.state = UP;
}


void	add_enemy_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	if (!env->editor.draw_enemy_tab)
		env->editor.create_enemy = 1;
	else
		env->editor.add_enemy.state = UP;
}

void	save_texture(void *param)
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
}

void	save_enemy(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_target*)param)->env;
	i = ((t_button_target*)param)->i;
	env->editor.current_enemy = env->enemy_main_sprite[i];
	env->editor.current_enemy_selection.img_down = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_pressed = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_hover = env->mini_enemies_textures[i].surface;
	env->editor.current_enemy_selection.img_up = env->mini_enemies_textures[i].surface;
	env->editor.draw_enemy_tab = 0;
}

void	nothing(void *target)
{
	(void)target;
}

void	general_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
}

void	sector_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
}

void	sprite_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
}

void	events_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
}
