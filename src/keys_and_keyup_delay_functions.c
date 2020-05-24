/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_keyup_delay_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:14:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 16:57:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		key_delay(t_env *env, double start)
{
	double	tick;

	tick = SDL_GetTicks();
	if (env->editor.key_delay > 200)
		return (-1);
	return (0);
}
