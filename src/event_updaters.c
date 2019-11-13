/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/13 14:16:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

t_event_param	*new_event_param(int num, t_v3 move)
{
		t_event_param	*new;

		if (!(new = (t_event_param*)malloc(sizeof(t_event_param))))
				return (0);
		new->num = num;
		new->move = move;
		return (new);
}

void	update_sector_event(t_event_param *param, void *penv)
{
		t_env	*env;

		env = (t_env*)penv;
		update_sector_slope(env, &env->sectors[param->num]);
}

int		check_collision_event(t_event_param *param, void *penv)
{
		t_movement	movement;
		t_v3		move;
		t_env		*env;

		env = (t_env*)penv;
		movement = new_movement(env->player.sector, env->player.size_2d,
		env->player.eyesight, env->player.pos);
		move = check_collision(env, param->move, movement, 0);
		if (!move.x && !move.y && !move.z)
				return (0);
		return (1);
}

void	update_player_event(t_event_param *param, void *penv)
{
		(void)param;
		update_player_pos((t_env*)penv);
}
