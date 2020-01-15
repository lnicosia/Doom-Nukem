/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:23:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 17:24:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser(t_events_parser *eparser)
{
	eparser->trigger_types[GLOBAL] = &new_global_event;
	eparser->trigger_types[PRESS] = &new_press_event;
	eparser->trigger_types[SHOOT] = &new_shoot_event;
	eparser->trigger_types[STAND] = &new_stand_event;
	eparser->trigger_types[WALK_IN] = &new_walk_in_event;
	eparser->trigger_types[WALK_OUT] = &new_walk_out_event;
	eparser->trigger_types[DEATH] = &new_death_event;
}
