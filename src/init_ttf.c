/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/17 17:02:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_ttf(t_env *env)
{
	if (TTF_Init() == -1)
		return(ft_printf("SDL_Init Error: %s\n", SDL_GetError()));
	env->sdl.font = TTF_OpenFont("fonts/heartwrecked.ttf", 65);
	return (0);
}
