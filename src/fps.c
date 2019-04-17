/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/17 11:12:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fps(t_env *env)
{
	int	new_time;

	new_time = SDL_GetTicks();
	ft_printf("FPS = %d\n", 1000 / (new_time - env->sdl.time));
	env->sdl.time = new_time;
}
