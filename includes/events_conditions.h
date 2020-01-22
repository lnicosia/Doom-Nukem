/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_conditions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:43:03 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 14:49:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_CONDITIONS_H
# define EVENTS_CONDITIONS_H
# include "env.h"
# define MAX_CONDITION_TYPES 9

typedef enum		e_condition_type
{
	EQUALS,
	DIFFERENT,
	LESS,
	GREATER,
	LESS_OR_EQUALS,
	GREATER_OR_EQUALS,
	EVENT_ENDED,
	EVENT_ENDED_START,
	FUNCTION
}					t_condition_type;

int		equals_condition(t_condition condition);
int		different_condition(t_condition condition);
int		less_condition(t_condition condition);
int		greater_condition(t_condition condition);
int		less_or_equals_condition(t_condition condition);
int		greater_or_equals_condition(t_condition condition);
int		event_ended_condition(t_condition condition, t_event event);
int		event_ended_start_condition(t_condition condition, t_event event);

#endif
