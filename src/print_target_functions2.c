/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 19:13:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Weapon %d",
	event->update_param.weapon);
	print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_ceiling_sprite_target(t_env *env, t_event *event, t_point pos,
int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Sector %d ceiling sprite"
	" %d", event->update_param.sector, event->update_param.sprite);
	print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_enemy_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Enemy %d",
	event->update_param.enemy);
	print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_object_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Target: Object %d",
	event->update_param.object);
	print_text(pos, new_printable_text(env->snprintf, font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}

int		print_nothing_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(env->event_types[event->target_index],
	font, 0xFFFFFFFF, 0), env);
	return (pos.y);
}
