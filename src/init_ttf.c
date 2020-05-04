/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ttf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/10 17:29:20 by sipatry          ###   ########.fr       */
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
		return (custom_error("SDL_Init Error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.amazdoom70 =
		TTF_OpenFont("fonts/AmazDooMLeft.ttf", 70)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.amazdoom50 =
		TTF_OpenFont("fonts/AmazDooMLeft.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.amazdoom20 =
		TTF_OpenFont("fonts/AmazDooMLeft.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.alice30 =
		TTF_OpenFont("fonts/Alice-Regular.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.alice70 =
		TTF_OpenFont("fonts/Alice-Regular.ttf", 70)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.bebasneue =
		TTF_OpenFont("fonts/BebasNeue-Regular.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.montserrat20 =
		TTF_OpenFont("fonts/Montserrat-Regular.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.playfair_display20 =
		TTF_OpenFont("fonts/PlayfairDisplay-Regular.ttf",
		20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato10 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato15 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato20 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato25 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato30 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato35 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato40 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato45 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato50 =
		TTF_OpenFont("fonts/Lato-Regular.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold10 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold15 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold20 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold25 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold30 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold35 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold40 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold45 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold50 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black10 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black15 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black20 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black25 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black30 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black35 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black40 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black45 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black50 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (0);
}
