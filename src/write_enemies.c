/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:01:37 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/18 17:49:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static int	get_main_enemy_sprite(int sprite, t_env *env)
{
	int		i;

	i = 0;
	while (i < MAX_ENEMIES)
	{
		if (sprite == env->enemies_main_sprites[i])
			return (i);
		i++;
	}
	return (i);
}

static void	write_enemy(int fd, t_enemies enemy, t_env *env)
{
	ft_dprintf(fd, "[%.*f %.*f %.*f %.*f] ",
			ft_min(5, get_decimal_len(enemy.pos.y)),
			enemy.pos.y,
			ft_min(5, get_decimal_len(enemy.pos.x)),
			enemy.pos.x,
			ft_min(5, get_decimal_len(enemy.pos.z)),
			enemy.pos.z,
			ft_min(5, get_decimal_len(enemy.angle)),
			enemy.angle);
	ft_dprintf(fd, "[%d %.*f] ",
			get_main_enemy_sprite(enemy.sprite, env),
			ft_min(5, get_decimal_len(enemy.scale)),
			enemy.scale);
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
