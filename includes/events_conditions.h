/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_conditions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:43:03 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/10 13:54:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_CONDITIONS_H
# define EVENTS_CONDITIONS_H
# include "env.h"

int		equals_condition(t_condition condition);
int		less_condition(t_condition condition);
int		greater_condition(t_condition condition);
int		less_or_equals_condition(t_condition condition);
int		greater_or_equals_condition(t_condition condition);
int		event_ended_condition(t_event event);

#endif
