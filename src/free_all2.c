/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:00:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 15:32:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_textures(t_env *env)
{
	free_sprite_textures(env);
	free_wall_textures(env);
	free_ui_textures(env);
	free_mini_skyboxes_textures(env);
	free_skyboxes(env);
}

void		free_event(t_event *event)
{
	if (event->exec_param)
		ft_memdel((void**)&event->exec_param);
	if (event->launch_conditions)
		ft_memdel((void**)&event->launch_conditions);
	if (event->exec_conditions)
		ft_memdel((void**)&event->exec_conditions);
}

void		free_events(t_event **events, size_t *size)
{
	size_t	j;

	j = 0;
	while (j < *size)
	{
		free_event(&(*events)[j]);
		j++;
	}
	if (events)
		ft_memdel((void**)events);
	*size = 0;
}

void		free_sectors(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		free_sector(&env->sectors[i]);
		i++;
	}
	ft_memdel((void**)&env->sectors);
}
