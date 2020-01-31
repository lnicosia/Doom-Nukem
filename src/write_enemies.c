/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:01:37 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/30 11:09:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static int	get_main_sprite(int sprite, t_env *env)
{
	int		i;

	i = 0;
	while (i < MAX_OBJECTS)
	{
		if (sprite == env->enemies_main_sprites[i])
			return (i);
		i++;
	}
	return (i);
}

static void	write_enemy(int fd, t_enemies enemy, t_env *env)
{
	ft_dprintf(fd, "[%.f %.f %.f %.f] ",
			enemy.pos.y, enemy.pos.x, enemy.pos.z, enemy.angle);
	ft_dprintf(fd, "[%d %.f] ",
			get_main_sprite(enemy.sprite, env), enemy.scale);
	ft_dprintf(fd, "[%d %d %d]\n",
			enemy.map_hp, enemy.speed, enemy.damage);

}

void		write_enemies(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nE %d\n", env->nb_enemies);
	while (i < env->nb_enemies)
	{
		write_enemy(fd, env->enemies[i], env);
		i++;
	}
	ft_dprintf(fd, "\n");
}
