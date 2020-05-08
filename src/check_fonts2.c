/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonts2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:00:44 by marvin            #+#    #+#             */
/*   Updated: 2020/04/28 15:00:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_fonts9(t_env *env)
{
    if (env->init.fonts[26] && !(env->sdl.fonts.lato_black10 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[27] && !(env->sdl.fonts.lato_black15 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[28] && !(env->sdl.fonts.lato_black20 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[29] && !(env->sdl.fonts.lato_black25 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 25)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return(0);
}

int     check_fonts10(t_env *env)
{
    if (env->init.fonts[30] && !(env->sdl.fonts.lato_black30 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[31] && !(env->sdl.fonts.lato_black35 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 35)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[32] && !(env->sdl.fonts.lato_black40 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 40)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[33] && !(env->sdl.fonts.lato_black45 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 45)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return (0);
}

int     check_fonts11(t_env *env)
{
    if (env->init.fonts[34] && !(env->sdl.fonts.lato_black50 =
		TTF_OpenFont("fonts/lato/Lato-Black.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return (0);
}
