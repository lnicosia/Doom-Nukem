/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:36:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:19:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		vertex_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d)", event.update_param.vertex);
}

void		weapon_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d)", event.update_param.weapon);
}

void		enemy_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d %d)", event.update_param.enemy);
}

void		object_writer(int fd, t_event event)
{
	ft_dprintf(fd, " (%d %d %d)", event.update_param.object);
}
