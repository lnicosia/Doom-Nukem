/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:57:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 17:59:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_target_panel_buttons(t_env *env)
{
	env->editor.event_panel.target_panel.sector = new_rectangle_button(
	ON_RELEASE, NULL, NULL, env);
}
