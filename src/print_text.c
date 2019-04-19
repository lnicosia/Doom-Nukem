/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:00:36 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/19 14:17:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
**	Create a struct formated to use print_text
**	DONT FORGET TO FREE *text if needed
*/

t_printable_text	new_printable_text(char *text, char *font, unsigned int color, int size)
{
	t_printable_text	new;
	SDL_Color			sdl_color;

	new.str = text;
	new.font = font;
	new.size = size;
	sdl_color.r = color >> 24;
	sdl_color.g = color >> 16;
	sdl_color.b = color >> 8;
	sdl_color.a = color;
	new.color = sdl_color;
	return (new);
}

void	print_text(t_v2 pos, t_printable_text text, t_env *env)
{
	SDL_Surface	*texte;
	SDL_Rect	rect;

	if (env->sdl.font)
		TTF_CloseFont(env->sdl.font);
	env->sdl.font = TTF_OpenFont(text.font, text.size);
	texte = TTF_RenderText_Solid(env->sdl.font, text.str, text.color);
	rect.x = pos.y;
	rect.y = pos.x;
	SDL_BlitSurface(texte, NULL, env->sdl.surface, &rect);
	SDL_FreeSurface(texte);
}
