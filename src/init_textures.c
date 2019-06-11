/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/11 14:18:10 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_textures(t_env *env)
{
	if (parse_bmp("images/wall0.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall1.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall2.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall3.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/floor0.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/floor1.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot1.bmp", 6, env))
		return (ft_printf("Invalid bmp file\n"));
 	if (parse_bmp("images/shotgun/shot2.bmp", 7, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot3.bmp", 8, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot4.bmp", 9, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot5.bmp", 10, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot6.bmp", 11, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot7.bmp", 12, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot8.bmp", 13, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot9.bmp", 14, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot10.bmp", 15, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot11.bmp", 16, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot12.bmp", 17, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot13.bmp", 18, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot14.bmp", 19, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot15.bmp", 20, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}
