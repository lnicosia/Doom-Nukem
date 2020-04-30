/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_array3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:19:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:20:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

t_event	*get_global_event(t_env *env, t_events_parser *eparser, int mode)
{
	(void)eparser;
	if (!mode)
		return (&env->global_events[eparser->source_index]);
	else
		return (&env->global_events[eparser->target_index]);
}

t_event	*get_press_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			wall_sprites[eparser->source_wall].
			press_events[eparser->source_sprite][eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector].
			wall_sprites[eparser->target_wall].
			press_events[eparser->target_sprite][eparser->target_index]);
}

t_event	*get_shoot_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			wall_sprites[eparser->source_wall].
			shoot_events[eparser->source_sprite][eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector].
			wall_sprites[eparser->target_wall].
			shoot_events[eparser->target_sprite][eparser->target_index]);
}

t_event	*get_stand_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			stand_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector].
			stand_events[eparser->target_index]);
}
