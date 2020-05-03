/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:47:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:17:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

void		write_event_links(int fd, t_event event)
{
	size_t	i;

	i = 0;
	while (i < event.nb_launch_conditions)
	{
		if (event.launch_conditions[i].type == EVENT_ENDED
			|| event.launch_conditions[i].type == EVENT_ENDED_START)
		{
			write_event_link(fd, event.launch_conditions[i]);
		}
		i++;
	}
}

void		write_sector_links(int fd, t_sector sector)
{
	size_t	i;

	i = 0;
	while (i < sector.nb_stand_events)
	{
		write_event_links(fd, sector.stand_events[i]);
		i++;
	}
	i = 0;
	while (i < sector.nb_walk_in_events)
	{
		write_event_links(fd, sector.walk_in_events[i]);
		i++;
	}
	i = 0;
	while (i < sector.nb_walk_out_events)
	{
		write_event_links(fd, sector.walk_out_events[i]);
		i++;
	}
}

void		write_enemies_links(int fd, t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < env->nb_enemies)
	{
		j = 0;
		while (j < env->enemies[i].nb_collision_events)
		{
			write_event_links(fd, env->enemies[i].collision_events[j]);
			j++;
		}
		j = 0;
		while (j < env->enemies[i].nb_death_events)
		{
			write_event_links(fd, env->enemies[i].death_events[j]);
			j++;
		}
		i++;
	}
}

void		write_objects_links(int fd, t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < env->nb_objects)
	{
		j = 0;
		while (j < env->objects[i].nb_collision_events)
		{
			write_event_links(fd, env->objects[i].collision_events[j]);
			j++;
		}
		i++;
	}
}

void		write_events_links(int fd, t_env *env)
{
	size_t	i;
	int		j;

	ft_dprintf(fd, "Links\n");
	i = 0;
	while (i < env->nb_global_events)
	{
		write_event_links(fd, env->global_events[i]);
		i++;
	}
	j = 0;
	while (j < env->nb_sectors)
	{
		write_sector_links(fd, env->sectors[j]);
		j++;
	}
	write_enemies_links(fd, env);
	write_objects_links(fd, env);
}
