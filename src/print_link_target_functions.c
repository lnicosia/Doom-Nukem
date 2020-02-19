/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_target_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/14 19:40:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

int		print_global_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	char		*ended;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	if (condition->type == EVENT_ENDED)
		ended = "ended";
	else
		ended = "ended (start)";
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%s %d %s",
	env->event_links_types[condition->target_type],
	condition->target_index, ended);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0xFFFFFFFF, 0), env);*/
	return (pos.y);
}

int		print_sector_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	char		*ended;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	if (condition->type == EVENT_ENDED)
		ended = "ended";
	else
		ended = "ended (start)";
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d %s %d %s",
	condition->sector, env->event_links_types[condition->target_type],
	condition->target_index, ended);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0xFFFFFFFF, 0), env);*/
	return (pos.y);
}

int		print_enemy_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	char		*ended;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	if (condition->type == EVENT_ENDED)
		ended = "ended";
	else
		ended = "ended (start)";
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Enemy %d %s %d %s",
	condition->enemy, env->event_links_types[condition->target_type],
	condition->target_index, condition->value, ended);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0xFFFFFFFF, 0), env);*/
	return (pos.y);
}

int		print_wall_sprite_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	char		*ended;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	if (condition->type == EVENT_ENDED)
		ended = "ended";
	else
		ended = "ended (start)";
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d wall %d sprite %d"
	" %s %d %s", condition->sector, condition->wall, condition->sprite,
	env->event_links_types[condition->target_type], condition->target_index,
	ended);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0xFFFFFFFF, 0), env);*/
	return (pos.y);
}
