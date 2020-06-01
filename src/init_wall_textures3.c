/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:56:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/15 20:03:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_wall_textures11(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/woodvert.bmp", 120, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/zdoorb1.bmp", 121, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/zdoorf1.bmp", 122, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/zzwolf11.bmp", 123, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/zzwolf12.bmp", 124, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/zzwolf13.bmp", 125, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/magma_rock.bmp", 126, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/rock5.bmp", 127, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}
