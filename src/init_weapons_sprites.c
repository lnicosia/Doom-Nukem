/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:54 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/12 17:55:07 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_shotgun(t_env *env)
{
	if (parse_bmp("images/HUD/shotgun/shot1.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
 	if (parse_bmp("images/HUD/shotgun/shot2.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot3.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot4.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot5.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot6.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot7.bmp", 6, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot8.bmp", 7, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot9.bmp", 8, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot10.bmp", 9, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot11.bmp", 10, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot12.bmp", 11, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot13.bmp", 12, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot14.bmp", 13, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shotgun/shot15.bmp", 14, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_raygun(t_env *env)
{
	if (parse_bmp("images/HUD/raygun/raygun1.bmp", 15, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun2.bmp", 16, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun3.bmp", 17, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun4.bmp", 18, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun5.bmp", 19, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun6.bmp", 20, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun/raygun7.bmp", 21, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_gun(t_env *env)
{
	if (parse_bmp("images/HUD/gun/gun_1.bmp", 40, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun/gun_2.bmp", 41, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun/gun_3.bmp", 42, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun/gun_4.bmp", 43, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun/gun_5.bmp", 44, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun/gun_6.bmp", 45, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}