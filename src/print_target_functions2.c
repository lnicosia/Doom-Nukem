/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:26:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	(void)event;
	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Weapon %d %s",
	event->update_param.weapon, env->event_types[event->target_index]);
	//print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_ceiling_sprite_target(t_env *env, t_event *event, t_point pos,
int size)
{
	TTF_Font	*font;

	(void)event;
	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Sector %d ceiling sprite"
	" %d %s", event->update_param.sector, event->update_param.sprite,
	env->event_types[event->target_index]);
	//print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_enemy_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	(void)event;
	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Enemy %d %s",
	event->update_param.enemy, env->event_types[event->target_index]);
	//print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_object_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	(void)event;
	(void)pos;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Object %d %s",
	event->update_param.object, env->event_types[event->target_index]);
	//print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_nothing_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	(void)event;
	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%s",
	env->event_types[event->target_index]);
	return (pos.y);
}
