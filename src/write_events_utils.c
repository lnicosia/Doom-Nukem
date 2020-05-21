/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:36:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:19:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		sector_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d)", event.update_param.sector);
}

void		wall_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d)", event.update_param.sector,
	event.update_param.wall);
}

void		wall_sprite_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d %d)", event.update_param.sector,
	event.update_param.wall, event.update_param.sprite);
}

void		floor_sprite_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d %d)", event.update_param.sector,
	event.update_param.sprite);
}

void		ceiling_sprite_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d %d)", event.update_param.sector,
	event.update_param.sprite);
}
