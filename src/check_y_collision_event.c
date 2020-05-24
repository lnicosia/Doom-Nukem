/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_y_collision_event.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:06:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:06:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "events_parser.h"
#include "parser.h"

int		check_y_collision_event2(t_event *event, t_motion movement, t_env *env)
{
	t_v3		move;
	int			sector;

	move.y = event->incr;
	if (!event->speed)
	{
		move = env->player.pos;
		move.y = event->goal;
		if ((sector = get_sector_no_z(env, move)) == -1
			|| intersects_with_sector(&env->sectors[get_sector_no_z(env, move)],
			move, env))
			return (1);
	}
	else
	{
		move = check_collision(env, move, movement);
		if (!move.y)
			return (1);
	}
	return (0);
}

int		check_y_collision_event(t_event *event, void *penv)
{
	t_motion	movement;
	t_env		*env;

	env = (t_env*)penv;
	ft_bzero(&movement, sizeof(t_motion));
	movement.lowest_ceiling = find_lowest_ceiling(env, movement);
	movement = new_motion(env->player.sector, env->player.size_2d,
			env->player.eyesight, env->player.pos);
	movement.flight = env->player.state.fly;
	return (check_y_collision_event2(event, movement, env));
}
