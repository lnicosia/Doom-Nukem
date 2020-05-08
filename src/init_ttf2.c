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

int		init_ttf5(t_env *env)
{
	if (!(env->init.fonts_names[21] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold30 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 30)))
		env->init.fonts[21] = 1;
	if (!(env->init.fonts_names[22] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold35 = TTF_OpenFont("fonts/Lato-Bold.ttf", 35)))
		env->init.fonts[22] = 1;
	if (!(env->init.fonts_names[23] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold40 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 40)))
		env->init.fonts[23] = 1;
	if (!(env->init.fonts_names[24] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold45 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 45)))
		env->init.fonts[24] = 1;
	if (!(env->init.fonts_names[25] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold50 =
		TTF_OpenFont("fonts/Lato-Bold.ttf", 50)))
		env->init.fonts[25] = 1;
	return (0);
}

int		init_ttf6(t_env *env)
{	
	if (!(env->init.fonts_names[26] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black10 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 10)))
		env->init.fonts[26] = 1;
	if (!(env->init.fonts_names[27] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black15 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 15)))
		env->init.fonts[27] = 1;
	if (!(env->init.fonts_names[28] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black20 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 20)))
		env->init.fonts[28] = 1;
	if (!(env->init.fonts_names[29] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black25 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 25)))
		env->init.fonts[29] = 1;
	return (0);
}

int		init_ttf7(t_env *env)
{		
	if (!(env->init.fonts_names[30] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black30 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 30)))
		env->init.fonts[30] = 1;
	if (!(env->init.fonts_names[31] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black35 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 35)))
		env->init.fonts[31] = 1;
	if (!(env->init.fonts_names[32] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black40 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 40)))
		env->init.fonts[32] = 1;
	if (!(env->init.fonts_names[33] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black45 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 45)))
		env->init.fonts[33] = 1;
	if (!(env->init.fonts_names[34] = ft_strdup("./fonts/Lato-Black.ttf")))
		return (custom_error("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_black50 =
		TTF_OpenFont("fonts/Lato-Black.ttf", 50)))
		env->init.fonts[34] = 1;
	return (0);
}
