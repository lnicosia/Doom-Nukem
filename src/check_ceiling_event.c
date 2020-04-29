/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:01:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:02:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		check_ceiling_event3(t_event *event, t_sector *sector,
double prec, t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == event->check_param.sector
			&& env->enemies[i].pos.z + env->enemies[i].scale >=
			get_ceiling_at_pos(sector, env->player.pos, env))
		{
			env->sectors[sector->num].ceiling = prec;
			update_sector_slope(env, &env->sectors[sector->num]);
			return (1);
		}
		i++;
	}
	env->sectors[sector->num].ceiling = prec;
	update_sector_slope(env, &env->sectors[sector->num]);
	return (0);
}

int		check_ceiling_event2(t_event *event, t_sector *sector,
double prec, t_env *env)
{
	double		z;

	if (env->player.sector == event->check_param.sector)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			env->sectors[sector->num].ceiling = prec;
			update_sector_slope(env, &env->sectors[sector->num]);
			return (1);
		}
	}
	return (check_ceiling_event3(event, sector, prec, env));
}

int		check_ceiling_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	*sector;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = &env->sectors[event->check_param.sector];
	prec = sector->ceiling;
	sector->ceiling = event->start_value + time * event->incr;
	if (!event->speed)
		sector->ceiling = event->goal;
	update_sector_slope(env, sector);
	if (sector->floor_max > sector->ceiling_min)
	{
		env->sectors[sector->num].ceiling = prec;
		update_sector_slope(env, &env->sectors[sector->num]);
		return (1);
	}
	return (check_ceiling_event2(event, sector, prec, env));
}
