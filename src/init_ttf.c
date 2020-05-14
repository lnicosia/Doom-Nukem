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

#include "init.h"

/*
** TODO Protection
*/

int		init_ttf5(t_env *env)
{
	if (!(env->sdl.fonts.lato40 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 40)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato45 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 45)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato50 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 50)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato_bold10 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 10)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	return (init_ttf6(env));
}
int		init_ttf4(t_env *env)
{
	if (!(env->sdl.fonts.lato20 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato25 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 25)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato30 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 30)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato35 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 35)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	return (init_ttf5(env));
}

int		init_ttf3(t_env *env)
{
	if (!(env->sdl.fonts.playfair_display20 =
		TTF_OpenFont("fonts/playfair-display/PlayfairDisplay-Regular.ttf",
		20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato10 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 10)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.lato15 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 15)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	return (init_ttf4(env));
}

int		init_ttf2(t_env *env)
{
	if (!(env->sdl.fonts.alice30 =
		TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 30)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.alice70 =
		TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 70)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.bebasneue =
		TTF_OpenFont("fonts/bebas_neue/BebasNeue-Regular.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.montserrat20 =
		TTF_OpenFont("fonts/montserrat/Montserrat-Regular.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	return (init_ttf3(env));
}

int		init_ttf(t_env *env)
{
	ft_printf("Initializing fonts..\n");
	if (TTF_Init() == -1)
		return (custom_error("SDL_Init Error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.amazdoom70 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 70)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.amazdoom50 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 50)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (!(env->sdl.fonts.amazdoom20 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	return (init_ttf2(env));
}