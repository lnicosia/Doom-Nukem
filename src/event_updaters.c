/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/02 16:20:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

t_event_param	new_event_param(int num, double equ_value, double diff_value,
t_v3 move)
{
		t_event_param	new;

		ft_bzero(&new, sizeof(new));
		new.num = num;
		new.move = move;
		new.equ_value = equ_value;
		new.diff_value = diff_value;
		return (new);
}

t_event_param	empty_event_param(void)
{
		t_event_param	new;

		ft_bzero(&new, sizeof(new));
		return (new);
}
void			update_sector_event(t_event *event, void *penv)
{
		t_env	*env;

		env = (t_env*)penv;
		update_sector_slope(env, &env->sectors[event->update_param.num]);
}

void			update_player_event(t_event *event, void *penv)
{
		(void)event;
		update_player_pos((t_env*)penv);
}

int				check_collision_event(t_event *event, void *penv)
{
		t_movement	movement;
		t_v3		move;
		t_env		*env;

		env = (t_env*)penv;
		movement = new_movement(env->player.sector, env->player.size_2d,
		env->player.eyesight, env->player.pos);
		move = check_collision(env, event->check_param.move, movement, 0);
		if (!move.x && !move.y && !move.z)
				return (0);
		return (1);
}

void			delete_itself_event(t_event *event, void *penv)
{
	ft_delindex(event->update_param.target,
	sizeof(*event->update_param.target) * event->update_param.size,
	sizeof(*event->update_param.target),
	sizeof(*event->update_param.target) * event->update_param.num);
	(void)penv;
}

int				check_equ_value_event(t_event *event, void *penv)
{
		(void)penv;
		if (event->type == INT
				&& event->check_param.equ_value == *(int*)event->target)
				return (1);
		else if (event->type == DOUBLE
				&& event->check_param.equ_value == *(double*)event->target)
				return (1);
		return (0);
}

int				check_diff_value_event(t_event *event, void *penv)
{
		(void)penv;
		if (event->type == INT
				&& event->check_param.diff_value != *(int*)event->target)
				return (1);
		else if (event->type == DOUBLE
				&& event->check_param.diff_value != *(double*)event->target)
				return (1);
		return (0);
}
