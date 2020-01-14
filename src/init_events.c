/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:18:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/14 17:19:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_event	new_fixed_event(int type, void *target, double goal, Uint32 duration)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = FIXED;
	if (duration)
		new.duration = duration;
	else
		new.duration = 1;
	new.type = type;
	new.goal = goal;
	update_event(&new);
	return (new);
}

t_event	new_incr_event(int type, void *target, double start_incr, Uint32 duration)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = INCR;
	if (duration)
		new.duration = duration;
	else
		new.duration = 1;
	new.type = type;
	new.start_incr = start_incr;
	update_event(&new);
	return (new);
}

t_event	new_func_event(int (*func)(void *, void *), void *param)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.type = FUNC;
	new.exec_func = func;
	new.exec_param = param;
	update_event(&new);
	return (new);
}
