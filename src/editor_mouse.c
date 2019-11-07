/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:31:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/07 10:50:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_mouse(t_env *env)
{
	(void)env;
	if (env->test_button.draw)
		button_event(&env->test_button, env);
	return (0);
}
