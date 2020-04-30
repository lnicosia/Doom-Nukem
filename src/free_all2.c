/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:00:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:00:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		free_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (env->sprite_textures[i].surface)
			SDL_FreeSurface(env->sprite_textures[i].surface);
		i++;
	}
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

void		free_events(t_event *events, size_t size)
{
	size_t	j;

	j = 0;
	while (j < size)
	{
		free_event(&events[j]);
		j++;
	}
	if (events)
		ft_memdel((void**)&events);
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
