/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_condition_target_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:38:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:38:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d %s %s %.*f",
	condition->sector, env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	return (pos.y);
}

int		print_wall_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d wall %d %s %s %.*f",
	condition->sector, condition->wall,
	env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	return (pos.y);
}

int		print_floor_sprite_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d floor sprite %d %s"
	" %s %.*f", condition->sector, condition->sprite,
	env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	return (pos.y);
}

int		print_wall_sprite_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d wall %d sprite %d %s"
	" %s %.*f", condition->sector, condition->wall, condition->sprite,
	env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	return (pos.y);
}

int		print_vertex_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Vertex %d %s %s %.*f",
	condition->vertex, env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	return (pos.y);
}
