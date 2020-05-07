/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_skyboxes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:58:23 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 10:58:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

void		init_mini_skyboxes_selection(t_env *env)
{
	if (parse_bmp_mini_skyboxes_textures("images/ui/moonlight.bmp", 0,
		env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/moonlight.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
	if (parse_bmp_mini_skyboxes_textures("images/ui/nebula.bmp", 1,
		env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/nebula.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
	if (parse_bmp_mini_skyboxes_textures("images/ui/beautifull_scenery.bmp",
	2, env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/beautifull_scenery.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
}

void		init_mini_skyboxes_selection2(t_env *env)
{
	if (parse_bmp_mini_skyboxes_textures("images/ui/moonlight_128.bmp",
		3, env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/moonlight_128.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
	if (parse_bmp_mini_skyboxes_textures("images/ui/nebula_128.bmp", 4,
		env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/nebula_128.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
	if (parse_bmp_mini_skyboxes_textures("images/ui/beautifull_scenery_128.bmp",
	5, env))
	{
		env->init.mini_skyboxes_names[0] =
		ft_strdup("images/ui/beautifull_scenery_128.bmp");
		env->init.mini_skyboxes[0] = 1;
	}
}