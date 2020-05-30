/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_event_conditions_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:36:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:52:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		condition_vertex_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d)", condition.vertex);
}

void		condition_weapon_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d)", condition.weapon);
}

void		condition_enemy_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d)", condition.enemy);
}

void		condition_object_writer(int fd, t_condition condition)
{
	ft_dprintf(fd, " (%d)", condition.object);
}

void		condition_no_writer(int fd, t_condition condition)
{
	(void)fd;
	(void)condition;
}
