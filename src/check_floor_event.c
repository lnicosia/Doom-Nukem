/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:03:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:20:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		check_floor_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	*sector;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = &env->sectors[event->check_param.sector];
	prec = sector->floor;
	sector->floor = event->start_value + time * event->incr;
	if (!event->speed)
		sector->floor = event->goal;
	update_sector_slope(env, sector);
	if (sector->floor_max > sector->ceiling_min
		|| check_entities_height_game(sector, env))
	{
		sector->floor = prec;
		update_sector_slope(env, &env->sectors[sector->num]);
		return (1);
	}
	env->sectors[sector->num].floor = prec;
	update_sector_slope(env, &env->sectors[sector->num]);
	return (0);
}
