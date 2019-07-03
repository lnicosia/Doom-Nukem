/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:08:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/13 15:20:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		get_screen_sectors(t_env *env)
{
	int		size;
	t_v2	curr;
	double	tmp;
	int		sect;
	int		sect_count;
	int		x;
	int		i;

	size = ft_min(env->nb_sectors, env->w);
	x = 0;
	sect_count = 0;
	while (x < env->w)
	{
		tmp = 2 * x / (env->camera.x2 - env->camera.x1) / env->camera.scale + env->camera.x1;
		curr.y = -env->camera.near_z;
		curr.x = tmp * -env->player.angle_sin - curr.y * env->player.angle_cos + env->player.pos.x;
		curr.y = tmp * env->player.angle_cos - curr.y * env->player.angle_sin + env->player.pos.y;
		env->screen_pos[x] = curr;
		i = 0;
		sect = get_sector(env, curr);
		while (i < env->screen_sectors_size && env->screen_sectors[i] != -1 && env->screen_sectors[i] != sect)
			i++;
		if (i < env->screen_sectors_size && env->screen_sectors[i] == -1 && sect != -1)
		{
			env->screen_sectors[i] = sect;
			env->xmin[i] = x;
			sect_count++;
		}
		else if (i < env->screen_sectors_size && env->screen_sectors[i] == sect)
			env->xmax[i] = x;
		x++;
	}
	//ft_printf("sect nb = %d\n", sect_count);
	return (sect_count);
}
