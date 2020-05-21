/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ttf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:51:22 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 13:51:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		init_ttf10(t_env *env)
{
	if (!(env->sdl.fonts.lato_black50 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (0);
}

int		init_ttf9(t_env *env)
{
	if (!(env->sdl.fonts.lato_black30 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black35 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black40 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black45 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (init_ttf10(env));
}

int		init_ttf8(t_env *env)
{
	if (!(env->sdl.fonts.lato_black10 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black15 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black20 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_black25 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (init_ttf9(env));
}

int		init_ttf7(t_env *env)
{
	if (!(env->sdl.fonts.lato_bold35 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold40 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold45 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold50 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (init_ttf8(env));
}

int		init_ttf6(t_env *env)
{
	if (!(env->sdl.fonts.lato_bold15 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold20 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold25 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (!(env->sdl.fonts.lato_bold30 =
		TTF_OpenFont("fonts/lato/Lato-Bold.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	return (init_ttf7(env));
}
