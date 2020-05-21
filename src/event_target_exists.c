/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_target_exists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:10:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 15:41:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"
#include "parser.h"

int		condition_target_exists(t_condition *condition, t_env *env)
{
	t_events_parser	eparser;
	t_event_trigger	trigger;

	if (condition->type == EVENT_ENDED || condition->type == EVENT_ENDED_START)
	{
		trigger = condition->target_trigger;
		if (get_event_array(env, trigger) != condition->target)
			return (0);
	}
	else
	{
		ft_bzero(&eparser, sizeof(eparser));
		eparser.target_index = condition->target_index;
		eparser.target_sector = condition->sector;
		eparser.target_wall = condition->wall;
		eparser.target_sprite = condition->sprite;
		eparser.target_enemy = condition->enemy;
		eparser.target_object = condition->object;
		eparser.target_vertex = condition->vertex;
		eparser.target_weapon = condition->weapon;
		if (set_event_target(env, &eparser) != condition->target)
			return (0);
	}
	return (1);
}

int		event_target_exists(t_event *event, t_env *env)
{
	t_events_parser	eparser;

	if (event->type != FUNC && !event->target)
		return (0);
	else
	{
		ft_bzero(&eparser, sizeof(eparser));
		eparser.target_index = event->target_index;
		eparser.target_sector = event->check_param.sector;
		eparser.target_wall = event->check_param.wall;
		eparser.target_sprite = event->check_param.sprite;
		eparser.target_enemy = event->check_param.enemy;
		eparser.target_object = event->check_param.object;
		eparser.target_vertex = event->check_param.vertex;
		eparser.target_weapon = event->check_param.weapon;
		if (set_event_target(env, &eparser) != event->target)
			return (0);
	}
	return (1);
}
