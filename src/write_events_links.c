/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:47:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 19:00:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

void		write_event_link(int fd, t_condition condition)
{
	ft_printf("cc\n");
	ft_dprintf(fd, "[%d ", condition.source_type);
	if (condition.source_type == PRESS || condition.source_type == SHOOT)
		ft_dprintf(fd, "(%d %d %d) ", condition.source_sector,
		condition.source_wall, condition.source_sprite);
	else if (condition.source_type == STAND || condition.source_type == WALK_IN
		|| condition.source_type == WALK_OUT)
		ft_dprintf(fd, "(%d) ", condition.source_sector);
	else if (condition.source_type == DEATH)
		ft_dprintf(fd, "(%d) ", condition.source_enemy);
	ft_dprintf(fd, "%d]", condition.source_index);
	ft_dprintf(fd, "[%d ", condition.target_type);
	if (condition.target_type == PRESS || condition.target_type == SHOOT)
		ft_dprintf(fd, "(%d %d %d) ", condition.target_sector,
		condition.target_wall, condition.target_sprite);
	else if (condition.target_type == STAND || condition.target_type == WALK_IN
		|| condition.target_type == WALK_OUT)
		ft_dprintf(fd, "(%d) ", condition.target_sector);
	else if (condition.target_type == DEATH)
		ft_dprintf(fd, "(%d) ", condition.target_enemy);
	ft_dprintf(fd, "%d]", condition.target_index);
	if (condition.type == EVENT_ENDED)
		ft_dprintf(fd, "[0]\n", condition.type);
	else
		ft_dprintf(fd, "[1]\n", condition.type);
}

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
	ft_printf("%d stand events \n", sector.nb_stand_events);
	while (i < sector.nb_stand_events)
	{
		write_event_links(fd, sector.stand_events[i]);
		i++;
	}
	i = 0;
	ft_printf("%d walk in events \n", sector.nb_walk_in_events);
	while (i < sector.nb_walk_in_events)
	{
		write_event_links(fd, sector.walk_in_events[i]);
		i++;
	}
	i = 0;
	ft_printf("%d walk out events \n", sector.nb_walk_out_events);
	while (i < sector.nb_walk_out_events)
	{
		write_event_links(fd, sector.walk_out_events[i]);
		i++;
	}
}

void		write_events_links(int fd, t_env *env)
{
	size_t	i;
	int		j;

	ft_dprintf(fd, "Links\n");
	i = 0;
	ft_printf("%d global events \n", env->nb_global_events);
	while (i < env->nb_global_events)
	{
		write_event_links(fd, env->global_events[i]);
		i++;
	}
	j = 0;
	while (j < env->nb_sectors)
	{
		write_sector_links(fd, env->sectors[i]);
		j++;
	}
}
