/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/23 16:09:37 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static void	write_sector_textures(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		if (sector.textures[i] == 38)
			ft_dprintf(fd, "%d", -1);
		else
			ft_dprintf(fd, "%d", sector.textures[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_neighbors(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.neighbors[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_vertices(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.vertices[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_wall_sprites(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		ft_dprintf(fd, "[%d %f %f %f %f]",
			sector.sprites[i].sprite,
			sector.sprites[i].pos.x,
			sector.sprites[i].pos.y,
			sector.sprites[i].scale.x,
			sector.sprites[i].scale.y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector(int fd, t_sector sector)
{
	ft_dprintf(fd, "[%.5f %.5f %d] ",
			sector.floor, sector.floor_slope, sector.floor_texture);
	if (sector.ceiling_texture == 38)
	{
		ft_dprintf(fd, "[%.5f %.5f %d] ",
				sector.ceiling, sector.ceiling_slope, -1);
	}
	else
	{
		ft_dprintf(fd, "[%.5f %.5f %d] ",
				sector.ceiling, sector.ceiling_slope, sector.ceiling_texture);
	}
			write_sector_vertices(fd, sector);
		write_sector_neighbors(fd, sector);
		write_sector_textures(fd, sector);
		write_sector_wall_sprites(fd, sector);
		ft_dprintf(fd, "%d ", (int)(sector.brightness));
		ft_dprintf(fd, "%d\n", (int)(sector.statue));
}

void		write_sectors(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nS %d\n", env->nb_sectors);
	while (i < env->nb_sectors)
	{
		write_sector(fd, env->sectors[i]);
		i++;
	}
}
