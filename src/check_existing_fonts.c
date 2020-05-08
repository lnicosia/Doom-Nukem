/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_fonts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:16:46 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 14:16:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_fonts1(t_env *env)
{
    if (env->init.fonts[0] && !(env->sdl.fonts.amazdoom70 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 70)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[1] && !(env->sdl.fonts.amazdoom50 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 50)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[2] && !(env->sdl.fonts.amazdoom20 =
		TTF_OpenFont("fonts/amazdoom/AmazDoomLeft.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[3] && !(env->sdl.fonts.alice30 =
		TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 30)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return (0);
}

int     check_fonts2(t_env *env)
{
	if (env->init.fonts[4] && !(env->sdl.fonts.alice70 =
		TTF_OpenFont("fonts/alice/Alice-Regular.ttf", 70)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[5] && !(env->sdl.fonts.bebasneue =
		TTF_OpenFont("fonts/bebas_neue/BebasNeue-Regular.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[6] && !(env->sdl.fonts.montserrat20 =
		TTF_OpenFont("fonts/montserrat/Montserrat-Regular.ttf", 20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return (0);
}

int     check_fonts3(t_env *env)
{
	if (env->init.fonts[7] && !(env->sdl.fonts.playfair_display20 =
		TTF_OpenFont("fonts/playfair-display/PlayfairDisplay-Regular.ttf",
		20)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[8] && !(env->sdl.fonts.lato10 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 10)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
	if (env->init.fonts[9] && !(env->sdl.fonts.lato15 =
		TTF_OpenFont("fonts/lato/Lato-Regular.ttf", 15)))
		return (custom_error("TTF_OpenFont error: %s\n", TTF_GetError()));
    return (0);
}

int     check_fonts(t_env *env)
{
    if (check_fonts1(env))
        return (-1);
    if (check_fonts2(env))
        return (-1);
    if (check_fonts3(env))
        return (-1);
    if (check_fonts4(env))
        return (-1);
    if (check_fonts5(env))
        return (-1);
    if (check_fonts6(env))
        return (-1);
    if (check_fonts7(env))
        return (-1);
    if (check_fonts8(env))
        return (-1);
    if (check_fonts9(env))
        return (-1);
    if (check_fonts10(env))
        return (-1);
    if (check_fonts11(env))
        return (-1);
    return (0);
}

int     check_existing_fonts(t_env *env, char *name)
{
    int i;

    i = 0;
    while (i < NB_FONTS)
    {
        if (!(ft_strcmp(name, env->init.fonts_names[i]))
        && env->init.fonts[i] == 1)
            return (1);
        i++;
    }
    return (0);
}
