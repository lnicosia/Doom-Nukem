/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:02 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/08 15:36:06 by gaerhard         ###   ########.fr       */
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
		// Use to save with real scale
		// !!! NOT DONE YET !!!
		/*ft_dprintf(fd, "[%d %f %f %f %f]",
		  sector.textures[i],
		  sector.align[i].x,
		  sector.align[i].y,
		  sector.map_scale[i].x,
		  sector.map_scale[i].y);*/

		// Use to save with default scale
		ft_dprintf(fd, "[%d %f %f %f %f]",
				sector.textures[i],
				sector.align[i].x,
				sector.align[i].y,
				10.0,
				10.0);
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

static void	write_sector_portals(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.portals[i]);
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
	int	j;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		ft_dprintf(fd, "{");
		j = 0;
		while (j < sector.wall_sprites[i].nb_sprites)
		{
			ft_dprintf(fd, "[%d %f %f %f %f]",
					sector.wall_sprites[i].sprite[j],
					sector.wall_sprites[i].pos[j].x,
					sector.wall_sprites[i].pos[j].y,
					sector.wall_sprites[i].scale[j].x,
					sector.wall_sprites[i].scale[j].y);
			j++;
		}
		ft_dprintf(fd, "}");
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_floor_sprites(int fd, t_sector sector)
{
	int	i;

	ft_dprintf(fd, "(");
	i = 0;
	while (i < sector.floor_sprites.nb_sprites)
	{
		ft_dprintf(fd, "[%d %f %f %f %f]",
				sector.floor_sprites.sprite[i],
				sector.floor_sprites.pos[i].x,
				sector.floor_sprites.pos[i].y,
				sector.floor_sprites.scale[i].x,
				sector.floor_sprites.scale[i].y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_ceiling_sprites(int fd, t_sector sector)
{
	int	i;

	ft_dprintf(fd, "(");
	i = 0;
	while (i < sector.ceiling_sprites.nb_sprites)
	{
		ft_dprintf(fd, "[%d %f %f %f %f]",
				sector.ceiling_sprites.sprite[i],
				sector.ceiling_sprites.pos[i].x,
				sector.ceiling_sprites.pos[i].y,
				sector.ceiling_sprites.scale[i].x,
				sector.ceiling_sprites.scale[i].y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

/*static void	write_interactions_related_data(int fd, t_sector sector)
{
	ft_dprintf(fd, "[%d (%d %d) (%d %d %f)]\n",
			(int)(sector.status),
			(int)(sector.tp.x),
			(int)(sector.tp.y),
			sector.enemy_flag,
			sector.activated,
			sector.start_floor);
}*/

static void	write_sector(int fd, t_sector sector)
{
	ft_dprintf(fd, "[%.5f %.5f %d %.5f %.5f %.5f %.5f] ",
			sector.floor, sector.floor_slope, sector.floor_texture,
			sector.floor_map_align.x, sector.floor_map_align.y,
			sector.floor_map_scale.x, sector.floor_map_scale.y);
	write_sector_floor_sprites(fd, sector);
	ft_dprintf(fd, "[%.5f %.5f %d %.5f %.5f %.5f %.5f] ",
			sector.ceiling, sector.ceiling_slope, sector.ceiling_texture,
			sector.ceiling_map_align.x, sector.ceiling_map_align.y,
			sector.ceiling_map_scale.x, sector.ceiling_map_scale.y);
	write_sector_ceiling_sprites(fd, sector);
	write_sector_vertices(fd, sector);
	write_sector_neighbors(fd, sector);
	write_sector_portals(fd, sector);
	write_sector_textures(fd, sector);
	write_sector_wall_sprites(fd, sector);
	/*ft_dprintf(fd, "[%d %x %d] ", (int)(sector.brightness),
	sector.light_color, (int)sector.intensity);*/
	ft_dprintf(fd, "[%d 0 0]\n", (int)(sector.brightness),
	sector.light_color, (int)sector.intensity);
	//write_interactions_related_data(fd, sector);
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
