/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_links_types.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:22:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 15:01:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		init_event_links_types(t_env *env)
{
	env->event_links_types[GLOBAL] = "Global event";
	env->event_links_types[PRESS] = "press event";
	env->event_links_types[SHOOT] = "shoot event";
	env->event_links_types[STAND] = "stand event";
	env->event_links_types[WALK_IN] = "walk in event";
	env->event_links_types[WALK_OUT] = "walk out event";
	env->event_links_types[DEATH] = "death event";
}

void		init_print_link_target_data(t_env *env)
{
	env->print_link_target_data[GLOBAL] = &print_global_link_target;
	env->print_link_target_data[PRESS] = &print_wall_sprite_link_target;
	env->print_link_target_data[SHOOT] = &print_wall_sprite_link_target;
	env->print_link_target_data[STAND] = &print_sector_link_target;
	env->print_link_target_data[WALK_IN] = &print_sector_link_target;
	env->print_link_target_data[WALK_OUT] = &print_sector_link_target;
	env->print_link_target_data[DEATH] = &print_enemy_link_target;
	env->print_link_target_data[ENEMY_COLLISION] = &print_enemy_link_target;
	env->print_link_target_data[OBJECT_COLLISION] = &print_object_link_target;
}
