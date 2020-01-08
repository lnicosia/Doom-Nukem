/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:01:37 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/06 14:42:47 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static void	write_enemy(int fd, t_enemies enemy)
{
	ft_dprintf(fd, "[%.f %.f %.f %.f] ",
			enemy.pos.y, enemy.pos.x, enemy.pos.z, enemy.angle);
	ft_dprintf(fd, "[%d %.f] ",
			enemy.sprite, enemy.scale);
	ft_dprintf(fd, "[%d %d %d]\n",
			enemy.health, enemy.speed, enemy.damage);

}

void		write_enemies(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nE %d\n", env->nb_enemies);
	while (i < env->nb_enemies)
	{
		write_enemy(fd, env->enemies[i]);
		i++;
	}
}
