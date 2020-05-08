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

int		init_ttf(t_env *env)
{
	ft_printf("Initializing fonts..\n");
	if (TTF_Init() == -1)
		return (custom_error("SDL_Init Error: %s\n", TTF_GetError()));
	if (init_ttf1(env))
		return (-1);
	if (init_ttf2(env))
		return (-1);
	if (init_ttf3(env))
		return (-1);
	if (init_ttf4(env))
		return (-1);
	if (init_ttf5(env))
		return (-1);
	if (init_ttf6(env))
		return (-1);
	if (init_ttf7(env))
		return (-1);
	return (0);
}

int	init_ttf1(t_env *env)
{
	if (!(env->init.fonts_names[0] = ft_strdup("./fonts/AmazDoomLeft.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.amazdoom70 =
		TTF_OpenFont("fonts/AmazDoomLeft.ttf", 70)))
		env->init.fonts[0] = 1;
	if (!(env->init.fonts_names[1] = ft_strdup("./fonts/AmazDoomLeft.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.amazdoom50 =
		TTF_OpenFont("fonts/AmazDoomLeft.ttf", 50)))
		env->init.fonts[1] = 1;
		if (!(env->init.fonts_names[2] = ft_strdup("./fonts/AmazDoomLeft.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.amazdoom20 =
		TTF_OpenFont("fonts/AmazDoomLeft.ttf", 20)))
		env->init.fonts[2] = 1;
	if (!(env->init.fonts_names[3] = ft_strdup("./fonts/Alice-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.alice30 =
		TTF_OpenFont("fonts/Alice-Regular.ttf", 30)))
		env->init.fonts[3] = 1;
		if (!(env->init.fonts_names[4] = ft_strdup("./fonts/Alice-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.alice70 = TTF_OpenFont("fonts/Alice-Regular.ttf", 70)))
		env->init.fonts[4] = 1;
	return (0);
}

int		init_ttf2(t_env *env)
{
	if (!(env->init.fonts_names[5] = ft_strdup("./fonts/BebasNeue-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.bebasneue =
		TTF_OpenFont("fonts/BebasNeue-Regular.ttf", 20)))
		env->init.fonts[5] = 1;
	if (!(env->init.fonts_names[6] = ft_strdup("./fonts/Montserrat-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.montserrat20 =
		TTF_OpenFont("fonts/Montserrat-Regular.ttf", 20)))
		env->init.fonts[6] = 1;
	if (!(env->init.fonts_names[7] =
		ft_strdup("./fonts/PlayfairDisplay-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.playfair_display20 =
		TTF_OpenFont("fonts/PlayfairDisplay-Regular.ttf", 20)))
		env->init.fonts[7] = 1;
	if (!(env->init.fonts_names[8] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato10 = TTF_OpenFont("fonts/Lato-Regular.ttf", 10)))
		env->init.fonts[8] = 1;
	if (!(env->init.fonts_names[9] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato15 = TTF_OpenFont("fonts/Lato-Regular.ttf", 15)))
		env->init.fonts[9] = 1;
	return(0);
}

int		init_ttf3(t_env *env)
{
	if (!(env->init.fonts_names[10] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato20 = TTF_OpenFont("fonts/Lato-Regular.ttf", 20)))
		env->init.fonts[10] = 1;
	if (!(env->init.fonts_names[11] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato25 = TTF_OpenFont("fonts/Lato-Regular.ttf", 25)))
		env->init.fonts[11] = 1;
	if (!(env->init.fonts_names[12] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato30 = TTF_OpenFont("fonts/Lato-Regular.ttf", 30)))
		env->init.fonts[12] = 1;
	if (!(env->init.fonts_names[13] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato35 = TTF_OpenFont("fonts/Lato-Regular.ttf", 35)))
		env->init.fonts[13] = 1;
	if (!(env->init.fonts_names[14] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato40 = TTF_OpenFont("fonts/Lato-Regular.ttf", 40)))
		env->init.fonts[14] = 1;
	if (!(env->init.fonts_names[15] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato45 = TTF_OpenFont("fonts/Lato-Regular.ttf", 45)))
		env->init.fonts[15] = 1;
	return (0);
}

int		init_ttf4(t_env *env)
{
	if (!(env->init.fonts_names[16] = ft_strdup("./fonts/Lato-Regular.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato50 = TTF_OpenFont("fonts/Lato-Regular.ttf", 50)))
		env->init.fonts[16] = 1;
	if (!(env->init.fonts_names[17] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold10 = TTF_OpenFont("fonts/Lato-Bold.ttf", 10)))
		env->init.fonts[17] = 1;
	if (!(env->init.fonts_names[18] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold15 = TTF_OpenFont("fonts/Lato-Bold.ttf", 15)))
		env->init.fonts[18] = 1;
	if (!(env->init.fonts_names[19] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold20 = TTF_OpenFont("fonts/Lato-Bold.ttf", 20)))
		env->init.fonts[19] = 1;
	if (!(env->init.fonts_names[20] = ft_strdup("./fonts/Lato-Bold.ttf")))
		return (ft_perror("Error while initializing a font\n"));
	if (!(env->sdl.fonts.lato_bold25 = TTF_OpenFont("fonts/Lato-Bold.ttf", 25)))
		env->init.fonts[20] = 1;
	return (0);
}

