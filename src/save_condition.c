/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:25:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 11:27:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		save_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_condition = 0;
	env->editor.event_panel.ok.release_action = save_event;
	return (0);
}
