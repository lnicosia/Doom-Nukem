/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_event_conditions_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:36:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:54:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		condition_sector_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d)", condition.sector);
}

void		condition_wall_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d %d)", condition.sector,
	condition.wall);
}

void		condition_wall_sprite_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d %d %d)", condition.sector,
	condition.wall, condition.sprite);
}

void		condition_floor_sprite_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d %d %d)", condition.sector,
	condition.sprite);
}

void		condition_ceiling_sprite_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d %d %d)", condition.sector,
	condition.sprite);
}
