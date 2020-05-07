/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_textures2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:26:14 by marvin            #+#    #+#             */
/*   Updated: 2020/05/07 13:26:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		init_skyboxes_textures5(t_env *env)
{
	if (!(env->init.skyboxes_names[15] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_printf("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/left.bmp",
	2, 3, env))
		env->init.skyboxes[15] = 1;
	if (!(env->init.skyboxes_names[16] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_printf("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/front.bmp",
	2, 4, env))
		env->init.skyboxes[16] = 1;
	if (!(env->init.skyboxes_names[17] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_printf("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/right.bmp",
	2, 5, env))
		env->init.skyboxes[17] = 1;
	return (0);
}