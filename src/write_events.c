/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:15:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 11:33:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "save.h"

void	write_wall_sprites_events(int fd, t_sector sector,
		void (*writers[])(int, t_event))
{
	int		i;

	i = 0;
	while (i < sector.nb_vertices)
	{
	  	write_current_wall_sprites_events(fd, sector, writers, i);
		i++;
	}
}

void	write_enemy_events(int fd, t_env *env,
void (*writers[])(int, t_event), int i)
{
	size_t	j;

	if (env->enemies[i].nb_death_events > 0
		&& env->enemies[i].death_events)
	{
		j = 0;
		while (j < env->enemies[i].nb_death_events)
		{
			ft_dprintf(fd, "[6 (%d)][%d", i,
			env->enemies[i].death_events[j].target_index);
			write_event(fd, env->enemies[i].death_events[j], writers);
			j++;
		}
	}
	if (env->enemies[i].nb_collision_events > 0
		&& env->enemies[i].collision_events)
	{
		j = 0;
		while (j < env->enemies[i].nb_collision_events)
		{
			ft_dprintf(fd, "[7 (%d)][%d", i,
			env->enemies[i].collision_events[j].target_index);
			write_event(fd, env->enemies[i].collision_events[j], writers);
			j++;
		}
	}
}

void	write_enemies_events(int fd, t_env *env,
void (*writers[])(int, t_event))
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
	  	write_enemy_events(fd, env, writers, i);
		i++;
	}
}

void	write_objects_events(int fd, t_env *env,
void (*writers[])(int, t_event))
{
	int		i;
	size_t	j;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].nb_collision_events > 0
			&& env->objects[i].collision_events)
		{
			j = 0;
			while (j < env->objects[i].nb_collision_events)
			{
				ft_dprintf(fd, "[8 (%d)][%d", i,
				env->objects[i].collision_events[j].target_index);
				write_event(fd, env->objects[i].collision_events[j], writers);
				j++;
			}
		}
		i++;
	}
}

void	write_events(int fd, t_env *env)
{
	void	(*writers[MAX_TARGET_TYPES + 1])(int, t_event);
	size_t	i;
	int		j;

	init_events_writers(writers);
	i = 0;
	while (i < env->nb_global_events)
	{
		ft_dprintf(fd, "[0][%d", env->global_events[i].target_index);
		write_event(fd, env->global_events[i], writers);
		i++;
	}
	j = 0;
	while (j < env->nb_sectors)
	{
		write_sector_events(fd, j, env->sectors[j], writers);
		write_wall_sprites_events(fd, env->sectors[j],
		writers);
		j++;
	}
	i = 0;
	write_enemies_events(fd, env, writers);
	write_objects_events(fd, env, writers);
}
