/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/18 11:45:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fps(t_env *env)
{
	int			new_time;
	SDL_Color	color;
	SDL_Surface	*texte;
	SDL_Rect	rect;
	char		*fps;

	new_time = SDL_GetTicks();
	color.r = 0xFF;
	color.g = 0xFF;
	color.b = 0xFF;
	color.a = 0xFF;
	fps = ft_itoa(1000 / (new_time - env->sdl.time));
	//ft_printf("FPS = %d\n", 1000 / (new_time - env->sdl.time));
	texte = TTF_RenderText_Solid(env->sdl.font, fps, color);
	rect.x = 10;
	rect.y = 0;
	SDL_BlitSurface(texte, NULL, env->sdl.surface, &rect);
	SDL_FreeSurface(texte);
	free(fps);
	env->sdl.time = new_time;
}
