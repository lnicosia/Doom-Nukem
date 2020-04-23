/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shoot_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:19:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 17:09:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		new_shoot_event(t_env *env, t_event_trigger trigger, t_event event)
{
	if (!(env->sectors[trigger.sector].wall_sprites[
		trigger.wall].shoot_events[trigger.sprite] =
		(t_event*)ft_realloc(env->sectors[trigger.sector].
		wall_sprites[trigger.wall].shoot_events[
		trigger.sprite], sizeof(t_event) * env->sectors[
		trigger.sector].wall_sprites[trigger.wall].
		nb_shoot_events[trigger.sprite], sizeof(t_event)
		* (env->sectors[trigger.sector].wall_sprites[
		trigger.wall].nb_shoot_events[trigger.sprite] + 1))))
		return (ft_perror("Could not realloc global events"));
	env->sectors[trigger.sector].wall_sprites[trigger.wall].
	shoot_events[trigger.sprite][env->sectors[trigger.sector].
	wall_sprites[trigger.wall].nb_shoot_events[trigger.sprite]] = event;
	env->sectors[trigger.sector].wall_sprites[trigger.wall].
	nb_shoot_events[trigger.sprite]++;
	return (0);
}

int		new_parser_shoot_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)parser;
	(void)line;
	if (!(env->sectors[eparser->trigger_sector].wall_sprites[eparser->
		trigger_wall].shoot_events[eparser->trigger_sprite] =
		(t_event*)ft_realloc(env->sectors[eparser->trigger_sector].
		wall_sprites[eparser->trigger_wall].
		shoot_events[eparser->trigger_sprite],
		sizeof(t_event) * env->sectors[eparser->trigger_sector].
		wall_sprites[eparser->trigger_wall].
		nb_shoot_events[eparser->trigger_sprite],
		sizeof(t_event) * (env->sectors[eparser->trigger_sector].
		wall_sprites[eparser->trigger_wall].nb_shoot_events[eparser->
		trigger_sprite] + 1))))
		return (ft_perror("Could not realloc global events"));
	env->sectors[eparser->trigger_sector].wall_sprites[eparser->trigger_wall].
	shoot_events[eparser->trigger_sprite][env->sectors[eparser->trigger_sector].
	wall_sprites[eparser->trigger_wall].nb_shoot_events[eparser->
	trigger_sprite]] = eparser->event;
	env->sectors[eparser->trigger_sector].wall_sprites[eparser->trigger_wall].
	nb_shoot_events[eparser->trigger_sprite]++;
	return (0);
}
