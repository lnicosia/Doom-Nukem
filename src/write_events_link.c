/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_events_link.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:22:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:22:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

void		write_event_link2(int fd, t_condition condition)
{
	if (condition.target_trigger.type == PRESS
		|| condition.target_type == SHOOT)
		ft_dprintf(fd, "(%d %d %d) ", condition.target_trigger.sector,
		condition.target_trigger.wall, condition.target_trigger.sprite);
	else if (condition.target_trigger.type == STAND
		|| condition.target_type == WALK_IN
		|| condition.target_trigger.type == WALK_OUT)
		ft_dprintf(fd, "(%d) ", condition.target_trigger.sector);
	else if (condition.target_trigger.type == DEATH
		|| condition.target_trigger.type == ENEMY_COLLISION)
		ft_dprintf(fd, "(%d) ", condition.target_trigger.enemy);
	else if (condition.target_trigger.type == OBJECT_COLLISION)
		ft_dprintf(fd, "(%d) ", condition.target_trigger.object);
	ft_dprintf(fd, "%d]", condition.target_trigger.index);
	if (condition.type == EVENT_ENDED)
		ft_dprintf(fd, "[0]\n", condition.type);
	else
		ft_dprintf(fd, "[1]\n", condition.type);
}

void		write_event_link(int fd, t_condition condition)
{
	ft_dprintf(fd, "[%d ", condition.source_trigger.type);
	if (condition.source_trigger.type == PRESS
		|| condition.source_trigger.type == SHOOT)
		ft_dprintf(fd, "(%d %d %d) ", condition.source_trigger.sector,
		condition.source_trigger.wall, condition.source_trigger.sprite);
	else if (condition.source_trigger.type == STAND
		|| condition.source_trigger.type == WALK_IN
		|| condition.source_trigger.type == WALK_OUT)
		ft_dprintf(fd, "(%d) ", condition.source_trigger.sector);
	else if (condition.source_trigger.type == DEATH
		|| condition.source_trigger.type == ENEMY_COLLISION)
		ft_dprintf(fd, "(%d) ", condition.source_trigger.enemy);
	else if (condition.source_trigger.type == OBJECT_COLLISION)
		ft_dprintf(fd, "(%d) ", condition.source_trigger.object);
	ft_dprintf(fd, "%d]", condition.source_trigger.index);
	ft_dprintf(fd, "[%d ", condition.target_trigger.type);
	write_event_link2(fd, condition);
}
