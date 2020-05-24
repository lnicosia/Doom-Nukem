/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:15:15 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 16:33:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pop_events.h"
#include "events.h"
#include "free.h"

int		func_event(t_event *curr, t_env *env)
{
	if (curr->exec_func)
		return (curr->exec_func(curr->exec_param, env));
	return (1);
}
