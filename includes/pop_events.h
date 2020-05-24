/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:03:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 14:03:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POP_EVENTS_H
# define POP_EVENTS_H
# include "env.h"

typedef struct	s_events_executer
{
	t_list		*tmp;
	t_list		*tmp_values;
	t_list		*prec;
	t_list		*prec_values;
}				t_events_executer;

#endif
