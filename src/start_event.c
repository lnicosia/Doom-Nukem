/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/08 20:26:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	start_event(t_sector *sector, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < sector->nb_walk_events)
	{
		update_event(&sector->walk_on_me_event[i]);
		ft_lstpushback(&env->events,
			ft_lstnew(&sector->walk_on_me_event[i],
			sizeof(t_event)));
		i++;

	}
}
