/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:00:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/08 18:29:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Create a struct formated to use print_text
**	DONT FORGET TO FREE *text if needed
*/

t_printable_text	new_printable_text(char *text, TTF_Font *font,
unsigned int color, int size)
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

int					print_text(t_point pos, t_printable_text text, t_env *env)
{
	SDL_Surface	*surface;

	if (!text.font)
		return (custom_error("Font not initialized\n"));
	if (!(surface = TTF_RenderText_Blended(text.font, text.str, text.color)))
		return (custom_error("TTF_RenderText_Solid error: %s\n",
		TTF_GetError()));
	apply_surface(surface, pos, new_point(surface->w, surface->h), env);
	SDL_FreeSurface(surface);
	return (0);
}
