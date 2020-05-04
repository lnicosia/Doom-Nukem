/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:43:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:43:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		save_enemy(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_param*)param)->env;
	i = ((t_button_param*)param)->i;
	env->editor.current_enemy = env->enemies_main_sprites[i];
	if (env->selected_enemy != -1)
		env->enemies[env->selected_enemy].sprite = env->editor.current_enemy;
	env->editor.draw_enemy_tab = 0;
	env->editor.click_locked = 1;
	env->editor.current_enemy_selection.state = UP;
	env->editor.current_enemy_selection.anim_state = REST;
	init_enemies_data(env);
	return (0);
}

int		save_object(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_param*)param)->env;
	i = ((t_button_param*)param)->i;
	env->editor.current_object = env->objects_main_sprites[i];
	if (env->selected_object != -1)
		env->objects[env->selected_object].sprite =
		env->editor.current_object;
	env->editor.draw_object_tab = 0;
	env->editor.click_locked = 1;
	env->editor.current_object_selection.state = UP;
	env->editor.current_object_selection.anim_state = REST;
	init_objects_data(env);
	return (0);
}

int		save_sprite2(int i, t_wall_sprites *sprite, t_env *env)
{
	if (env->selected_floor_sprite != -1)
	{
		sprite = &env->sectors[env->selected_floor].floor_sprites;
		sprite->sprite[env->selected_floor_sprite] =
		env->objects_main_sprites[i];
		precompute_floor_sprite_scales(env->selected_floor,
		env->selected_floor_sprite, env);
	}
	env->editor.draw_sprite_tab = 0;
	env->editor.click_locked = 1;
	return (0);
}

int		save_sprite(void *param)
{
	t_env			*env;
	t_wall_sprites	*sprite;
	int				i;

	env = ((t_button_param*)param)->env;
	i = ((t_button_param*)param)->i;
	env->editor.current_sprite = env->objects_main_sprites[i];
	if (env->selected_wall_sprite_sprite != -1)
	{
		sprite = env->sectors[env->editor.selected_sector].wall_sprites;
		sprite[env->selected_wall_sprite_wall].
		sprite[env->selected_wall_sprite_sprite] = env->objects_main_sprites[i];
	}
	if (env->selected_ceiling_sprite != -1)
	{
		sprite = &env->sectors[env->selected_ceiling].ceiling_sprites;
		sprite->sprite[env->selected_ceiling_sprite] =
		env->objects_main_sprites[i];
		precompute_ceiling_sprite_scales(env->selected_ceiling,
		env->selected_ceiling_sprite, env);
	}
	return (save_sprite2(i, sprite, env));
}
