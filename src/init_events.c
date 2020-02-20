/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:18:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 15:26:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_event	new_fixed_event(int type, void *target, double goal, double speed)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = FIXED;
	new.type = type;
	new.goal = goal;
	new.speed = speed;
	update_event(&new);
	return (new);
}

t_event	new_incr_event(int type, void *target, double start_incr,
double speed)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = INCR;
	new.type = type;
	new.speed = speed;
	new.start_incr = start_incr;
	update_event(&new);
	return (new);
}

t_event	new_func_event(int (*func)(void *, void *), void *param)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.type = FUNC;
	new.mod_type = FUNC;
	new.exec_func = func;
	new.exec_param = param;
	update_event(&new);
	return (new);
}
