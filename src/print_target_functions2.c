/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 10:42:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)event;
	(void)pos;
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: %s's %s",
	env->weapons[event->update_param.weapon].name,
	env->event_types[event->target_index]);
	return (pos.y);
}

int		print_ceiling_sprite_target(t_env *env, t_event *event, t_point pos,
int size)
{
	(void)event;
	(void)size;
	(void)pos;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Sector %d ceiling sprite"
	" %d %s", event->update_param.sector, event->update_param.sprite,
	env->event_types[event->target_index]);
	return (pos.y);
}

int		print_enemy_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)event;
	(void)pos;
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Enemy %d %s",
	event->update_param.enemy, env->event_types[event->target_index]);
	return (pos.y);
}

int		print_object_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)event;
	(void)pos;
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Object %d %s",
	event->update_param.object, env->event_types[event->target_index]);
	return (pos.y);
}

int		print_nothing_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)event;
	(void)pos;
	(void)size;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%s",
	env->event_types[event->target_index]);
	return (pos.y);
}
