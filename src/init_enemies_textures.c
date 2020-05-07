/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:10:52 by marvin            #+#    #+#             */
/*   Updated: 2020/03/26 16:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int    init_enemies_sprites_textures(t_env *env)
{
    int	start;

	start = env->enemies_start;
	if (!(env->init.enemy_names[0] =
	ft_strdup("images/sprites/cyber_demon.bmp")))
		return (ft_printf("Error while parsing enemy sprite texture\n"));
	if (parse_bmp("images/sprites/cyber_demon.bmp", start + 0, env))
		env->init.enemies[0] = 1;
	if (!(env->init.enemy_names[1] =
	ft_strdup("images/sprites/lost_soul.bmp")))
		return (ft_printf("Error while parsing enemy sprite texture\n"));
	if (parse_bmp("images/sprites/lost_soul.bmp", start + 1, env))
		env->init.enemies[1] = 1;
	return (0);
}