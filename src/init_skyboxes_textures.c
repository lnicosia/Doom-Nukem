/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:18:36 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/12 18:07:14 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		init_skyboxes_textures(t_env *env)
{
	if (!(env->init.skyboxes_names[0] =
	ft_strdup("images/skyboxes/night_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_bottom.bmp",
	0, 0, env))
		env->init.skyboxes[0] = 1;
	if (!(env->init.skyboxes_names[1] =
	ft_strdup("images/skyboxes/night_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_bottom.bmp",
	0, 1, env))
		env->init.skyboxes[1] = 1;
	if (!(env->init.skyboxes_names[2] =
	ft_strdup("images/skyboxes/night_back.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_back.bmp",
	0, 2, env))
		env->init.skyboxes[2] = 1;
	return (0);
}

int		init_skyboxes_textures1(t_env *env)
{
	if (!(env->init.skyboxes_names[3] =
		ft_strdup("images/skyboxes/night_left.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_left.bmp",
	0, 3, env))
		env->init.skyboxes[3] = 1;
	if (!(env->init.skyboxes_names[4] =
		ft_strdup("images/skyboxes/night_front.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_front.bmp",
	0, 4, env))
		env->init.skyboxes[4] = 1;
	if (!(env->init.skyboxes_names[5] =
		ft_strdup("images/skyboxes/night_right.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_right.bmp",
	0, 5, env))
		env->init.skyboxes[5] = 1;
	return (0);
}

int		init_skyboxes_textures2(t_env *env)
{
	if (!(env->init.skyboxes_names[6] =
		ft_strdup("images/skyboxes/nebula_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_bottom.bmp",
	1, 0, env))
		env->init.skyboxes[6] = 1;
	if (!(env->init.skyboxes_names[7] =
		ft_strdup("images/skyboxes/nebula_top.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_top.bmp",
	1, 1, env))
		env->init.skyboxes[7] = 1;
	if (!(env->init.skyboxes_names[8] =
		ft_strdup("images/skyboxes/nebula_back.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_back.bmp",
	1, 2, env))
		env->init.skyboxes[8] = 1;
	return (0);
}

int		init_skyboxes_textures3(t_env *env)
{
	if (!(env->init.skyboxes_names[9] =
		ft_strdup("images/skyboxes/nebula_left.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_left.bmp",
	1, 3, env))
		env->init.skyboxes[9] = 1;
	if (!(env->init.skyboxes_names[10] =
		ft_strdup("images/skyboxes/nebula_front.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_front.bmp",
	1, 4, env))
		env->init.skyboxes[10] = 1;
	if (!(env->init.skyboxes_names[11] =
		ft_strdup("images/skyboxes/nebula_right.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_right.bmp",
	1, 5, env))
		env->init.skyboxes[11] = 1;
		return (0);
}

int		init_skyboxes_textures4(t_env *env)
{
	if (!(env->init.skyboxes_names[12] =
	ft_strdup("images/skyboxes/bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/bottom.bmp",
	2, 0, env))
		env->init.skyboxes[12] = 1;
	if (!(env->init.skyboxes_names[13] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/top.bmp",
	2, 1, env))
		env->init.skyboxes[13] = 1;
	if (!(env->init.skyboxes_names[14] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/back.bmp",
	2, 2, env))
		env->init.skyboxes[14] = 1;
	return (0);
}
