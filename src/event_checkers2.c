/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checkers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:50:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:50:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		check_texture_event(t_event *event, void *penv)
{
	(void)penv;
	if ((event->incr > 0 && *(int*)event->target >= MAX_WALL_TEXTURE - 1)
			|| (event->incr < 0 && *(int*)event->target <= -MAX_SKYBOX)
			|| (!event->speed && ((int)event->goal >= MAX_WALL_TEXTURE
					|| (int)event->goal < -MAX_SKYBOX)))
		return (1);
	return (0);
}

int		check_sprite_event(t_event *event, void *penv)
{
	(void)penv;
	if ((event->incr > 0 && *(int*)event->target >= MAX_OBJECT_SPRITES - 1)
			|| (event->incr < 0 && *(int*)event->target <= 0)
			|| (!event->speed && ((int)event->goal >= MAX_OBJECT_SPRITES
					|| (int)event->goal < 0)))
		return (1);
	return (0);
}

int		check_scale_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr > 100)
		|| (event->incr < 0 && event->start_value + time * event->incr < 0.1)
		|| (!event->speed && (event->goal > 100 || event->goal < 0.1)))
		return (1);
	return (0);
}

int		check_speed_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr > 1)
		|| (event->incr < 0 && event->start_value + time * event->incr <= 0)
		|| (!event->speed && (event->goal > 1 || event->goal <= 0)))
		return (1);
	return (0);
}
