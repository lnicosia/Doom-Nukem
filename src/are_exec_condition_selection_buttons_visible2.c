/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_exec_condition_selection_buttons_visibl        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:37:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:37:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_sector_exec_conditions(t_env *env,
int sector)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (sector != -1 && ((events == 0 && env->sectors[sector].
		nb_stand_events > 0 && env->sectors[sector].stand_events[event].
		nb_exec_conditions > 1) || (events == 1 && env->sectors[sector].
		nb_walk_in_events > 0 && env->sectors[sector].walk_in_events[event].
		nb_exec_conditions > 1)
		|| (events == 2 && env->sectors[sector].
		nb_walk_out_events > 0 && env->sectors[sector].walk_out_events[event].
		nb_exec_conditions > 1)))
		return (1);
	return (0);
}

int			check_sector_launch_conditions(t_env *env,
int sector)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (sector != -1 && ((events == 0 && env->sectors[sector].
		nb_stand_events > 0 && env->sectors[sector].stand_events[event].
		nb_launch_conditions > 1) || (events == 1 && env->sectors[sector].
		nb_walk_in_events > 0 && env->sectors[sector].walk_in_events[event].
		nb_launch_conditions > 1)
		|| (events == 2 && env->sectors[sector].
		nb_walk_out_events > 0 && env->sectors[sector].walk_out_events[event].
		nb_launch_conditions > 1)))
		return (1);
	return (0);
}
