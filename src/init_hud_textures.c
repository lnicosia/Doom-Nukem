/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:09:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/16 15:11:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_hud_textures(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[0] = ft_strdup("images/HUD/shot1.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot1.bmp", start + 0, env))
		env->init.hud[0] = 1;
	if (!(env->init.hud_names[1] = ft_strdup("images/HUD/shot2.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
 	if (parse_bmp("images/HUD/shot2.bmp", start + 1, env))
		env->init.hud[1] = 1;
	if (!(env->init.hud_names[2] = ft_strdup("images/HUD/shot3.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot3.bmp", start + 2, env))
		env->init.hud[2] = 1;
	if (!(env->init.hud_names[3] = ft_strdup("images/HUD/shot4.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot4.bmp", start + 3, env))
		env->init.hud[3] = 1;
	return (0);
}

int		init_hud_textures1(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[4] = ft_strdup("images/HUD/shot5.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot5.bmp", start + 4, env))
		env->init.hud[4] = 1;
	if (!(env->init.hud_names[5] = ft_strdup("images/HUD/shot6.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot6.bmp", start + 5, env))
		env->init.hud[5] = 1;
	if (!(env->init.hud_names[6] = ft_strdup("images/HUD/shot7.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot7.bmp", start + 6, env))
		env->init.hud[6] = 1;
	if (!(env->init.hud_names[7] = ft_strdup("images/HUD/shot8.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot8.bmp", start + 7, env))
		env->init.hud[7] = 1;
	return (0);
}

int		init_hud_textures2(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[8] = ft_strdup("images/HUD/shot9.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot9.bmp", start + 8, env))
		env->init.hud[8] = 1;
	if (!(env->init.hud_names[9] = ft_strdup("images/HUD/shot10.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot10.bmp", start + 9, env))
		env->init.hud[9] = 1;
	if (!(env->init.hud_names[10] = ft_strdup("images/HUD/shot11.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot11.bmp", start + 10, env))
		env->init.hud[10] = 1;
	if (!(env->init.hud_names[11] = ft_strdup("images/HUD/shot12.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot12.bmp", start + 11, env))
		env->init.hud[11] = 1;
	return (0);
}

int		init_hud_textures3(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[12] = ft_strdup("images/HUD/shot13.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot13.bmp", start + 12, env))
		env->init.hud[12] = 1;
	if (!(env->init.hud_names[13] = ft_strdup("images/HUD/shot14.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot14.bmp", start + 13, env))
		env->init.hud[13] = 1;
	if (!(env->init.hud_names[14] = ft_strdup("images/HUD/shot15.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/shot15.bmp", start + 14, env))
		env->init.hud[14] = 1;
	return (0);
}

int		init_hud_textures4(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[15] = ft_strdup("images/HUD/raygun1.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun1.bmp", start + 15, env))
		env->init.hud[15] = 1;
	if (!(env->init.hud_names[16] = ft_strdup("images/HUD/raygun2.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun2.bmp", start + 16, env))
		env->init.hud[16] = 1;
	if (!(env->init.hud_names[17] = ft_strdup("images/HUD/raygun3.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun3.bmp", start + 17, env))
		env->init.hud[17] = 1;
	if (!(env->init.hud_names[18] = ft_strdup("images/HUD/raygun4.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun4.bmp", start + 18, env))
		env->init.hud[18] = 1;
	return (0);
}