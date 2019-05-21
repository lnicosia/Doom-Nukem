/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/19 19:07:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** TODO Protection
*/

int		init_ttf(t_env *env)
{
	ft_printf("Initializing fonts..\n");
	if (TTF_Init() == -1)
		return(ft_printf("SDL_Init Error: %s\n", SDL_GetError()));
	//env->sdl.font = TTF_OpenFont("fonts/heartwrecked.ttf", 65);
	env->sdl.fonts.amazdoom50 = TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 50);
	env->sdl.fonts.amazdoom20 = TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 20);
	env->sdl.fonts.alice = TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 30);
	env->sdl.fonts.bebasneue = TTF_OpenFont("fonts/bebas_neue/BebasNeue-Regular.ttf", 20);
	return (0);
}
