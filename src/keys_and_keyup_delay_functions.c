/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_keyup_delay_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:14:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/14 11:31:34 by sipatry          ###   ########.fr       */
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