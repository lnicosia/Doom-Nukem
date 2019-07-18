/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/16 10:56:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fps(t_env *env)
{
	int			new_time;

	new_time = SDL_GetTicks();
	env->fps = ft_sitoa(1000 / (new_time - env->sdl.time));
	if (env->options.show_fps)
	{
		print_text(new_point(0, 10), new_printable_text(
					env->fps,
					env->sdl.fonts.amazdoom50,
					0xFFFFFFFF,
					65),
				env);
	}
	env->sdl.time = new_time;
}
