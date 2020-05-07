/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 14:56:02 by marvin            #+#    #+#             */
/*   Updated: 2020/04/28 14:56:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_fonts4(t_env *env)
{
	if (env->init.fonts[10] && !(env->sdl.fonts.lato20 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[11] && !(env->sdl.fonts.lato25 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 25)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[12] && !(env->sdl.fonts.lato30 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 30)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
    return (0);
}

int     check_fonts5(t_env *env)
{
	if (env->init.fonts[13] && !(env->sdl.fonts.lato35 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 35)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[14] && !(env->sdl.fonts.lato40 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 40)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[15] && !(env->sdl.fonts.lato45 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 45)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
    return (0);
}

int     check_fonts6(t_env *env)
{
	if (env->init.fonts[16] && !(env->sdl.fonts.lato50 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 50)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[17] && !(env->sdl.fonts.lato_bold10 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 10)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[18] && !(env->sdl.fonts.lato_bold15 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 15)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
    return (0);
}

int     check_fonts7(t_env *env)
{
    if (env->init.fonts[19] && !(env->sdl.fonts.lato_bold20 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 20)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[20] && !(env->sdl.fonts.lato_bold25 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 25)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[21] && !(env->sdl.fonts.lato_bold30 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 30)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
    return (0);
}

int     check_fonts8(t_env *env)
{
    if (env->init.fonts[22] && !(env->sdl.fonts.lato_bold35 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 35)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[23] && !(env->sdl.fonts.lato_bold40 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 40)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[24] && !(env->sdl.fonts.lato_bold45 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 45)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
	if (env->init.fonts[25] && !(env->sdl.fonts.lato_bold50 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 50)))
	{
		ft_printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return (-1);
	}
    return (0);
}