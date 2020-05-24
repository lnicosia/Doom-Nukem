/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:21:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:34:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

/*
**	Mode == source or target
*/

size_t	*get_global_event_nb(t_env *env, t_events_parser *eparser, int mode)
{
	(void)eparser;
	if (!mode)
		return (&env->global_events[eparser->source_index].
		nb_launch_conditions);
	else
		return (&env->global_events[eparser->target_index].
		nb_launch_conditions);
}

size_t	*get_press_event_nb(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
				wall_sprites[eparser->source_wall].
				press_events[eparser->source_sprite][eparser->source_index].
				nb_launch_conditions);
	else
		return (&env->sectors[eparser->target_sector].
				wall_sprites[eparser->target_wall].
				press_events[eparser->target_sprite][eparser->target_index].
				nb_launch_conditions);
}

size_t	*get_shoot_event_nb(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			wall_sprites[eparser->source_wall].
			shoot_events[eparser->source_sprite][eparser->source_index].
			nb_launch_conditions);
	else
		return (&env->sectors[eparser->target_sector].
			wall_sprites[eparser->target_wall].
			shoot_events[eparser->target_sprite][eparser->target_index].
			nb_launch_conditions);
}

size_t	*get_stand_event_nb(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			stand_events[eparser->source_index].
			nb_launch_conditions);
	else
		return (&env->sectors[eparser->target_sector].
			stand_events[eparser->target_index].
			nb_launch_conditions);
}

size_t	*get_walk_in_event_nb(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			walk_in_events[eparser->source_index].
			nb_launch_conditions);
	else
		return (&env->sectors[eparser->target_sector].
			walk_in_events[eparser->target_index].
			nb_launch_conditions);
}
