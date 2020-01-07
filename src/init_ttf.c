/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/06 18:44:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** TODO Protection
*/

int		init_ttf(t_env *env)
{
	ft_printf("Initializing fonts..\n");
	if (TTF_Init() == -1)
		return(ft_printf("SDL_Init Error: %s\n", SDL_GetError()));
	//env->sdl.font = TTF_OpenFont("fonts/heartwrecked.ttf", 65);
	env->sdl.fonts.amazdoom70 = TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 70);
	env->sdl.fonts.amazdoom50 = TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 50);
	env->sdl.fonts.amazdoom20 = TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 20);
	env->sdl.fonts.alice30 = TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 30);
	env->sdl.fonts.alice70 = TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 70);
	env->sdl.fonts.bebasneue = TTF_OpenFont("fonts/bebas_neue/BebasNeue-Regular.ttf", 20);
	env->sdl.fonts.montserrat20 = TTF_OpenFont("fonts/montserrat/Montserrat-Regular.ttf", 20);
	env->sdl.fonts.playfair_display20 = TTF_OpenFont("fonts/playfair-display/PlayfairDisplay-Regular.ttf", 20);
	env->sdl.fonts.lato20 = TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 20);
	return (0);
}
