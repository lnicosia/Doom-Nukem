/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:56:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/12 17:43:57 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_wall_textures(t_env *env)
{
	if (!(env->init.text_name[0] = ft_strdup("./images/textures/wall0.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/wall0.bmp", 0, env))
		env->init.textures[0] = 1;
	if (!(env->init.text_name[1] = ft_strdup("./images/textures/wall1.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/wall1.bmp", 1, env))
		env->init.textures[1] = 1;
	if (!(env->init.text_name[2] = ft_strdup("./images/textures/wall2.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/wall2.bmp", 2, env))
		env->init.textures[2] = 1;
	if (!(env->init.text_name[3] = ft_strdup("./images/textures/wall3.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/wall3.bmp", 3, env))
		env->init.textures[3] = 1;
	if (!(env->init.text_name[4] = ft_strdup("./images/textures/floor0.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/floor0.bmp", 4, env))
		env->init.textures[4] = 1;
	return (0);
}

int		init_wall_textures1(t_env *env)
{
	if (!(env->init.text_name[5] = ft_strdup("./images/textures/floor1.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/floor1.bmp", 5, env))
		env->init.textures[5] = 1;
	if (!(env->init.text_name[6] = ft_strdup("./images/textures/rust.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/rust.bmp", 6, env))
		env->init.textures[6] = 1;
	if (!(env->init.text_name[7] = ft_strdup("./images/textures/black_tiles.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/black_tiles.bmp", 7, env))
		env->init.textures[7] = 1;
	if (!(env->init.text_name[8] = ft_strdup("./images/textures/rock.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/rock.bmp", 8, env))
		env->init.textures[8] = 1;
	if (!(env->init.text_name[9] = ft_strdup("./images/textures/grass1.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/grass1.bmp", 9, env))
	{
		ft_printf("Copuld not parse grass1.bmp\n");
		env->init.textures[9] = 1;
	}
	return (0);
}

int		init_wall_textures2(t_env *env)
{
	if (!(env->init.text_name[10] = ft_strdup("./images/textures/grass2.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/grass2.bmp", 10, env))
		env->init.textures[10] = 1;
	if (!(env->init.text_name[11] = ft_strdup("./images/textures/grass3.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/grass3.bmp", 11, env))
		env->init.textures[11] = 1;
	if (!(env->init.text_name[12] = ft_strdup("./images/textures/tiles.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/tiles.bmp", 12, env))
		env->init.textures[12] = 1;
	if (!(env->init.text_name[13] = ft_strdup("./images/textures/sand.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/sand.bmp", 13, env))
		env->init.textures[13] = 1;
	if (!(env->init.text_name[14] = ft_strdup("./images/textures/grey.bmp")))
		return (ft_printf("Error while malloc texture name\n"));
	if (parse_bmp_wall_textures("./images/textures/grey.bmp", 14, env))
		env->init.textures[14] = 1;
	return (0);
}