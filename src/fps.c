/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/17 15:16:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fps(t_env *env)
{
	int			new_time;
	char		*fps;

	new_time = SDL_GetTicks();
	fps = ft_itoa(1000 / (new_time - env->sdl.time));
	/*print_text(new_v2(0, 10), new_printable_text(
				fps,
				"fonts/amazdoom/AmazDoomLeft.ttf",
				0xFFFFFFFF,
				65),
			env);*/
	ft_printf("fps = %s\n", fps);
	ft_strdel(&fps);
	env->sdl.time = new_time;
}
