/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sector2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:01:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:01:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_wall_sprites2(t_wall_sprites *wall)
{
	if (wall->sprite)
		ft_memdel((void**)&wall->sprite);
	if (wall->pos)
		ft_memdel((void**)&wall->pos);
	if (wall->scale)
		ft_memdel((void**)&wall->scale);
	if (wall->nb_press_events)
		ft_memdel((void**)&wall->nb_press_events);
	if (wall->nb_shoot_events)
		ft_memdel((void**)&wall->nb_shoot_events);
	if (wall->press_events)
		ft_memdel((void**)&wall->press_events);
	if (wall->shoot_events)
		ft_memdel((void**)&wall->shoot_events);
}

void		free_wall_sprites(t_wall_sprites *wall)
{
	int		i;

	i = 0;
	while (i < wall->nb_sprites)
	{
		if (wall->nb_shoot_events && wall->nb_shoot_events[i] > 0
			&& wall->shoot_events && wall->shoot_events[i])
			free_events(wall->shoot_events[i], wall->nb_shoot_events[i]);
		if (wall->nb_press_events && wall->nb_press_events[i] > 0
			&& wall->press_events && wall->press_events[i])
			free_events(wall->press_events[i], wall->nb_press_events[i]);
		i++;
	}
	free_wall_sprites2(wall);
}
