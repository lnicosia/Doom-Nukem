/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_checkers2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:10:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:10:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_entities_sprite_scale_input_box(void *penv)
{
	double		scale;
	t_env		*env;
	t_sector	*sector;

	env = (t_env*)penv;
	sector = NULL;
	scale = ft_atof(env->input_box.str);
	if (env->selected_object != -1)
		sector = &env->sectors[env->objects[env->selected_object].sector];
	if (env->selected_enemy != -1)
		sector = &env->sectors[env->enemies[env->selected_enemy].sector];
	if (scale < 0.1 || scale > 100)
		return (1);
	else if (env->selected_enemy != -1 && check_height_at_pos(env, sector,
		env->enemies[env->selected_enemy].pos,
		(env->enemies[env->selected_enemy].scale + 1)))
		return (-1);
	else if (env->selected_object != -1
		&& check_height_at_pos(env, sector,
		env->objects[env->selected_object].pos,
		(env->objects[env->selected_object].scale + 1)))
		return (-1);
	return (0);
}

int		check_texture_scale_input_box(void *penv)
{
	double	scale;
	t_env	*env;

	env = (t_env*)penv;
	scale = ft_atof(env->input_box.str);
	if (scale < 1 || scale > 100)
		return (1);
	return (0);
}

int		check_damage_input_box(void *penv)
{
	int		damage;
	t_env	*env;

	env = (t_env*)penv;
	damage = ft_atof(env->input_box.str);
	if (damage < 0 || damage > 100)
		return (1);
	return (0);
}

int		check_light_data_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value < -255 || value > 255)
		return (1);
	return (0);
}

int		check_gravity_input_box(void *penv)
{
	double	value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atof(env->input_box.str);
	if (value && (value > -1 || value < -10))
		return (1);
	return (0);
}
