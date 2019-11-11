/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:54 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/11 16:57:42 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_raygun(t_env *env)
{
    env->init_max = MAX_RAYGUN_SPRITE;
	if (parse_bmp("images/sprites/raygun/raygun1.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun2.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun3.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun4.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun5.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun6.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/raygun/raygun7.bmp", 6, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_shotgun(t_env *env)
{
    env->init_max = MAX_SHOTGUN_SPRITE;
	if (parse_bmp("images/sprites/shotgun/shot1.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
 	if (parse_bmp("images/sprites/shotgun/shot2.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot3.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot4.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot5.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot6.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot7.bmp", 6, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot8.bmp", 7, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot9.bmp", 8, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot10.bmp", 9, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot11.bmp", 10, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot12.bmp", 11, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot13.bmp", 12, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot14.bmp", 13, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/sprites/shotgun/shot15.bmp", 14, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_weapons_sprites(t_env *env)
{
	if (init_shotgun(env))
		return (ft_printf("Failed to load shotgun textures\n"));
	if (init_raygun(env))
		return (ft_printf("Failed to load raygun textures\n"));
}