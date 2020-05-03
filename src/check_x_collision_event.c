/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x_collision_event.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:06:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:06:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "events_parser.h"

int		check_x_collision_event2(t_event *event, t_motion movement, t_env *env)
{
	t_v3	move;
	int		sector;

	move.x = event->incr;
	if (!event->speed)
	{
		move = env->player.pos;
		move.x = event->goal;
		if ((sector = get_sector_no_z(env, move)) == -1
			|| intersects_with_sector(&env->sectors[get_sector_no_z(env, move)],
			move, env))
			return (1);
	}
	else
	{
		move = check_collision(env, move, movement);
		if (!move.x)
			return (1);
	}
	return (0);
}

int		check_x_collision_event(t_event *event, void *penv)
{
	t_motion	movement;
	t_env		*env;

	env = (t_env*)penv;
	ft_bzero(&movement, sizeof(t_motion));
	movement.lowest_ceiling = find_lowest_ceiling(env, movement);
	movement = new_motion(env->player.sector, env->player.size_2d,
			env->player.eyesight, env->player.pos);
	movement.flight = env->player.state.fly;
	return (check_x_collision_event2(event, movement, env));
}
