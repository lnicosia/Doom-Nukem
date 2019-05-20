/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/20 11:57:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fps(t_env *env)
{
	int			new_time;
	char		*fps;

	new_time = SDL_GetTicks();
	fps = ft_sitoa(1000 / (new_time - env->sdl.time));
	print_text(new_v2(0, 10), new_printable_text(
				fps,
				env->sdl.fonts.amazdoom50,
				0xFFFFFFFF,
				65),
			env);
	ft_printf("fps = %d\n", 1000 / (new_time - env->sdl.time));
	env->sdl.time = new_time;
}
