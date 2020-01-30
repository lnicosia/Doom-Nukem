/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_links_types.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:22:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 15:37:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		init_event_links_types(t_env *env)
{
	env->event_links_types[GLOBAL] = "Global event";
	env->event_links_types[PRESS] = "Sector          wall          sprite"
	"          press event";
	env->event_links_types[SHOOT] = "Sector          wall          sprite"
	"          shoot event";
	env->event_links_types[STAND] = "Sector          stand event";
	env->event_links_types[WALK_IN] = "Sector          walk in event";
	env->event_links_types[WALK_OUT] = "Walk out event";
	env->event_links_types[DEATH] = "Enemy death event";
}
