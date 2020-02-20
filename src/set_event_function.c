/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:21:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 15:27:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	*set_event_function(t_env *env, t_events_parser *eparser)
{
	(void)env;
	if (eparser->target_index == WIN)
	{
		eparser->event.exec_func = &win;
		eparser->event.mod_type = FUNC;
	}
	return (0);
}
